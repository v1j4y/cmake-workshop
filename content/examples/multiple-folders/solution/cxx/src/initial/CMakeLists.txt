add_library(initial)

target_sources(initial
  PUBLIC
    initial.hpp
  PRIVATE
    initial.cpp
  )

target_include_directories(initial
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
  )
