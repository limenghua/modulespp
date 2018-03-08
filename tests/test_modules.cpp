//
// Created by limenghua on 18-2-8.
//
#include "modulepp/module.h"

#include "mock_modules.h"

#include "CppUTest/TestHarness.h"

using namespace modulepp;

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
    module module("test_module");

    CHECK(module.get_name() == "test_module");

    CHECK(module.get_dependencies().empty());

    CHECK(module.get_status() == module_status::inactive);

}

TEST(Module, register_service)
{
    module module("test_module");

    std::shared_ptr<service_interface> service_ptr = std::make_shared<service_imp>();

    module.register_service<service_interface>("service_name",service_ptr);

    auto ret_ptr = module.get_service<service_interface>("service_name");

    CHECK(ret_ptr==service_ptr);
}

TEST(Module, start)
{
    module module("test_module");

    CHECK(module.get_status() == module_status::inactive);

    module.start();

    CHECK(module.get_status() == module_status::active)

    module.stop();

    CHECK(module.get_status() == module_status::inactive);
}

TEST(Module, StartInCorrectShoudThrow)
{
    module module("test_module");

    CHECK(module.get_status() == module_status::inactive);

    module.start();

    CHECK(module.get_status() == module_status::active)

    CHECK_THROWS(std::runtime_error,module.start());
}

TEST(Module, StopInCorrectShoudThrow)
{
    module module("test_module");

    CHECK(module.get_status() == module_status::inactive);
    CHECK_THROWS(std::runtime_error,module.stop());

    module.start();

    CHECK(module.get_status() == module_status::active)

    module.stop();
    CHECK_THROWS(std::runtime_error,module.stop());
}


TEST(Module,GetDependency)
{
    module_ptr module_ptr = std::make_shared<module_mock>();
    auto & dependencys = module_ptr->get_dependencies();
    CHECK(dependencys.find("core") != dependencys.end());
}

TEST(Module,InjectDenpendency)
{
    module_ptr m = std::make_shared<module>("core");

    module_ptr m2 = std::make_shared<module_mock>();

    m2->inject_module(m);

    auto module_ret = m2->get_module("core");

    CHECK(module_ret == m);
}

TEST(Module,InjectNotDenpendencyShouldThrow)
{
    module_ptr m = std::make_shared<module>("core2");
    module_ptr m2 = std::make_shared<module_mock>();
    CHECK_THROWS(std::runtime_error,m2->inject_module(m));
}

