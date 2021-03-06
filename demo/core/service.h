#pragma once

#include <string>


namespace core {

class service{
public:
    virtual int version() =0;
    virtual std::string name() =0;
    virtual std::string describe() =0;
};


} //end namespace core {