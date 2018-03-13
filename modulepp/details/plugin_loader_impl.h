//
// Created by limenghua on 18-3-12.
//

#ifndef MODULESPP_PLUGIN_LOADER_IMPL_H
#define MODULESPP_PLUGIN_LOADER_IMPL_H
#include "../module.h"
#include <list>
#include <string>

namespace modulepp{
    namespace plugin{

        class plugin_loader_impl{
        public:
            std::list<module_ptr> load_plugins(const std::string & plugin_folder){
                return std::list<module_ptr>();
            }

        };



    }}


#endif //MODULESPP_PLUGIN_LOADER_IMPL_H
