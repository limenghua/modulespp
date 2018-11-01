# modulespp-- A Simple C++ Module Framework

## 主要特性--核心目标
- 模块生命周期管理
- 服务发现
- 动态模块加载--Plugin机制

## 基本哲学
- 接口隔离
- 精简

## 项目构建
项目采用CMake管理跨平台项目构建，构建前需要确认已经安装CMake  
Requirement:
1. CMake
2. Boost
3. CppUTest

- Use Virsual Studio In Windows
  1. 安装CMake：https://cmake.org/
  2. 下载编译Boost：http://www.boost.org/
  3. 设置环境变量BOOST_ROOT
  4. 下载编译CppUtest:http://cpputest.github.io/
     * cd download folder    
     * md build
     * cd build
     * cmake ..
     * 使用管理员权限打开CppUtest.sln,编译INSTALL项目，编译成功后后会自动安装CppUtest库到系统目录，根据需要编译Release或Debug

  5. 使用cmake 构建VS工程
     * md build
     * cd build
     * cmake ..

  6. 打开VS工程编译运行调试

 - Build On Linux
   1. git clone https://github.com/limenghua/modulespp.git
   2. cd modulespp
   3. mkdir build && cd build
   4. cmake ..
   5. make && make install
   
  7. Exapmple
  ```cpp
  //
// Created by limenghua on 18-3-10.
//
#include <modulepp/application.h>
#include <iostream>
#include <memory>
#include <ctime>

using namespace modulepp;

class time_service{
public:
    virtual std::time_t get_start_time() =0;
};

class time_service_imp:public time_service{
public:
    time_service_imp(){
        std::time( & _start_time);
    }

    virtual std::time_t get_start_time() override {
        return _start_time;
    }

    time_t _start_time;
};

std::shared_ptr<time_service> create_test_service(){
    return std::make_shared<time_service_imp>();
}

class time_module:public module{
public:
    time_module():module("time_module"){}

    virtual void start()override{
        module::start();
        auto srv = create_test_service();
        register_service<time_service>("time",srv);
    }
};

class client_module:public module{
public:
    client_module():module("client_module"){
        add_dependencies("time_module");
    }
};


int main(){
    application app;
    app.register_module(std::make_shared<time_module>());
    app.register_module(std::make_shared<client_module>());

    app.start();

    auto start_time =
            app.get_module("client_module")
            ->get_service<time_service>("time_module.time")
            ->get_start_time();

    std::cout<<"time_module.time:"
             <<start_time<<std::endl;

    app.stop();
}
  
  ```
