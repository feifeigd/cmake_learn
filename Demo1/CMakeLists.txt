cmake_minimum_required(VERSION 2.8)

project(Demo1)

# 是否使用自己的库
option(USE_MYMATH "Use provided math implementation" ON)

# 配置文件的选项要在配置文件指令之前定义

# 配置文件
configure_file(config.h.in ${PROJECT_SOURCE_DIR}/config.h)

if(USE_MYMATH)
	include_directories(math)
	# 库代码
	add_subdirectory(math)
	set(EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)
endif()


aux_source_directory(. SRC)
add_executable(Demo1 ${SRC})
target_link_libraries(Demo1 ${EXTRA_LIBS})

install(TARGETS Demo1 DESTINATION bin)
