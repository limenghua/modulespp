//
// Created by limenghua on 18-3-12.
//

#include <iostream>
#include <boost/config.hpp>

#include "modulepp/module.h"
#include "modulepp/plugin/plugin_config.h"
#include "modulepp/plugin/plugin_module.h"
#include "core/service.h"

namespace core {

    using namespace modulepp;
    using modulepp::plugin::plugin_module;
    using modulepp::plugin::plugin_config;

    class core_service:public service{
    public:
		virtual int version() { return 1; };
        virtual std::string name(){return "core";}
        virtual std::string describe(){return "this is the core service";}
	};

    class core_module:public plugin_module
    {
    public:
        core_module():
                plugin_module("core"){
            register_service<service>("service",std::make_shared<core_service>());
            std::cout<<"demo module core construct"<<std::endl;
        }

        ~core_module(){
            std::cout<<"demo module core destroyed"<<std::endl;
        }

        virtual void start()override {
            module::start();
            std::cout<<"demo module core start..."<<std::endl;

            
        }
        
        virtual void stop()override {
            module::stop();
            std::cout<<"demo module core stop..."<<std::endl;
        }
    };



// Exporting `my_namespace::plugin` variable with alias name `plugin`
// (Has the same effect as `BOOST_DLL_ALIAS(my_namespace::plugin, plugin)`)
    extern "C" BOOST_SYMBOL_EXPORT core_module plugin_module;
    core_module plugin_module;


} // namespace my_namespace







