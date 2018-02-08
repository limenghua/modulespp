//
// Created by limenghua on 18-2-8.
//

#include "CppUTest/TestHarness.h"
#include "module.h"

using namespace modulespp;

class module_mock:public module
{
public:
    virtual std::string get_name()override
    {
        return "module_mock";
    }
    virtual std::list<std::string> get_dependencies()override
    {
        return std::list<std::string>();
    }
    virtual void start() override
    {

    }
    virtual void stop() override
    {

    }
};

TEST_GROUP(module)
{
};

TEST(module, create)
{
    module_ptr module = std::make_shared<module_mock>();

    CHECK(module->get_name() == "module_mock");
}

TEST(module, register_service)
{
    module_ptr module = std::make_shared<module_mock>();

    auto service_ptr = std::make_shared<int>(100);

}