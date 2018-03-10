//
// Created by limenghua on 18-3-10.
//

#include <iostream>
#include <modulepp/application.h>
#include <modulepp/module.h>

using namespace modulepp;

class hello_module:public module{
public:
    hello_module():
        module("hello_module"){
        std::cout<<"hello_module contructed"<<std::endl;
    }

    ~hello_module(){
        std::cout<<"hello_module disctructed"<<std::endl;
    }

    virtual void start()override {
        module::start();
        std::cout<<"hello_module::start"<<std::endl;
    }

    virtual void stop()override {
        module::stop();
        std::cout<<"hello_module::stop"<<std::endl;
    }
};



int main()
{
    std::cout<<"start run..."<<std::endl;

    {
        application app;
        app.register_module(std::make_shared<hello_module>());

        app.start();
        //do some working...
        app.stop();
    }

    std::cout<<"exit running"<<std::endl;

    return 0;
}

