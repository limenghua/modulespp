//
// Created by limenghua on 18-3-8.
//
#include "modulepp/module.h"
#include "modulepp/details/topo_sorting.h"

#include "mock_modules.h"

#include "CppUTest/TestHarness.h"

using namespace modulepp;

TEST_GROUP(TopoSorting)
{

};



TEST(TopoSorting,create_dependent_map)
{
    module_ptr m1=std::make_shared<module_b1>();
    module_ptr m2=std::make_shared<module_b2>();
    module_ptr m2_1=std::make_shared<module_b2_1>();
    module_ptr m3=std::make_shared<module_a3>();

    std::map<std::string,module_ptr> map_data;

    map_data[m1->get_name()]=m1;
    map_data[m2->get_name()]=m2;
    map_data[m2_1->get_name()]=m2_1;
    map_data[m3->get_name()]=m3;

    auto data = module_sorter::create_dependent_map(map_data);

    auto d1=data[m1];
    CHECK(d1.empty());

    auto d2=data[m2];
    CHECK(!d2.empty());

    CHECK(d2.find(m1) != d2.end());
    CHECK(d2.find(m2) == d2.end());
}


TEST(TopoSorting,Sorting)
{
    module_ptr m1=std::make_shared<module_b1>();
    module_ptr m2=std::make_shared<module_b2>();
    module_ptr m2_1=std::make_shared<module_b2_1>();
    module_ptr m3=std::make_shared<module_a3>();

    std::map<std::string,module_ptr> map_data;

    map_data[m1->get_name()]=m1;
    map_data[m2->get_name()]=m2;
    map_data[m2_1->get_name()]=m2_1;
    map_data[m3->get_name()]=m3;



    std::list<module_ptr> ret = module_sorter::topo_sorting(map_data);

    CHECK(ret.size() == map_data.size());

    std::list<module_ptr> expect={m1,m2_1,m2,m3};
    CHECK(ret==expect);
}






