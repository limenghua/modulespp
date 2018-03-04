//
// Created by limenghua on 18-2-8.
//

#ifndef MODULESPP_MODULE_H
#define MODULESPP_MODULE_H

#include <memory>
#include <string>
#include <list>
namespace modulespp {

    class module
    {
    public:
        virtual std::string get_name() = 0;
        virtual std::list<std::string> get_dependencies() = 0;

        virtual void start() = 0;
        virtual void stop() = 0;

        template <typename Service>
            void register_service(const std::string &name,std::shared_ptr<Service> service)
        {

        }

        template <typename Service>
        std::shared_ptr<Service> get_service(const std::string &name)
        {

        }

        template <typename Service>
        void register_service(std::shared_ptr<Service> service)
        {

        }

        template <typename Service>
        std::shared_ptr<Service> get_service()
        {

        }
    };

    typedef std::shared_ptr<module> module_ptr;

}

#endif //MODULESPP_MODULE_H
