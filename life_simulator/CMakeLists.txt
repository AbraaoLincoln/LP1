cmake_minimum_required(VERSION 3.5)
project (life_simulator)

set( GCC_COMPILE_FLAGS "-Wall" )
set( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COMPILE_FLAGS}" )

include_directories(include)

file(GLOB SOURCE "src/*.cpp")

add_executable(slife ${SOURCE})
