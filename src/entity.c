#include "entity.h"

static float gravity = 100.0f;

void updateEntities(SDL_Renderer* r, Entity* entities, uint32_t numEntities, float delta)
{
    for(uint32_t i = 0; i < numEntities; i++)
    {
        entities[i].pos.y += gravity * delta;
    }

    if(gravity < 500.0f) 
    {
        gravity += 0.5f;
    }

    printf("%f\n", gravity);
}

void drawEntities(SDL_Renderer* r, Entity* entities, uint32_t numEntities)
{
    SDL_SetRenderDrawColor(r, 255, 0, 0, 255);

    for(uint32_t i = 0; i < numEntities; i++)
    {
        SDL_Rect rect;
        rect.w = entities[i].scale.x;
        rect.h = entities[i].scale.y;

        rect.x = entities[i].pos.x;
        rect.y = entities[i].pos.y;

        SDL_RenderFillRect(r, &rect);
        SDL_RenderDrawRect(r, &rect);
    }

    SDL_SetRenderDrawColor(r, 0, 0, 0, 255);
}