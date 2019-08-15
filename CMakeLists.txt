cmake_minimum_required(VERSION 3.14)
project(untitled2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR} ${CMAKE_MODULE_PATH})

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

find_package(glfw)
find_package(glad)

add_executable(untitled2 main.cpp Shader.cpp Shader.h)

if(TARGET glfw::glfw)
    target_link_libraries(untitled2 glfw::glfw)
endif()

if(TARGET glad::glad)
    target_link_libraries(untitled2 glad::glad)
endif()