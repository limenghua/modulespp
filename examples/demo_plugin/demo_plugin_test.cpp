//
// Created by limenghua on 18-3-12.
//

#include <iostream>
#include <boost/dll/import.hpp> // for import_alias
#include "modulepp/module.h"
#include "modulepp/plugin_config.h"
#include <functional>

#include <iostream>


namespace dll = boost::dll;
using namespace modulepp;

int main(int argc, char* argv[]) {

    boost::filesystem::path lib_path(argv[1]);          // argv[1] contains path to directory with our plugin library
    module_ptr plugin;            // variable to hold a pointer to plugin variable
    typedef module_ptr (module_create_t)(plugin::plugin_config &config);
    std::function<module_create_t > creator;

    std::cout << "Loading the plugin" << std::endl;

    creator = dll::import<module>(          // type of imported symbol is located between `<` and `>`
            lib_path / "demo_plugin",                     // path to the library and library name
            "plugin",                                       // name of the symbol to import
            dll::load_mode::append_decorations              // makes `libmy_plugin_sum.so` or `my_plugin_sum.dll` from `my_plugin_sum`
    );

    std::cout << "plugin->start() call:  " << std::endl;

    plugin->start();

    std::cout<<"plugin->stop() call"<<std::endl;

    auto age = plugin->get_service<int>("age");
    std::cout<<"get service age="<<*age<<std::endl;

    age.reset();

    plugin->stop();

    plugin.reset();

    std::cout<<"after plugin distruct"<<std::endl;
}