//
// Created by limenghua on 18-3-12.
//

#include <modulepp/plugin_loader.h>

#include "CppUTest/TestHarness.h"

using namespace modulepp::plugin;
using namespace modulepp;

TEST_GROUP(plugin_loader)
{
    void setup(){
        MemoryLeakWarningPlugin::turnOffNewDeleteOverloads();
    }

    void teardown(){
        MemoryLeakWarningPlugin::turnOnNewDeleteOverloads();
    }

};

TEST(plugin_loader,load_plugin)
{
    plugin_loader loader;

    std::list<module_ptr> modules = loader.load_plugins("/home/limenghua/github/limenghua/modulespp/build/examples/demo_plugin/");

    CHECK(! modules.empty());
}

