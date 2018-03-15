//
// Created by limenghua on 18-3-12.
//

#include <iostream>
#include <boost/dll/import.hpp> // for import_alias
#include "modulepp/module.h"
#include "modulepp/plugin_config.h"
#include "modulepp/plugin_module.h"

using namespace modulepp;
using modulepp::plugin::plugin_config;
using modulepp::plugin::plugin_module;

#include <iostream>

template<class T> std::shared_ptr<T> to_std(boost::shared_ptr<T> &p) {
    return std::shared_ptr<T>(p.get(), [p](T* t) mutable { p.reset(); });
}

template<class T> boost::shared_ptr<T> to_boost(std::shared_ptr<T> &p) {
    return boost::shared_ptr<T>(p.get(), [p](T* t) mutable { p.reset(); });
}


namespace dll = boost::dll;
using namespace modulepp;

int main(int argc, char* argv[]) {

    boost::filesystem::path lib_path(argv[1]);          // argv[1] contains path to directory with our plugin library

    std::cout << "Loading the plugin" << std::endl;

    boost::shared_ptr<plugin_module> plugin =
            dll::import<plugin_module>(          // type of imported symbol is located between `<` and `>`
            lib_path / "demo_plugin",                     // path to the library and library name
            "plugin_module",                                       // name of the symbol to import
            dll::load_mode::append_decorations              // makes `libmy_plugin_sum.so` or `my_plugin_sum.dll` from `my_plugin_sum`
    );

    std::shared_ptr<plugin_module> plugin1 = to_std(plugin);

    plugin =
            dll::import<plugin_module>(          // type of imported symbol is located between `<` and `>`
                    lib_path / "demo_plugin2",                     // path to the library and library name
                    "plugin_module",                                       // name of the symbol to import
                    dll::load_mode::append_decorations              // makes `libmy_plugin_sum.so` or `my_plugin_sum.dll` from `my_plugin_sum`
            );

    std::shared_ptr<plugin_module> plugin2 = to_std(plugin);

    plugin::plugin_config config;
    plugin1->set_config(config);
    plugin2->set_config(config);

    std::cout << "plugin1->start() call:  " << std::endl;
    plugin1->start();
    plugin2->start();

    std::cout<<"plugin->stop() call"<<std::endl;
    auto age = plugin1->get_service<int>("age");
    std::cout<<"get service age="<<*age<<std::endl;

    plugin1->stop();
    plugin2->stop();


    std::cout<<"after plugin distruct"<<std::endl;
}