//
// Created by limenghua on 18-3-12.
//

#include <modulepp/plugin_loader.h>

#include "CppUTest/TestHarness.h"

using namespace modulepp::plugin;
using namespace modulepp;

TEST_GROUP(plugin_loader)
{

};

TEST(plugin_loader,load_plugin)
{
    plugin_loader loader;

    std::list<module_ptr> modules = loader.load_plugin("/home/limenghua/plugin");

    CHECK(modules.empty());
}

