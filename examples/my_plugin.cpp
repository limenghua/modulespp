//
// Created by limenghua on 18-3-12.
//

#include <iostream>
#include <boost/config.hpp>

#include "modulepp/module.h"
#include "modulepp/plugin/plugin_config.h"
#include "modulepp/plugin/plugin_module.h"

namespace my_namespace {

    using namespace modulepp;
    using modulepp::plugin::plugin_module;
    using modulepp::plugin::plugin_config;

    class cal_service{
    public:
        virtual int calculate(int a,int b) =0;
    };

    class service_add:public cal_service{
    public:
        virtual int calculate(int a,int b)override {
            return a+b;
        }
    };

    class my_plugin:public plugin_module
    {
    public:
        my_plugin():
                plugin_module("my_plugin"){
            std::cout<<"my_plugin construct"<<std::endl;
        }

        ~my_plugin(){
            std::cout<<"my_plugin distruct"<<std::endl;
        }

        virtual void start()override {
            module::start();
            std::cout<<"my_plugin start..."<<std::endl;

            register_service<int>("age",std::make_shared<int>(100));
            register_service<cal_service>("add",std::make_shared<service_add>());
        }

        virtual void stop()override {
            module::stop();
            std::cout<<"my_plugin stoping..."<<std::endl;
        }


    };



    // Exporting `my_namespace::my_plugin`
    extern "C" BOOST_SYMBOL_EXPORT my_plugin plugin_module;
    my_plugin plugin_module;

} // namespace my_namespace

