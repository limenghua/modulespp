//
// Created by limenghua on 18-2-8.
//

#ifndef MODULESPP_MODULE_H
#define MODULESPP_MODULE_H

#include <memory>
#include <string>
#include <list>

#include "any_ptr_map.h"

namespace module {

    enum class mudule_status{
        unload,
        loaded,
        starting,
        started,
        stopping,
        stoped
    };

    class module
    {
    public:
        module(const std::string &name) :
            _name(name),
            _status(mudule_status::unload)
        {

        }
        std::string get_name()const{
            return _name;
        }
        const std::list<std::string> & get_dependencies(){
            return _dependencies;
        };

        virtual void start() {};
        virtual void stop() {};

        mudule_status get_status()const{
            return _status;
        };

        template <typename Service>
            void register_service(const std::string &name,std::shared_ptr<Service> service)
        {
            return _services.set<Service>(name,service);
        }

        template <typename Service>
        std::shared_ptr<Service> get_service(const std::string &name)
        {
            return _services.get<Service>(name);

        }

        template <typename Service>
        void register_service(std::shared_ptr<Service> service)
        {
            return _services.set<Service>(service);
        }

        template <typename Service>
        std::shared_ptr<Service> get_service()
        {
            return _services.get<Service>();
        }

    protected:
        void add_dependencies(const std::string & denpendence){
            _dependencies.push_back(denpendence);
        }

    private:
        std::string _name;
        std::list<std::string> _dependencies;
        mudule_status _status;

        util::safe_any_ptr_map _services;
    };

    typedef std::shared_ptr<module> module_ptr;

}

#endif //MODULESPP_MODULE_H
