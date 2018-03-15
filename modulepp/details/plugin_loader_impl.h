//
// Created by limenghua on 18-3-12.
//

#ifndef MODULESPP_PLUGIN_LOADER_IMPL_H
#define MODULESPP_PLUGIN_LOADER_IMPL_H
#include "modulepp/module.h"
#include "modulepp/plugin_module.h"
#include <boost/dll/import.hpp> // for import_alias

#include <list>
#include <string>

namespace modulepp{
    namespace plugin{

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

            std::list<module_ptr> load_plugins(){
                std::list<module_ptr> modules;

                std::list<std::string> dllFiles = load_all_dllFile();
                for(auto & file:dllFiles){
                    module_ptr m = load_module(file);

                    if(m){
                        modules.push_back(m);
                    }
                }
                return modules;
            }

            std::list<std::string> load_all_dllFile(){
                return std::list<std::string>{
                        "demo_plugin",
                        "demo_plugin2"
                };
            }

            module_ptr load_module(const std::string &file){
                boost::filesystem::path lib_path(_path);

                boost::shared_ptr<plugin_module> plugin =
                        dll::import<plugin_module>(          // type of imported symbol is located between `<` and `>`
                                lib_path / file,                     // path to the library and library name
                                "plugin_module",                                       // name of the symbol to import
                                dll::load_mode::append_decorations              // makes `libmy_plugin_sum.so` or `my_plugin_sum.dll` from `my_plugin_sum`
                        );

                std::shared_ptr<plugin_module> module = to_std(plugin);

                return module;
            }

        private:
            std::string _path;

        };



    }}


#endif //MODULESPP_PLUGIN_LOADER_IMPL_H
