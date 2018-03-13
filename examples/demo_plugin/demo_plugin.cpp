//
// Created by limenghua on 18-3-12.
//

#include <iostream>
#include <boost/dll/alias.hpp>
#include <boost/config.hpp>

#include "modulepp/module.h"
#include "modulepp/plugin_config.h"

namespace my_namespace {

    using modulepp::module;

    class demo_module:public module
    {
    public:
        demo_module():
           module("demo_moduel"){
            std::cout<<"demo module construct"<<std::endl;
        }

        ~demo_module(){
            std::cout<<"demo module disstruct"<<std::endl;
        }

        virtual void start()override {
            module::start();
            std::cout<<"demo module start..."<<std::endl;

            register_service<int>("age",std::make_shared<int>(100));
        }

        virtual void stop()override {
            module::stop();
            std::cout<<"demo module start..."<<std::endl;
        }

        std::shared_ptr<demo_module> create(modulepp::plugin::plugin_config & config){
            return std::make_shared<demo_module>();
        }

    };



// Exporting `my_namespace::plugin` variable with alias name `plugin`
// (Has the same effect as `BOOST_DLL_ALIAS(my_namespace::plugin, plugin)`)
    BOOST_DLL_ALIAS(
            demo_module::create,
            create_module
    )


} // namespace my_namespace







