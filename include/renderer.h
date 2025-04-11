#ifndef RENDERER_H
#define RENDERER_H

#include <SDL2/SDL.h>
#include "pendulum.h"

void draw_background(SDL_Renderer *renderer);

void draw_sample_circle(SDL_Renderer *renderer, int xc, int yc, int r);

void draw_node(SDL_Renderer *renderer, Node *node);

void draw_pendulum(SDL_Renderer *renderer, Pendulum *pend);

#endif
