
find_package(SDL2 REQUIRED)

include_directories(
  ${SDL2_INCLUDE_DIRS})

add_library(SDL2_gfx
  SHARED
    SDL2_framerate.c
    SDL2_gfxPrimitives.c
    SDL2_imageFilter.c
    SDL2_rotozoom.c)

set_target_properties(SDL2_gfx
  PROPERTIES
    C_VISIBILITY_PRESET hidden
    POSITION_INDEPENDENT_CODE ON)

target_link_libraries(SDL2_gfx
  PRIVATE
    ${SDL2_LIBRARIES})
