#ifndef _MODULE_MGR_H
#define _MODULE_MGR_H

#include <map>
#include <list>
#include <memory>

namespace module{
class module;
typedef std::shared_ptr<module> module_ptr;

class module_mgr
{
public:
    void register_module(module_ptr module){
        std::string name = module->get_name();
        _modules[name]=module;
    }

    module_ptr get_module(const std::string & name){
        auto it = _modules.find(name);
        if(it==std::end(_modules)){
            throw std::runtime_error("module not found");
        }
        return it->second;
    }

    std::list<std::string> get_module_names(){
        std::list<std::string> ret;

        for(auto & item:_modules){
            ret.push_back(item.first);
        }
        return ret;
    }
private:
    std::map<std::string,module_ptr> _modules;
};


}//




#endif //_MODULE_MGR_H