#ifndef ENTITY_H
#define ENTITY_H

#include <SDL2/SDL.h>
#include "mathematics.h"

typedef struct
{
    Vec2 pos;
    Vec2 rot;
    Vec2 scale;
} Entity;

void updateEntities(SDL_Renderer* r, Entity* entities, uint32_t numEntities, float delta);
void drawEntities(SDL_Renderer* r, Entity* entities, uint32_t numEntities);

#endif