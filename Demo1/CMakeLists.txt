cmake_minimum_required(VERSION 2.8)

project(Demo1)

# 库代码
add_subdirectory(math)
include_directories(math)

aux_source_directory(. SRC)
add_executable(Demo1 ${SRC})
target_link_libraries(Demo1 MathFunctions)
