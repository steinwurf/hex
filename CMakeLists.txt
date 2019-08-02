cmake_minimum_required (VERSION 3.12)
project(hex)

add_library(hex INTERFACE)
target_include_directories(hex INTERFACE src/)
