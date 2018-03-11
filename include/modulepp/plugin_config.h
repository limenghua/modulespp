//
// Created by limenghua on 18-3-11.
//

#ifndef MODULESPP_PLUGIN_CONFIG_H
#define MODULESPP_PLUGIN_CONFIG_H
#include <string>

namespace modulepp{
namespace  plugin{

    class plugin_config{
    public:
        void set_module_name(const std::string & value){
            _name=value;
        }

        std::string get_module_name(){
            return _name;
        }

        void set_module_folder(const std::string & value){
            _folder=value;
        }

        std::string get_module_folder(){
            return _folder;
        }


    private:
        std::string _name;
        std::string _folder;
    };

}}//namespacd modulepp::plugin


#endif //MODULESPP_PLUGIN_CONFIG_H
