//
// Created by limenghua on 18-3-12.
//

#include <iostream>
#include <boost/dll/import.hpp> // for import_alias
#include "modulepp/module.h"
#include "modulepp/plugin_config.h"
#include "modulepp/plugin_loader.h"

using namespace modulepp;

#include <iostream>



namespace dll = boost::dll;
using namespace modulepp;

int main(int argc, char* argv[]) {

    boost::filesystem::path lib_path(argv[1]);          // argv[1] contains path to directory with our plugin library



    std::cout<<"after plugin distruct"<<std::endl;
}