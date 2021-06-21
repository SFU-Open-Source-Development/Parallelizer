cmake_minimum_required(VERSION 3.19)
project(Parallelizer)

set(Boost_ARCHITECTURE "-x64")
set(Boost_USE_STATIC_LIBS ON)
set(CMAKE_CXX_STANDARD 14)
set(BOOST_ROOT "include/boost_1_76_0")
find_package(Boost 1.74.0 COMPONENTS log log_setup)

if(NOT Boost_FOUND)
    message(FATAL_ERROR "could not find boost")
endif()

include_directories(src)
#include_directories(include/boost_1_74_0)

add_executable(Parallelizer
        src/main-api.cpp
        src/file_handler.cpp
        src/utils.h)

target_link_libraries(Parallelizer Boost::log Boost::log_setup)