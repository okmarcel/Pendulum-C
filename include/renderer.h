#ifndef RENDERER_H
#define RENDERER_H

#include <SDL2/SDL.h>

void draw_background(SDL_Renderer *renderer);

void draw_sample_circle(SDL_Renderer *renderer, int xc, int yc, int r);

#endif
