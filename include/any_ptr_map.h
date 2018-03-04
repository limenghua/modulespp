#pragma once
#include <boost/any.hpp>
#include <memory>
#include <map>
#include <mutex>

namespace util {

	class any_ptr_map {
	public:
		template<typename ServiceType>
		void set(const std::string &key, std::shared_ptr<ServiceType> ptr) {
            _container[key] = ptr;
		}
		template<typename ServiceType>
		void set(std::shared_ptr<ServiceType> ptr) {
			std::string key = typeid(ServiceType).name();
			set<ServiceType>(key, ptr);
		}

		template<typename ServiceType>
		std::shared_ptr<ServiceType> get(const std::string &key) {
			auto it = _container.find(key);
            if(it == _container.end()){
                throw std::logic_error("key not found");
            }

            return boost::any_cast<std::shared_ptr<ServiceType>>(it->second);
		}
		template<typename ServiceType>
		std::shared_ptr<ServiceType> get() {
			std::string key = typeid(ServiceType).name();
			return get<ServiceType>(key);
		}
		void remove(const std::string &key) {
            _container.erase(key);
		}
		template<typename ServiceType>
		void remove() {
			std::string key = typeid(ServiceType).name();
			return remove(key);
		}

		void remove_all() {
            _container.clear();
		}

	private:
		std::map<std::string, boost::any> _container;
	};

    class safe_any_ptr_map{
    public:
        template<typename ServiceType>
        void set(const std::string &key, std::shared_ptr<ServiceType> ptr) {
            std::lock_guard<std::mutex> lock(_mutex);
            return _map.set<ServiceType>(key,ptr);
        }
        template<typename ServiceType>
        void set(std::shared_ptr<ServiceType> ptr) {
            std::lock_guard<std::mutex> lock(_mutex);
            return _map.set<ServiceType>(ptr);
        }

        template<typename ServiceType>
        std::shared_ptr<ServiceType> get(const std::string &key) {
            std::lock_guard<std::mutex> lock(_mutex);
            return _map.get<ServiceType>(key);
        }
        template<typename ServiceType>
        std::shared_ptr<ServiceType> get() {
            std::lock_guard<std::mutex> lock(_mutex);
            return _map.get<ServiceType>();
        }
        void remove(const std::string &key) {
            std::lock_guard<std::mutex> lock(_mutex);
            return _map.remove(key);
        }
        template<typename ServiceType>
        void remove() {
            std::lock_guard<std::mutex> lock(_mutex);
            return _map.remove<ServiceType>();
        }

        void remove_all() {
            std::lock_guard<std::mutex> lock(_mutex);
            return _map.remove_all();
        }

    private:
        any_ptr_map _map;
        std::mutex _mutex;
    };

}//end namespace enginex {
