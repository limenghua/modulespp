//
// Created by limenghua on 18-2-8.
//
#include "module.h"

#include "CppUTest/TestHarness.h"

using module::module_status;

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

    CHECK(module.get_status() == module_status::inactive);

}

TEST(Module, register_service)
{
    module::module module("test_module");

    std::shared_ptr<service_interface> service_ptr = std::make_shared<service_imp>();

    module.register_service<service_interface>("service_name",service_ptr);

    auto ret_ptr = module.get_service<service_interface>("service_name");

    CHECK(ret_ptr==service_ptr);
}

TEST(Module, start)
{
    module::module module("test_module");

    CHECK(module.get_status() == module_status::inactive);

    module.start();

    CHECK(module.get_status() == module_status::active)

    module.stop();

    CHECK(module.get_status() == module_status::inactive);
}

TEST(Module, StartInCorrectShoudThrow)
{
    module::module module("test_module");

    CHECK(module.get_status() == module_status::inactive);

    module.start();

    CHECK(module.get_status() == module_status::active)

    CHECK_THROWS(std::runtime_error,module.start());
}

TEST(Module, StopInCorrectShoudThrow)
{
    module::module module("test_module");

    CHECK(module.get_status() == module_status::inactive);
    CHECK_THROWS(std::runtime_error,module.stop());

    module.start();

    CHECK(module.get_status() == module_status::active)

    module.stop();
    CHECK_THROWS(std::runtime_error,module.stop());
}

class module_mock:public module::module
{
public:
    module_mock():
        module::module("module_mock")
    {
        add_dependencies("core");
    }
};

TEST(Module,GetDependency)
{
    module::module_ptr module_ptr = std::make_shared<module_mock>();
    auto & dependencys = module_ptr->get_dependencies();
    CHECK(dependencys.find("core") != dependencys.end());
}

