//
// Created by limenghua on 18-3-10.
//
#include <modulepp/application.h>
#include <iostream>
#include <memory>
#include <ctime>

using namespace modulepp;

class time_service{
public:
    virtual std::time_t get_start_time() =0;
};

class time_service_imp:public time_service{
public:
    time_service_imp(){
        std::time( & _start_time);
    }

    virtual std::time_t get_start_time() override {
        return _start_time;
    }

    time_t _start_time;
};

std::shared_ptr<time_service> create_test_service(){
    return std::make_shared<time_service_imp>();
}

class time_module:public module{
public:
    time_module():module("time_module"){}

    virtual void start()override{
        module::start();
        auto srv = create_test_service();
        register_service<time_service>("time",srv);
    }
};

class client_module:public module{
public:
    client_module():module("client_module"){
        add_dependencies("time_module");
    }
};


int main(){
    application app;
    app.register_module(std::make_shared<time_module>());
    app.register_module(std::make_shared<client_module>());

    app.start();

    auto start_time =
            app.get_module("client_module")
            ->get_service<time_service>("time_module.time")
            ->get_start_time();

    std::cout<<"time_module.time:"
             <<start_time<<std::endl;

    app.stop();
}

