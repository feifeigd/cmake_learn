cmake_minimum_required(VERSION 2.8)

project(Demo1)

aux_source_directory(. SRC)
add_executable(Demo1 ${SRC})
