cmake_minimum_required(VERSION 3.28)

# 设置项目名称
project(MyProject)

# 指定 C++ 标准
set(CMAKE_CXX_STANDARD 17)

# 定义源代码目录
aux_source_directory(src DIR_SRCS)

# 定义头文件目录
include_directories(include)

# 指定构建类型为Release
set(CMAKE_BUILD_TYPE Debug)

# 添加可执行文件
add_executable(test main.cpp ${DIR_SRCS})

message("Print current DIR_SRCS: ${DIR_SRCS}\n")