cmake_minimum_required(VERSION 2.8)

project(cmake_learn)

if(UNIX)
	set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
	set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")
endif()

set (Demo1_VERSION_MAJOR 1)
set (Demo1_VERSION_MINOR 0)
add_subdirectory(Demo1)

#生成二进制安装包：
#cpack -C CPackConfig.cmake

#生成源码安装包
#cpack -C CPackSourceConfig.cmake

# 构建CPack安装包
include(InstallRequiredSystemLibries)
set(CPACK_RESOURCE_FILE_LICENSE ${CMAKE_CURRENT_SOURCE_DIR}/License.txt)
# 版本号
set(CPACK_PACKAGE_VERSION_MAJOR "${Demo1_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${Demo1_VERSION_MINOR}")
include(CPack)
