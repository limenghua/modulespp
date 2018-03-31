//
// Created by limenghua on 18-3-12.
//

#include <iostream>
#include <boost/dll/import.hpp> // for import_alias
#include "modulepp/module.h"
#include "modulepp/plugin/plugin_config.h"
#include "modulepp/loader/plugin_loader.h"
#include "modulepp/application.h"

using namespace modulepp;

#include <iostream>



namespace dll = boost::dll;
using namespace modulepp;
using modulepp::loader::plugin_loader;

int main(int argc, char* argv[]) {

    modulepp::loader::plugin_loader loader;
    auto modules = plugin_loader::load_plugins(argv[1]);

    modulepp::application app;



    for(auto & module:modules){
        app.register_module(module);
    }

    app.start();

    std::cout<<"after plugin distruct"<<std::endl;

    app.stop();
}