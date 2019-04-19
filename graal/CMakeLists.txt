cmake_minimum_required(VERSION 3.10.2)
project(graal)

# Locate GTest package (library)
find_package(GTest REQUIRED)
include_directories( ${GTEST_INCLUDE_DIRS})

set( GCC_COMPILE_FLAGS "-Wall" )
set( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COMPILE_FLAGS}" )

include_directories(include)

#=== Library ===

# We want to build a static library.
add_library(graal STATIC "src/graal.cpp")

#Set the location for library installation -- i.e., /usr/lib in this case
# not really necessary in this example. Use "make install" to apply
install(TARGETS graal ARCHIVE DESTINATION ${CMAKE_SOURCE_DIR}/lib)

# The file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES_TEST "test/*.cpp" )

# Define the sources
add_executable(run_tests ${SOURCES_TEST} )

# Link with the google test libraries.
target_link_libraries(run_tests PRIVATE ${GTEST_LIBRARIES} PRIVATE pthread PRIVATE graal )
