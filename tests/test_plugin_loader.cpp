//
// Created by limenghua on 18-3-12.
//

#include <modulepp/loader/plugin_loader.h>
#include <modulepp/loader/details/plugin_loader_impl.h>

#include "CppUTest/TestHarness.h"

using namespace modulepp::plugin;
using namespace modulepp::loader;
using namespace modulepp;

TEST_GROUP(plugin_loader)
{
    void setup(){
        MemoryLeakWarningPlugin::turnOffNewDeleteOverloads();
    }

    void teardown(){
        MemoryLeakWarningPlugin::turnOnNewDeleteOverloads();
    }

    const std::string ROOT="/home/limenghua/github/";
    plugin_loader_impl loader = plugin_loader_impl(ROOT);

};

TEST(plugin_loader,load_plugin)
{
    plugin_loader loader;

    //std::list<module_ptr> modules = loader.load_plugins("/home/limenghua/github/limenghua/modulespp/build/examples/demo_plugin/");

    //CHECK(! modules.empty());
}

TEST(plugin_loader,root_path)
{
    CHECK(loader.get_root_folder() == ROOT);
}

TEST(plugin_loader,get_config_file)
{
    std::string config_file=ROOT+"plugin.json";
    CHECK(loader.get_config_file() == config_file);
}

