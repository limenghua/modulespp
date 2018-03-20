//
// Created by limenghua on 18-3-12.
//

#ifndef MODULESPP_PLUGIN_LOADER_IMPL_H
#define MODULESPP_PLUGIN_LOADER_IMPL_H
#include <modulepp/module.h>
#include <modulepp/plugin/plugin_module.h>

#include <boost/dll/import.hpp> // for import_alias

#include <list>
#include <string>

namespace modulepp{
    namespace loader{

        using modulepp::plugin::plugin_config;
        using modulepp::plugin::plugin_module;

        namespace dll = boost::dll;

        template<class T> std::shared_ptr<T> to_std(boost::shared_ptr<T> &p) {
            return std::shared_ptr<T>(p.get(), [p](T* t) mutable { p.reset(); });
        }

        template<class T> boost::shared_ptr<T> to_boost(std::shared_ptr<T> &p) {
            return boost::shared_ptr<T>(p.get(), [p](T* t) mutable { p.reset(); });
        }

        class plugin_loader_impl{
        public:
            plugin_loader_impl(const std::string & path):_path(path){}

            std::string get_root_folder(){return _path;}

            std::string get_config_file(){
                auto path = boost::filesystem::path(_path) / "plugin.json";
                return path.string();
            }

            std::list<module_ptr> load_plugins(){
                std::list<module_ptr> modules;

                std::string config_file=get_config_file();

                if(boost::filesystem::exists(config_file)){

                    plugin_config config;
                    config.set_module_folder(_path);
                    config.load_propertys(config_file);

                    module_ptr module = load_plugin(config);
                    if(module){
                        modules.push_back(module);
                    }

                }

                std::list<module_ptr> child_modules = load_sub_plugins();
                modules.insert(modules.begin(),child_modules.begin(),child_modules.end());

                return modules;
            }

            module_ptr load_plugin(plugin_config & config){

                std::string module_name = config.get_module_name();

                boost::filesystem::path lib_path(_path);

                boost::shared_ptr<plugin_module> plugin =
                        dll::import<plugin_module>(          // type of imported symbol is located between `<` and `>`
                                lib_path / module_name,      // path to the library and library name
                                "plugin_module",                                       // name of the symbol to import
                                dll::load_mode::append_decorations              // makes `libmy_plugin_sum.so` or `my_plugin_sum.dll` from `my_plugin_sum`
                        );

                std::shared_ptr<plugin_module> module = to_std(plugin);

                module->set_config(config);

                return module;
            }

            std::list<module_ptr> load_sub_plugins(){
                std::list<module_ptr> modules;

                std::list<std::string> sub_directory = get_sub_directory();

                for(auto &sub:sub_directory){
                    plugin_loader_impl loader(sub);

                    std::list<module_ptr> m=loader.load_plugins();

                    modules.insert(modules.begin(),m.begin(),m.end());
                }

                return modules;
            }

            std::list<std::string> get_sub_directory(){
                using boost::filesystem::directory_iterator;

                std::list<std::string> sub_folders;

                directory_iterator end;
                for(directory_iterator pos(_path);pos != end;pos++){
                    if(boost::filesystem::is_directory(*pos)){
                        sub_folders.push_back(pos->path().string());
                    }
                }


                return sub_folders;
            }


        private:
            std::string _path;

        };



    }}


#endif //MODULESPP_PLUGIN_LOADER_IMPL_H
