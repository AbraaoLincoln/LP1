cmake_minimum_required(VERSION 3.10.2)
project(graal)

set( GCC_COMPILE_FLAGS "-Wall" )
set( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COMPILE_FLAGS}" )

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_executable(driver ${SOURCES})