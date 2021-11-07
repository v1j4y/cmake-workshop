add_library(conversion)

target_sources(conversion
  PUBLIC
    conversion.hpp
  PRIVATE
    conversion.cpp
  )

target_include_directories(conversion
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
  )
