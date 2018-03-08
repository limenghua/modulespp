//
// Created by limenghua on 18-3-8.
//

#ifndef MODULESPP_MOCK_MODULES_H
#define MODULESPP_MOCK_MODULES_H

#include "module.h"

#include "CppUTestExt/MockSupport.h"

using modulepp::module;
using modulepp::priority;

class module_mock:public module
{
public:
    module_mock():
            module::module("module_mock")
    {
        add_dependencies("core");
    }

    virtual void start()override {
        module::start();
        mock().actualCall("module_mock@start");
    }

    virtual void stop()override {
        module::stop();
        mock().actualCall("module_mock@stop");
    }
};



class module_b1:public module
{
public:
    module_b1():
            module("module_b1")
    {
    }


    virtual void start()override {
        module::start();
        mock().actualCall("module_b1@start");
    }

    virtual void stop()override {
        module::stop();
        mock().actualCall("module_b1@stop");
    }
};

class module_b2:public module{
public:
    module_b2():
            module("module_b2")
    {
        add_dependencies("module_b1");
    }

    virtual void start()override {
        module::start();
        mock().actualCall("module_b2@start");
    }

    virtual void stop()override {
        module::stop();
        mock().actualCall("module_b2@stop");
    }
};

class module_b2_1:public module{
public:
    module_b2_1():
            module("module_b2_1")
    {
        add_dependencies("module_b1");
        set_priority(priority::earlest);
    }

    virtual void start()override {
        module::start();
        mock().actualCall("module_b2_1@start");
    }

    virtual void stop()override {
        module::stop();
        mock().actualCall("module_b2_1@stop");
    }
};

class module_a3:public module{
public:
    module_a3():
            module("module_a3")
    {
        add_dependencies("module_b2");
    }

    virtual void start()override {
        module::start();
        mock().actualCall("module_a3@start");
    }

    virtual void stop()override {
        module::stop();
        mock().actualCall("module_a3@stop");
    }
};


#endif //MODULESPP_MOCK_MODULES_H
