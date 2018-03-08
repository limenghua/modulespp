//
// Created by limenghua on 18-2-8.
//

#ifndef MODULESPP_APPLICATION_H
#define MODULESPP_APPLICATION_H

#include "module.h"

#include <memory>
#include <string>
#include <list>
#include <map>

namespace modulepp {
    class application
    {
    public:
        void start();
        void stop();

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

    private:
        std::list<module_ptr> get_dependencys(module_ptr m);
        void inject_all_dependency(module_ptr m);

    private:
        std::map<std::string,module_ptr> _modules;
    };

} //end namespace modulespp {

#endif //MODULESPP_APPLICATION_H
