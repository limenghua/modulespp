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