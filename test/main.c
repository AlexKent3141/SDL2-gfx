#include "SDL2/SDL.h"
#include "SDL2_framerate.h"
#include "SDL2_gfxPrimitives.h"
#include "stdio.h"
#include "stdlib.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

int main()
{
  if (SDL_Init(SDL_INIT_VIDEO) != 0)
  {
    printf("SDL_Init error: %s\n", SDL_GetError());
    return EXIT_FAILURE;
  }

  SDL_Window* window = SDL_CreateWindow(
    "SDL2 gfx test",
    SDL_WINDOWPOS_UNDEFINED,
    SDL_WINDOWPOS_UNDEFINED,
    WINDOW_WIDTH,
    WINDOW_HEIGHT,
    SDL_WINDOW_SHOWN);
  if (window == NULL)
  {
    printf("SDL_CreateWindow error: %s\n", SDL_GetError());
    return EXIT_FAILURE;
  }

  SDL_Renderer* renderer = SDL_CreateRenderer(
    window,
    -1,
    SDL_RENDERER_ACCELERATED);
  if (renderer == NULL)
  {
    printf("SDL_CreateRenderer error: %s\n", SDL_GetError());
    return EXIT_FAILURE;
  }

  FPSmanager fps;
  SDL_initFramerate(&fps);
  SDL_setFramerate(&fps, 60);

  int16_t polyx[4] = { 50, 150, 150, 50 };
  int16_t polyy[4] = { 150 , 150, 50, 50 };

  int16_t bezierx[3] = { 200, 300, 400 };
  int16_t beziery[3] = { 300, 400, 350 };

  SDL_bool stop = SDL_FALSE;
  SDL_Event event;
  while (!stop)
  {
    while (SDL_PollEvent(&event))
    {
      switch (event.type)
      {
        case SDL_QUIT:
          stop = SDL_TRUE;
          break;
        default:
          break;
      }
    }

    // Use SDL2 gfx to draw some shapes.
    filledPolygonColor(renderer, polyx, polyy, 4, 0xFF0000FF);
    filledCircleColor(renderer, 300, 100, 50, 0xFFFF0000);
    bezierColor(renderer, bezierx, beziery, 3, 2, 0xFF00FF00);

    SDL_RenderPresent(renderer);

    SDL_framerateDelay(&fps);
  }

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return EXIT_SUCCESS;
}
