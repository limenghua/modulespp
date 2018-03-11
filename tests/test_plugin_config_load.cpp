//
// Created by limenghua on 18-3-11.
//
#include <modulepp/plugin_config.h>

#include "CppUTest/TestHarness.h"

#include <fstream>
#include <boost/filesystem.hpp>

using namespace modulepp::plugin;

TEST_GROUP(plugin_config_load)
{
    const std::string filename="test_feature.json";

    const std::string property_doc = R"(
        {
            "name":"test_name",
            "priority":100
        }
    )";

    void setup(){
        MemoryLeakWarningPlugin::turnOffNewDeleteOverloads();
        std::ofstream fout(filename.c_str());
        fout<<property_doc<<std::endl;
    }

    void teardown(){
        MemoryLeakWarningPlugin::turnOnNewDeleteOverloads();
        boost::filesystem::remove(filename);
    }
};

TEST(plugin_config_load,load_module_property){
    plugin_config config;

    config.load_propertys(filename);

    auto & property = config.get_module_propertys();

    CHECK(property.get<std::string>("name")=="test_name");
    CHECK_EQUAL(property.get<int>("priority"),100);
}