add_library(evolution)

target_sources(evolution
  PUBLIC
    ancestors.f90
    evolution.f90
  PRIVATE
    empty.f90
  )
