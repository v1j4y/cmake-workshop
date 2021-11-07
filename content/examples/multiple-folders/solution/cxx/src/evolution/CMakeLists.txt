add_library(evolution)

target_sources(evolution
  PUBLIC
    evolution.hpp
  PRIVATE
    evolution.cpp
  )

target_include_directories(evolution
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
  )
