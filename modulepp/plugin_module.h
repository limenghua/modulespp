//
// Created by limenghua on 18-3-13.
//

#ifndef MODULESPP_MODULE_CREATOR_H
#define MODULESPP_MODULE_CREATOR_H

#include "module.h"
#include "plugin_config.h"

#include <memory>

namespace modulepp{
namespace plugin{
    class plugin_module:public modulepp::module{
    public:
        plugin_module(const std::string & name):module::module(name){}

        virtual void set_config(plugin_config & config)=0;
    };


}}//namespace modulepp::plugin

#endif //MODULESPP_MODULE_CREATOR_H
