//
// Created by limenghua on 18-3-12.
//

#ifndef MODULESPP_PLUGIN_LOADER_H
#define MODULESPP_PLUGIN_LOADER_H
#include "modulepp/module.h"
#include <list>
#include <string>
#include <memory>

namespace modulepp{
namespace loader{

    class plugin_loader{
    public:
        static inline std::list<module_ptr> load_plugins(const std::string & plugin_folder);

    };

}}

#include <modulepp/loader/details/plugin_loader_impl.ipp>

#endif //MODULESPP_PLUGIN_LOADER_H
