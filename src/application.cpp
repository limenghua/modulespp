//
// Created by limenghua on 18-2-8.
//

#include "application.h"
#include "topo_sorting.h"

using namespace modulepp;


void application::start() {
    auto topo_list = module_sorter::topo_sorting(_modules);

    for(auto m:topo_list){
        inject_all_dependency(m);
        m->start();
    }
}

void application::stop() {
    auto topo_list = module_sorter::topo_sorting(_modules);

    for(auto it=topo_list.rbegin();it!=topo_list.rend();it++){
        (*it)->stop();
        (*it)->clear_inject_modules();
    }
}

std::list<module_ptr> application::get_dependencys(module_ptr m) {
    std::list<module_ptr> ret;

    auto & depends = m->get_dependencies();

    for(auto & name:depends){
        ret.push_back(get_module(name));
    }

    return ret;
}

void application::inject_all_dependency(module_ptr m) {
    auto denpends = get_dependencys(m);

    for(auto depend:denpends){
        m->inject_module(depend);
    }
}