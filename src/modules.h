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
    };

}

#endif //MODULESPP_MODULE_H
