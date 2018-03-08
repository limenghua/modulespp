//
// Created by limenghua on 18-3-8.
//

#ifndef MODULESPP_APPLICATION_IMPL_H
#define MODULESPP_APPLICATION_IMPL_H

#include "topo_sorting.h"
#include <modulepp/module.h>

namespace modulepp {
    class application_impl
    {
    public:
        void start(){
            auto topo_list = module_sorter::topo_sorting(_modules);

            for(auto m:topo_list){
                inject_all_dependency(m);
                m->start();
            }
        }

        void stop(){
            auto topo_list = module_sorter::topo_sorting(_modules);

            for(auto it=topo_list.rbegin();it!=topo_list.rend();it++){
                (*it)->stop();
                (*it)->clear_inject_modules();
            }
        }

        void register_module(module_ptr module){
            std::string name = module->get_name();
            _modules[name]=module;
        }

        module_ptr get_module(const std::string & name){
            auto it = _modules.find(name);
            if(it==std::end(_modules)){
                throw std::runtime_error("module not found");
            }
            return it->second;
        }

        std::list<std::string> get_module_names(){
            std::list<std::string> ret;

            for(auto & item:_modules){
                ret.push_back(item.first);
            }
            return ret;
        }

        std::list<module_ptr> get_dependencys(module_ptr m){
            std::list<module_ptr> ret;

            auto & depends = m->get_dependencies();

            for(auto & name:depends){
                ret.push_back(get_module(name));
            }

            return ret;
        }

        void inject_all_dependency(module_ptr m) {
            auto denpends = get_dependencys(m);

            for(auto depend:denpends){
                m->inject_module(depend);
            }
        }


        std::map<std::string,module_ptr> _modules;
    };

} //end namespace modulespp {

#endif //MODULESPP_APPLICATION_IMPL_H
