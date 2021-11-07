cmake_minimum_required(VERSION 3.14)

# note that the code below is a bad example only used for a discussion
project(bad-example LANGUAGES CXX)

add_definitions(-DMY_DEFINITION)

include_directories(world)
include_directories(hello_world)
include_directories(greeting)

link_libraries(
  ${PROJECT_BINARY_DIR}/libgreeting.a
  ${PROJECT_BINARY_DIR}/libhello_world.a
  ${PROJECT_BINARY_DIR}/libworld.a
  )

add_library(world
  world/world.hpp
  world/world.cpp
  )

add_library(hello_world
  hello_world/hello_world.hpp
  hello_world/hello_world.cpp
  )
add_dependencies(hello_world world)

add_library(greeting
  greeting/greeting.hpp
  greeting/greeting.cpp
  )
add_dependencies(greeting hello_world)

add_executable(example main.cpp)
