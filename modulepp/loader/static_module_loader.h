//
// Created by limenghua on 18-3-10.
//

#ifndef MODULESPP_STATKC_MODULE_LOADER_H
#define MODULESPP_STATKC_MODULE_LOADER_H
#include "modulepp/module.h"
#include <list>

namespace modulepp{

class static_module_loader{
public:
    static_module_loader(module_ptr module){
        register_module(module);
    }

    static void register_module(module_ptr module){
         get_container().push_back(module);
    }

    static std::list<module_ptr> load_all_modules(){
        return std::move(get_container());
    }

    static std::list<module_ptr> & get_container()
    {
        static std::list<module_ptr> modules;
        return modules;
    }
};


#define REGISTER_MODULE(Module,Name) static_module_loader register##Name(Module)

}//namespace modulepp{
#endif //MODULESPP_STATKC_MODULE_LOADER_H
