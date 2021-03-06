//
// Created by limenghua on 18-3-20.
//

#ifndef MODULESPP_MODULEPP_H
#define MODULESPP_MODULEPP_H

#include <modulepp/module.h>
#include <modulepp/application.h>
#include <modulepp/plugin/plugin_config.h>
#include <modulepp/plugin/plugin_module.h>
#include <modulepp/loader/plugin_loader.h>
#include <modulepp/loader/static_module_loader.h>

namespace modulepp{
    using plugin_module = plugin::plugin_module;
    using plugin_loader = loader::plugin_loader;
}


#endif //MODULESPP_MODULEPP_H
