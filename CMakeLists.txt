cmake_minimum_required(VERSION 3.26)
project(usr)

set(CMAKE_CXX_STANDARD 17)

# 添加你的自定义list源文件
add_library(MyList
        src/list.cpp
        include/forward_list.hpp)

add_executable(usr main.cpp)

# 链接main程序和你的自定义list
target_link_libraries(main MyList)