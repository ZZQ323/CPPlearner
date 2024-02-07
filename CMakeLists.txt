cmake_minimum_required(VERSION 3.10)
project(Tutorial VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

include_directories(C:\\Users\\admin\\CLionProjects\\Code-snippets\\include)
#include_directories(SYSTEM unixtest)
#add_subdirectory(. output)

#add_executable(main add.h add.cpp mai.cpp)

# 列出你的源代码文件
set(MAIN_SRC
    main.cpp

)
# 列出你的头文件
set(MAIN_HDR
        include/algorithms.hpp
)
add_executable(main ${MAIN_SRC} ${MAIN_HDR} )
