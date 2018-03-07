//
// Created by limenghua on 18-2-8.
//

#include "application.h"
#include <list>
#include <set>

using namespace module;

class depend_map{
public:
    typedef std::set<module_ptr> dependency;
    typedef std::map<module_ptr,dependency> map_data;

    depend_map(std::map<std::string,module_ptr> & modules){
        for(auto it:modules){
            auto module=it.second;
            const std::set<std::string> depend = module->get_dependencies();
        }
    }



    map_data _map_data;
};

std::list<module_ptr> topo_sorting(std::map<std::string,module_ptr> modules){
    std::list<module_ptr> topo_list;
    while(! modules.empty()){
        std::vector<module_ptr> ret;
        for(auto it=modules.begin();it!=modules.end();it++){
            auto module=it->second;
            if(module->get_dependencies().empty())
        }
    }

}


void application::start() {
    auto depend_map = create_depend_map(_modules);
    auto topo_list = topo_sorting(depend_map);

    for(auto m:topo_list){
        inject_all_dependcy(m);
        m->start();
    }
}

void application::stop() {
    auto depend_map = create_depend_map(_modules);
    auto topo_list = topo_sorting(depend_map);

    for(auto it=topo_list.rbegin();it!=topo_list.rend();it++){
        (*it)->stop();
        (*it)->clear_inject_modules();
    }
}