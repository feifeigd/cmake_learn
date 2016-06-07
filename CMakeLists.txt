cmake_minimum_required(VERSION 3.0)

project(cmake_learn)

include(CPack)
include(CTest)

if(UNIX)
	set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
	set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")
endif()

add_subdirectory(Demo1)

