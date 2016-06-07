cmake_minimum_required(VERSION 2.8)

project(cmake_learn)

include(CTest)

if(UNIX)
	set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
	set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")
endif()

#add_subdirectory(Demo1)

