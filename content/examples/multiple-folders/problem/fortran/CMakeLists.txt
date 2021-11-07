cmake_minimum_required(VERSION 3.14)

project(example LANGUAGES Fortran)


add_library(conversion)

target_sources(conversion
  PUBLIC
    external/conversion.f90
  )


add_library(evolution)

target_sources(evolution
  PUBLIC
    src/evolution/ancestors.f90
    src/evolution/evolution.f90
  PRIVATE
    src/evolution/empty.f90
  )


add_library(initial)

target_sources(initial
  PUBLIC
    src/initial/initial.f90
  )


add_library(io)

target_sources(io
  PUBLIC
    src/io/io.f90
  )


add_library(parser)

target_sources(parser
  PUBLIC
    src/parser/parser.f90
  )


add_executable(automata src/main.f90)

target_link_libraries(automata
  PRIVATE
    conversion
    evolution
    initial
    io
    parser
  )
