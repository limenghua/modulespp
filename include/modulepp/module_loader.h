//
// Created by limenghua on 18-3-7.
//

#ifndef MODULESPP_MODULE_LOADER_H
#define MODULESPP_MODULE_LOADER_H

#include <list>
#include "module.h"

namespace modulepp{
    class module_loader{
    public:
        std::list<module_ptr> get_all_modules()=0;
    };

}


#endif //MODULESPP_MODULE_LOADER_H
