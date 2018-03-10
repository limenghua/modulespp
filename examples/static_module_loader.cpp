//
// Created by limenghua on 18-3-10.
//

#include <iostream>
#include <modulepp/application.h>
#include <modulepp/module.h>
#include <modulepp/static_module_loader.h>

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


REGISTER_MODULE(std::make_shared<hello_module>(),hello);


class test_module:public module{
public:
    test_module(const std::string & name):
            module(name){
        std::cout<<"test_module contructed,name:"<<name<<std::endl;
    }

    ~test_module(){
        std::cout<<"test_module disctructed"<<std::endl;
    }

    virtual void start()override {
        module::start();
        std::cout<<"test_module::start"<<std::endl;
    }

    virtual void stop()override {
        module::stop();
        std::cout<<"test_module::stop"<<std::endl;
    }
};
REGISTER_MODULE(std::make_shared<test_module>("test_module"),test);



int main()
{
    std::cout<<"start run..."<<std::endl;


    {
        application app;

        auto modules = static_module_loader::load_all_modules();
        for(auto &module:modules){
            app.register_module(module);
        }

        app.start();
        //do some working...
        app.stop();
    }

    std::cout<<"exit running"<<std::endl;

    return 0;
}

