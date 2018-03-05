//
// Created by limenghua on 18-2-8.
//
#include "module.h"

#include "CppUTest/TestHarness.h"

class service_interface
{
};

class service_imp:public service_interface
{
};

TEST_GROUP(Module)
{
};

TEST(Module, constructor)
{
    module::module module("test_module");

    CHECK(module.get_name() == "test_module");

    CHECK(module.get_dependencies().empty());

    CHECK(module.get_status() == module::mudule_status::unload);

}

TEST(Module, register_service)
{
    module::module module("test_module");

    std::shared_ptr<service_interface> service_ptr = std::make_shared<service_imp>();

    module.register_service<service_interface>("service_name",service_ptr);

    auto ret_ptr = module.get_service<service_interface>("service_name");

    CHECK(ret_ptr==service_ptr);
}
