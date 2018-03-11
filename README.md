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

- Use Virsual Studio In Windows
  1. 安装CMake：https://cmake.org/
  2. 下载编译Boost：http://www.boost.org/
  3. 设置环境变量BOOST_ROOT
  4. 下载编译CppUtest:http://cpputest.github.io/
  
  cd download folder  
  
  md build
  
  cd build
  
  cmake ..
  
  打开CppUtest.sln,编译INSTALL项目，完成CppUtest库安装

