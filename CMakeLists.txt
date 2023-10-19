cmake_minimum_required(VERSION 3.25)
project(test)

set(CMAKE_CXX_STANDARD 17)

\# 添加可执行文件生成目录
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
#add_executable(test main.cpp data_structure/list/List01.cpp data_structure/list/List01.h)

add_executable(main main.cpp )
add_executable(List01 data_structure/list/List01.cpp)


add_executable(Array01 array/Array01.cpp )
add_executable(Pointer01 pointer/Pointer01.c )
add_executable(string01 class/string01.cpp )
add_executable(dynamic pointer/dynamic.cpp)
add_executable(Class01 class/Class01.cpp)
add_executable(List02 data_structure/list/List02.cpp)
add_executable(List03 data_structure/list/List03.cpp)