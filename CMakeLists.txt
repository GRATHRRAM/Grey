cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(grey_project VERSION 1.0)

set(srcs
    src/main.c
    src/Map/map.c
)

add_executable(grey src/linux_main.c ${srcs})

target_link_libraries(grey PRIVATE m raylib)
