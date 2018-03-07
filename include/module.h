//
// Created by limenghua on 18-2-8.
//

#ifndef MODULESPP_MODULE_H
#define MODULESPP_MODULE_H

#include <memory>
#include <string>
#include <set>

#include "any_ptr_map.h"

namespace module {

    enum class module_status{
        active,
        inactive
    };
    class priority{
    public:
        static const int earlest = 100;
        static const int earlier=10;
        static const int normal=0;
        static const int later=-10;
        static const int latest=-100;
    };

    class module;
    typedef std::shared_ptr<module> module_ptr;

    class module
    {
    public:
        module(const std::string &name) :
            _name(name),
            _status(module_status::inactive)
        {

        }
        std::string get_name()const{
            return _name;
        }
        const std::set<std::string> & get_dependencies(){
            return _dependence_names;
        };

        virtual void start() {
            if(_status != module_status::inactive){
                throw std::runtime_error("cannot do start once module already started");
            }
            _status = module_status::active;
        };
        virtual void stop() {
            if(_status != module_status::active){
                throw std::runtime_error("cannot do stop when module not stated");
            }
            _status = module_status::inactive;
        };

        void inject_module(module_ptr m){
            std::string name = m->get_name();

            if(_dependence_names.find(name) == _dependence_names.end()){
                throw std::runtime_error("inject module is not denpendence");
            }

            _denpend_modules[name]=m;
        }

        module_ptr get_module(const std::string & name){
            auto it = _denpend_modules.find(name);
            if(it == _denpend_modules.end()){
                throw std::runtime_error("module name not found");
            }
            return it->second;
        }

        module_status get_status()const{
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
            _dependence_names.insert(denpendence);
        }

    protected:
        std::string _name;
        std::set<std::string> _dependence_names;
        module_status _status;
        int _priority;

        std::map<std::string,module_ptr> _denpend_modules;
        util::safe_any_ptr_map _services;
    };



}

#endif //MODULESPP_MODULE_H
