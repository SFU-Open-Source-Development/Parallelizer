cmake_minimum_required(VERSION 3.19)
project(Parallelizer)

set(Boost_ARCHITECTURE "-x64")
set(CMAKE_CXX_STANDARD 14)
set(BOOST_ROOT "include/boost_1_76_0")
set(Boost_DEBUG 1)
find_package(Boost 1.76.0 COMPONENTS log log_setup)

if(NOT Boost_FOUND)
    message(FATAL_ERROR "could not find boost")
endif()

include_directories(src)
include_directories(include/boost_1_76_0)

add_executable(Parallelizer
        src/main-api.cpp
#        src/file_handler.cpp
        )

target_link_libraries(Parallelizer Boost::log Boost::log_setup)