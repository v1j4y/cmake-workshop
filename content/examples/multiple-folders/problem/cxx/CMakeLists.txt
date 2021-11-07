cmake_minimum_required(VERSION 3.14)

project(example LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_library(conversion)

target_sources(conversion
  PUBLIC
    external/conversion.hpp
  PRIVATE
    external/conversion.cpp
  )

target_include_directories(conversion
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/external
  )


add_library(evolution)

target_sources(evolution
  PUBLIC
    src/evolution/evolution.hpp
  PRIVATE
    src/evolution/evolution.cpp
  )

target_include_directories(evolution
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/src/evolution
  )


add_library(initial)

target_sources(initial
  PUBLIC
    src/initial/initial.hpp
  PRIVATE
    src/initial/initial.cpp
  )

target_include_directories(initial
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/src/initial
  )


add_library(io)

target_sources(io
  PUBLIC
    src/io/io.hpp
  PRIVATE
    src/io/io.cpp
  )

target_include_directories(io
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/src/io
  )


add_library(parser)

target_sources(parser
  PUBLIC
    src/parser/parser.hpp
  PRIVATE
    src/parser/parser.cpp
  )

target_include_directories(parser
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/src/parser
  )


add_executable(automata src/main.cpp)

target_link_libraries(automata
  PRIVATE
    conversion
    evolution
    initial
    io
    parser
  )
