//
// Created by limenghua on 18-3-12.
//

#ifndef MODULESPP_PLUGIN_LOADER_H
#define MODULESPP_PLUGIN_LOADER_H
#include "module.h"
#include "details/plugin_loader_impl.h"
#include <list>
#include <string>
#include <memory>

namespace modulepp{
namespace plugin{

    class plugin_loader{
    public:
        std::list<module_ptr> load_plugins(const std::string & root_folder){
            return _impl->load_plugins(root_folder);
        }

    private:
        std::unique_ptr<plugin_loader_impl> _impl = std::make_unique<plugin_loader_impl>();
    };



}}


#endif //MODULESPP_PLUGIN_LOADER_H
