#include "any_ptr_map.h"

#include<CppUTest/TestHarness.h>

using namespace util;

TEST_GROUP(AnyPtrMap)
{

};


TEST(AnyPtrMap, constructor)
{
    any_ptr_map any_map;
}

TEST(AnyPtrMap, PutOneShareValue) {
    any_ptr_map any_map;
    auto ptr = std::make_shared<int>(5);
    any_map.set<int>("key", ptr);

    CHECK_EQUAL(ptr.use_count(), 2);

    auto ptr_ret = any_map.get<int>("key");
    CHECK_TRUE(ptr_ret == ptr);
    CHECK_EQUAL(*(ptr_ret), 5);

    //int b;
    //any_map.set("b", b);    //无法通过编译
}

TEST(AnyPtrMap, CanPutDifrientTypes) {
    any_ptr_map any_map;
    any_map.set<int>("key_int", std::make_shared<int>(5));
    any_map.set<double>("key_double", std::make_shared<double>(5.0));
    any_map.set<std::string>("key_string", std::make_shared<std::string>("5.0"));

    CHECK_EQUAL(*(any_map.get<int>("key_int")), 5);
    DOUBLES_EQUAL(*(any_map.get<double>("key_double")), 5.0,0.000001);
    CHECK_TRUE(*(any_map.get<std::string>("key_string"))== std::string("5.0"));
    //int b;
    //any_map.set("b", b);    //无法通过编译
}


TEST(AnyPtrMap, NotExistKeyShouldThrow)
{
    any_ptr_map any_map;

    CHECK_THROWS(std::exception,any_map.get<int>("nokey"));
}

TEST(AnyPtrMap, TypeMissMatchShouldThrow)
{
    any_ptr_map any_map;
    auto ptr = std::make_shared<int>(5);
    any_map.set<int>("key", ptr);

    CHECK_THROWS(std::exception,any_map.get<double>("key"));
}


TEST(AnyPtrMap, CanRemoveOneExistKey)
{
    any_ptr_map any_map;
    auto ptr = std::make_shared<int>(5);
    any_map.set<int>("key", ptr);

    CHECK_TRUE(any_map.get<int>("key") == ptr);

    any_map.remove("key");
    CHECK_THROWS(std::exception,any_map.get<int>("key"));
}

TEST(AnyPtrMap, CanRemoveAllExistKey)
{
    any_ptr_map any_map;
    auto ptr = std::make_shared<int>(5);
    any_map.set<int>("key1", ptr);
    any_map.set<int>("key2", ptr);

    CHECK_TRUE(any_map.get<int>("key1") == ptr);
    CHECK_TRUE(any_map.get<int>("key2") == ptr);

    any_map.remove_all();
    CHECK_THROWS(std::exception,any_map.get<int>("key1"));
    CHECK_THROWS(std::exception,any_map.get<int>("key2"));
}

TEST(AnyPtrMap, CanDirectUseTypeAsKey)
{
    any_ptr_map any_map;
    auto ptr = std::make_shared<int>(5);
    any_map.set<int>(ptr);

    CHECK_TRUE(any_map.get<int>() == ptr);

    any_map.remove<int>();
    CHECK_THROWS(std::exception,any_map.get<int>());
}



class BaseClassA
{
public:
    virtual void f(){}
};

class ClassA:public BaseClassA
{
public:
    virtual void f(){}
};

class ClassB{
public:
    ClassB(int v):value(v){}

    int value;
};

struct StructA{
    int value;
};

TEST(AnyPtrMap, OtherUserDifineTypes)
{
    any_ptr_map any_map;

    auto base_ptr=std::make_shared<BaseClassA>();
    auto classA_ptr=std::make_shared<ClassA>();
    auto classB_ptr=std::make_shared<ClassB>(1);

    auto structA_ptr = std::shared_ptr<StructA>(new StructA());
    structA_ptr->value = 1;

    any_map.set<BaseClassA>(base_ptr);
    any_map.set<ClassA>(classA_ptr);
    any_map.set<ClassB>(classB_ptr);
    any_map.set<StructA>(structA_ptr);

    CHECK_TRUE(any_map.get<BaseClassA>() == base_ptr);
    CHECK_TRUE(any_map.get<ClassA>() == classA_ptr);
    CHECK_TRUE(any_map.get<ClassB>() == classB_ptr);
    CHECK_TRUE(any_map.get<StructA>() == structA_ptr);
}

