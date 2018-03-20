//
// Created by limenghua on 18-2-8.
//

#ifndef MODULESPP_APPLICATION_H
#define MODULESPP_APPLICATION_H

#include <modulepp/module.h>
#include <modulepp/details/application_impl.h>

#include <string>
#include <list>
#include <memory>

namespace modulepp {
    class application
    {
    public:
        void start(){
            return _impl->start();
        }

        void stop(){
            return _impl->stop();
        }

        void register_module(module_ptr module){
            return _impl->register_module(module);
        }

        module_ptr get_module(const std::string & name){
            return _impl->get_module(name);
        }

        std::list<std::string> get_module_names(){
            return _impl->get_module_names();
        }

    private:
        std::unique_ptr<application_impl> _impl = std::make_unique<application_impl>();
    };

} //end namespace modulespp {

#endif //MODULESPP_APPLICATION_H
