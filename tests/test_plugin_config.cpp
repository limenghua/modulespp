//
// Created by limenghua on 18-3-11.
//
#include <modulepp/plugin_config.h>

#include "CppUTest/TestHarness.h"

using namespace modulepp::plugin;

TEST_GROUP(plugin_config)
{

};

TEST(plugin_config,constructor)
{
    plugin_config config;
}

TEST(plugin_config,set_get_module_name){
    plugin_config config;

    config.set_module_name("test");

    std::string ret = config.get_module_name();

    CHECK(ret=="test");
}


TEST(plugin_config,set_get_module_folder){
    plugin_config config;

    config.set_module_folder("c:/test");

    std::string ret = config.get_module_folder();

    CHECK(ret=="c:/test");
}

