//
// Created by limenghua on 18-3-10.
//

#ifndef MODULESPP_STATKC_MODULE_LOADER_H
#define MODULESPP_STATKC_MODULE_LOADER_H
#include "module.h"
#include <list>

namespace modulepp{

class static_module_loader{
public:
    static_module_loader(module_ptr module){
        _modules.push_back(module);
    }

    static std::list<module_ptr> load_all_modules(){
        return std::move(_modules);
    }

private:
    static std::list<module_ptr> _modules;
};


#define REGISTER_MODULE(Module,Name) static_module_loader register##Name(Module)

}//namespace modulepp{
#endif //MODULESPP_STATKC_MODULE_LOADER_H
