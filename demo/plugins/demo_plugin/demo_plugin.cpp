//
// Created by limenghua on 18-3-12.
//

#include <iostream>
#include <boost/config.hpp>

#include "modulepp/module.h"
#include "modulepp/plugin/plugin_config.h"
#include "modulepp/plugin/plugin_module.h"
#include "core/service.h"

namespace my_namespace {

    using namespace modulepp;
    using modulepp::plugin::plugin_module;
    using modulepp::plugin::plugin_config;

    class demo_module:public plugin_module
    {
    public:
        demo_module():
                plugin_module("demo_module"){
            add_dependencies("core");
            std::cout<<"demo module construct"<<std::endl;

        }

        ~demo_module(){
            std::cout<<"demo module disstruct"<<std::endl;
        }

        virtual void start()override {
			auto service = get_service<core::service>("core.service");

			std::string dec = service->describe();

            module::start();
            std::cout<<"demo module start..."<<std::endl;
			std::cout << "get describe from core is:"<< dec << std::endl;

            register_service<int>("age",std::make_shared<int>(100));
        }

        virtual void stop()override {
            module::stop();
            std::cout<<"demo module stop..."<<std::endl;
        }


    };



// Exporting `my_namespace::plugin` variable with alias name `plugin`
// (Has the same effect as `BOOST_DLL_ALIAS(my_namespace::plugin, plugin)`)
    extern "C" BOOST_SYMBOL_EXPORT demo_module plugin_module;
    demo_module plugin_module;


} // namespace my_namespace







