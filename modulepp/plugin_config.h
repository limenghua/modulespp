//
// Created by limenghua on 18-3-11.
//

#ifndef MODULESPP_PLUGIN_CONFIG_H
#define MODULESPP_PLUGIN_CONFIG_H
#include <string>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/property_tree/json_parser.hpp>

namespace modulepp{
namespace  plugin{

    class plugin_config{
    public:
        typedef boost::property_tree::ptree module_propertys;
        void set_module_name(const std::string & value){
            _name=value;
        }

        std::string get_module_name()const {
            return _name;
        }

        void set_module_folder(const std::string & value){
            _folder=value;
        }

        std::string get_module_folder()const {
            return _folder;
        }

        module_propertys & get_module_propertys(){
            return _property;
        }

        const module_propertys & get_module_propertys()const{
            return _property;
        }

        void load_propertys(const std::string & filename){
            return boost::property_tree::read_json(filename, _property);
        }


    private:
        std::string _name;
        std::string _folder;
        module_propertys _property;
    };

}}//namespacd modulepp::plugin


#endif //MODULESPP_PLUGIN_CONFIG_H
