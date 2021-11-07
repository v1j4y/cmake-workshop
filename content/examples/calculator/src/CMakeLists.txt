add_library(calculator)

target_sources(
  calculator
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/calculator.h
  PRIVATE
    add.f90
    subtract.f90
  )

target_include_directories(
  calculator
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
  )


# this sets GIT_HASH used by configure_file
include(git-version.cmake)

# generate file version.h from version-template.h
configure_file(
  version-template.h
  ${PROJECT_BINARY_DIR}/generated/version.h
  @ONLY
  )


add_executable(calculator.x)

target_sources(
  calculator.x
  PRIVATE
    main.cpp
  )

target_link_libraries(
  calculator.x
  PRIVATE
    calculator
  )

target_include_directories(
  calculator.x
  PRIVATE
    ${PROJECT_BINARY_DIR}/generated
  )


install(
  TARGETS calculator.x
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  )

install(
  TARGETS calculator
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  )
