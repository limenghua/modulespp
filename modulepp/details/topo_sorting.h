//
// Created by limenghua on 18-3-8.
//

#ifndef MODULESPP_TOPO_SORTING_H
#define MODULESPP_TOPO_SORTING_H

#include "modulepp/module.h"
#include <map>
#include <vector>
#include <list>
#include <set>
#include <iostream>

namespace modulepp{
    class module_sorter{
    public:
        typedef std::set<module_ptr> dependencys;
        typedef std::map<module_ptr,dependencys> map_data;

        static map_data create_dependent_map(const std::map<std::string,module_ptr> & modules)
        {
            map_data data;
            for(auto it:modules){
                auto module=it.second;

                const std::set<std::string> &depends = module->get_dependencies();
                data[module]=dependencys();
                for(auto & name : depends){
                    auto res_it=modules.find(name);
                    if(res_it == modules.end()){
                        throw std::runtime_error("not resovlved dependence module");
                    }
                    data[module].insert(res_it->second);
                }
            }

            return data;
        }

        static std::list<module_ptr> topo_sorting(const std::map<std::string,module_ptr> & modules)
        {
            std::list<module_ptr> ret;
            map_data data_copy = create_dependent_map(modules);

            while(!data_copy.empty()){
                std::vector<module_ptr> modules_tmp;
                for(auto it=data_copy.begin();it!= data_copy.end();){
                    module_ptr curr_module=it->first;
                    dependencys & dep=it->second;

                    if(dep.empty()){
                        modules_tmp.push_back(it->first);
                        it=data_copy.erase(it);
                    }
                    else{
                        it++;
                    }
                }
                if(modules_tmp.empty()){
                    throw std::runtime_error("topology sorting with  circular dependencies");
                }

                for(auto &module_select:modules_tmp){
                    for(auto &module:data_copy){
                        module.second.erase(module_select);
                    }
                }

                std::sort(modules_tmp.begin(),modules_tmp.end(),[](module_ptr m1,module_ptr m2){
                   return m1->get_priority() > m2->get_priority();
                });

                ret.insert(ret.end(),modules_tmp.begin(),modules_tmp.end());
            }

            return ret;
        }

    };

}


#endif //MODULESPP_TOPO_SORTING_H
