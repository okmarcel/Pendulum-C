#include <stdio.h>
#include "simulation.h"

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

const char *TITLE = "Pendulum Simulation";

int main(void) {
    Simulation sim = {0};

    if (!simulation_init(&sim, TITLE, WINDOW_WIDTH, WINDOW_HEIGHT)) {
        printf("Error while initializing\n");
        return 1;
    }

    simulation_run(&sim);

    simulation_quit(&sim);

    return 0;
}
