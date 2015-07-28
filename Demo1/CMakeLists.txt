cmake_minimum_required(VERSION 2.8)
cmake_policy(SET CMP0048 NEW)
project(Demo1 VERSION 1.0.1)

include(CTest)

# 是否使用自己的库
# option(USE_MYMATH "Use provided math implementation" ON)
include(${CMAKE_ROOT}/Modules/CheckFunctionExists.cmake)
check_function_exists(pow HAVE_POW)

# 配置文件的选项要在配置文件指令之前定义

# 配置文件
configure_file(config.h.in ${PROJECT_SOURCE_DIR}/config.h)

if(NOT HAVE_POW)
	include_directories(math)
	# 库代码
	add_subdirectory(math)
	set(EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)
endif()


aux_source_directory(. SRC)
add_executable(Demo1 ${SRC})
target_link_libraries(Demo1 ${EXTRA_LIBS})

install(TARGETS Demo1 DESTINATION bin)

# 启用测试
enable_testing()

add_test(test_run Demo1 5 2)

add_test(test_usage Demo1)
set_tests_properties(test_usage PROPERTIES PASS_REGULAR_EXPRESSION "Usage: .* base exponent")

macro(do_test arg1 arg2 result)
	add_test(test_${arg1}_${arg2} Demo1 ${arg1} ${arg2})
	set_tests_properties(test_${arg1}_${arg2} PROPERTIES PASS_REGULAR_EXPRESSION ${result})
endmacro()

# 调用宏
do_test(5 2 "is 25")
do_test(10 5 "is 100000")
do_test(2 10 "is 1024")
