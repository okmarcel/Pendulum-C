#ifndef SIMULATION_H
#define SIMULATION_H

#include <SDL2/SDL.h>
#include <stdbool.h>

typedef struct {
    SDL_Window *window;
    SDL_Renderer *renderer;
    bool running;
} Simulation;


bool simulation_init(Simulation *sim, const char *title, int width, int height);

void simulation_run(Simulation *sim);

void simulation_quit(Simulation *sim);

#endif
