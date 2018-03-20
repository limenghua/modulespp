//
// Created by limenghua on 18-3-12.
//

#ifndef MODULESPP_PLUGIN_LOADER_H
#define MODULESPP_PLUGIN_LOADER_H
#include "modulepp/module.h"
#include "details/plugin_loader_impl.h"
#include <list>
#include <string>
#include <memory>

namespace modulepp{
namespace loader{

    class plugin_loader{
    public:
        std::list<module_ptr> load_plugins(const std::string & plugin_folder){
            plugin_loader_impl loader(plugin_folder);
            return loader.load_plugins();
        }

    };



}}


#endif //MODULESPP_PLUGIN_LOADER_H
