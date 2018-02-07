//
// Created by limenghua on 18-2-8.
//

#ifndef MODULESPP_APPLICATION_H
#define MODULESPP_APPLICATION_H

#include <memory>
#include <string>
#include <list>
#include <map>
namespace modulespp {
    class module;
    typedef std::shared_ptr<module> module_ptr;
    class application
    {
    public:
        void start();
        void stop();

        void register_module(module_ptr module);

        module_ptr get_module(std::string & name);

        std::list<std::string> get_module_names();

    private:
        std::map<std::string,module_ptr> _modules;
    };

} //end namespace modulespp {

#endif //MODULESPP_APPLICATION_H
