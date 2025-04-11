#include <stdio.h>
#include "simulation.h"
#include "constants.h"

int main(void) {
    Simulation sim;

    if (!simulation_init(&sim, TITLE, WINDOW_WIDTH, WINDOW_HEIGHT)) {
        printf("Error while initializing\n");
        return 1;
    }

    simulation_run(&sim);

    simulation_clean(&sim);

    return 0;
}
