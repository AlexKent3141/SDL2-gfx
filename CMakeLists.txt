cmake_minimum_required (VERSION 3.16.3)
project(SDL_gfx)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

if (MSVC)
else()
  set(CMAKE_C_FLAGS_DEBUG "-Wall -Wextra -Wpedantic -O0 -g")
  set(CMAKE_C_FLAGS_RELEASE "-Wall -Wextra -Wpedantic -O3")
endif()

include_directories(
  "./include")

add_subdirectory("./src")
add_subdirectory("./test")
