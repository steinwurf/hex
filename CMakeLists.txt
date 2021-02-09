cmake_minimum_required(VERSION 3.12)
project(hex)

# Define library
add_library(hex INTERFACE)
target_compile_features(hex INTERFACE cxx_std_14)
target_include_directories(hex INTERFACE src/)
add_library(steinwurf::hex ALIAS hex)

# Install headers
install(
  DIRECTORY ./src/hex
  DESTINATION ${CMAKE_INSTALL_PREFIX}/include
  FILES_MATCHING
  PATTERN *.hpp)
