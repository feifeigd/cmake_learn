aux_source_directory(. SRC)
add_library(MathFunctions ${SRC})

# 安装头文件
file(GLOB INC ./*.h*)
install(FILES ${INC} DESTINATION include/Demo)

# 安装库
install(TARGETS MathFunctions DESTINATION lib)
