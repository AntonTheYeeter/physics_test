#include <SDL2/SDL.h>

#include "entity.h"

int main(int argc, char** argv)
{
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window* window = SDL_CreateWindow("Physics", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    Entity entities[] = {
        {{100, 100}, {0, 0}, {50, 50}},
        {{300, 100}, {0, 0}, {50, 50}}
    };
    uint32_t numEntities = sizeof(entities) / sizeof(entities[0]);

    float nowTime = SDL_GetPerformanceCounter();
    float lastTime = 0;
    float delta = 0;

    SDL_bool running = SDL_TRUE;
    while(running)
    {
        lastTime = nowTime;
        nowTime = SDL_GetPerformanceCounter();
        delta = (nowTime - lastTime) / SDL_GetPerformanceFrequency();

        SDL_RenderClear(renderer);
        
        updateEntities(renderer, entities, numEntities, delta);
        drawEntities(renderer, entities, numEntities);
        
        SDL_RenderPresent(renderer);

        SDL_Event e;
        while(SDL_PollEvent(&e))
        {
            switch(e.type)
            {
                case SDL_QUIT:
                    running = SDL_FALSE;
                    break;
            }
        }
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}