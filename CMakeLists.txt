cmake_minimum_required(VERSION 3.10)
project(WATERTANK)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)
include_directories($ENV{SYSTEMC_HOME}/include)

find_library(systemc systemc $ENV{SYSTEMC_HOME}/lib-linux64)
link_directories($ENV{SYSTEMC_HOME}/lib-linux64)

add_executable(watertank_AMS src/valve_TDF.cpp src/watertank_LSF.cpp src/controller_TDF.cpp src/main_WATERTANK.cpp)
target_link_libraries(watertank_AMS systemc systemc-ams)