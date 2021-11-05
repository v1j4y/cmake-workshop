add_library(io)

target_sources(io
  PUBLIC
    io.hpp
  PRIVATE
    io.cpp
  )

target_include_directories(io
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
  )
