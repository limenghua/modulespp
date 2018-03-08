//
// Created by limenghua on 18-3-5.
//

#include "application.h"
#include "mock_modules.h"


#include "CppUTest/TestHarness.h"


using namespace modulepp;



TEST_GROUP(Application)
{
    void teardown()
    {
        mock().clear();
    }

    module_ptr m1=std::make_shared<module_b1>();
    module_ptr m2=std::make_shared<module_b2>();
    module_ptr m2_1=std::make_shared<module_b2_1>();
    module_ptr m3=std::make_shared<module_a3>();

};

TEST(Application,CanRegisterModule)
{
    application app;
    auto test_moudle = std::make_shared<module>("test_module");

    app.register_module(test_moudle);

    auto names=app.get_module_names();

    CHECK(std::find(std::begin(names),std::end(names),test_moudle->get_name()) != std::end(names));

    auto ret_module = app.get_module(test_moudle->get_name());

}

TEST(Application,StartShoudCallStartOfAllModules)
{
    application app;

    app.register_module(m1);
    app.register_module(m2);
    app.register_module(m2_1);
    app.register_module(m3);

    mock().expectOneCall("module_b1@start");
    mock().expectOneCall("module_b2@start");
    mock().expectOneCall("module_b2_1@start");
    mock().expectOneCall("module_a3@start");

    app.start();

    mock().checkExpectations();
}

TEST(Application,StopShoudCallStopOfAllModules)
{
    application app;

    app.register_module(m1);
    app.register_module(m2);
    app.register_module(m2_1);
    app.register_module(m3);

    mock().expectOneCall("module_b1@start");
    mock().expectOneCall("module_b2@start");
    mock().expectOneCall("module_b2_1@start");
    mock().expectOneCall("module_a3@start");

    mock().expectOneCall("module_b1@stop");
    mock().expectOneCall("module_b2@stop");
    mock().expectOneCall("module_b2_1@stop");
    mock().expectOneCall("module_a3@stop");

    app.start();

    app.stop();

    mock().checkExpectations();
}