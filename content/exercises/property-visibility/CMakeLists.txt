cmake_minimum_required(VERSION 3.14)

project(example LANGUAGES CXX)


add_library(world)
target_sources(world
  PUBLIC
    world/world.hpp
  PRIVATE
    world/world.cpp
  )
target_include_directories(world
  PUBLIC
    world
  )
# target_compile_definitions(world PRIVATE "MY_DEFINITION")


add_library(hello_world)
target_sources(hello_world
  PUBLIC
    hello_world/hello_world.hpp
  PRIVATE
    hello_world/hello_world.cpp
  )
target_include_directories(hello_world
  PUBLIC
    hello_world
  )

# hello_world depends on world
target_link_libraries(hello_world PRIVATE world)


add_library(greeting)
target_sources(greeting
  PUBLIC
    greeting/greeting.hpp
  PRIVATE
    greeting/greeting.cpp
  )
target_include_directories(greeting
  PUBLIC
    greeting
  )

# greeting depends on hello_world
target_link_libraries(greeting PRIVATE hello_world)


add_executable(example main.cpp)

# example depends on greeting
target_link_libraries(example PRIVATE greeting)
