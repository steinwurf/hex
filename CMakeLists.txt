cmake_minimum_required (VERSION 3.10)
project(hex)

file(GLOB hex_headers ./src/hex/*.hpp)

add_library(hex INTERFACE)
add_library(steinwurf::hex ALIAS hex)

target_include_directories(hex INTERFACE src/)

install(FILES ${hex_headers} DESTINATION ${CMAKE_INSTALL_PREFIX}/include/hex)
