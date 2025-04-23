#ifndef RENDERER_H
#define RENDERER_H

#include "pendulum.h"

void set_color(SDL_Renderer *renderer, SDL_Color color);

void draw_background(SDL_Renderer *renderer);

void draw_node(SDL_Renderer *renderer, Node *node);

void draw_pendulum(SDL_Renderer *renderer, Pendulum *pend);

#endif
