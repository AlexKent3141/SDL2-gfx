
find_package(SDL2 REQUIRED)

include_directories(
  ${SDL2_INCLUDE_DIRS})

add_executable(test
  main.c)

target_link_libraries(test
  PRIVATE
    SDL2_gfx
    ${SDL2_LIBRARIES})
