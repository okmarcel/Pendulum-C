#include <stdio.h>
#include <SDL2/SDL.h>
#include "simulation.h"

bool simulation_init(Simulation *sim, const char *title, int width, int height) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        return false;
    }

    sim->window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
    if (sim->window == NULL) {
        return false;
    }

    sim->renderer = SDL_CreateRenderer(sim->window, -1, SDL_RENDERER_ACCELERATED);
    if (sim->renderer == NULL) {
        return false;
    }

    return true;
}

void simulation_play(Simulation *sim) {
    sim->running = true;

    SDL_Event e;
    while (sim->running) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT || e.key.keysym.sym == SDLK_ESCAPE) {
                sim->running = false;
                break;
            }
            
            SDL_SetRenderDrawColor(sim->renderer, 0, 0, 0, 255);
            SDL_RenderClear(sim->renderer);
            SDL_RenderPresent(sim->renderer);

            SDL_Delay(16);
        }
    }

    return;
}

void simulation_quit(Simulation *sim) {
    
    SDL_DestroyWindow(sim->window);
    SDL_DestroyRenderer(sim->renderer);
    SDL_Quit();

    return;
}
