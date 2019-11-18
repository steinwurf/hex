cmake_minimum_required (VERSION 3.10)
project(hex)

add_library(hex INTERFACE)
add_library(steinwurf::hex ALIAS hex)

target_include_directories(hex INTERFACE src/)
