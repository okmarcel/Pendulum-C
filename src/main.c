#include <stdio.h>
#include "simulation.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

#define TITLE "pendulum simulation"

int main(void) {
    Simulation sim = {0};

    if (!simulation_init(&sim, TITLE, WINDOW_WIDTH, WINDOW_HEIGHT)) {
        printf("Error while initializing\n");
        return 1;
    }

    simulation_play(&sim);

    simulation_quit(&sim);

    return 0;
}
