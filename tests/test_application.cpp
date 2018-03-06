//
// Created by limenghua on 18-3-5.
//

#include "application.h"
#include "module.h"

#include "CppUTest/TestHarness.h"
#include <memory>

using module::application;
using module::module;

auto test_moudle = std::make_shared<module::module>("test_module");

TEST_GROUP(Application)
{

};

TEST(Application,CanRegisterModule)
{
    application app;

    app.register_module(test_moudle);

    auto names=app.get_module_names();

    CHECK(std::find(std::begin(names),std::end(names),test_moudle->get_name()) != std::end(names));

    auto ret_module = app.get_module(test_moudle->get_name());

}