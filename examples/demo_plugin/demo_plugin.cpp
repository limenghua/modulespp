//
// Created by limenghua on 18-3-12.
//

#include <modulepp/module.h>
#include <iostream>
#include <boost/dll.hpp>

using namespace modulepp;

class hello_module:public module{
    hello_module():
            module("hello_module"){}

    virtual void start()override {
        module::start();
        std::cout<<"hello_module start"<<std::endl;
    }

    virtual void stop()override {
        module::stop();
        std::cout<<"hello_module stop"<<std::endl;
    }
};



