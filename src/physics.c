#include "physics.h"
#include "pendulum.h"
#include "constants.h"
#include <math.h>
#include <stdio.h>

void calculate_node_pos(Node *node) {
    double g = GRAVITY;
    double dt = SPEED;
    double accel = - (g / node->rod_length) * sin(node->theta);

    node->omega += accel * dt;
    node->theta += node->omega * dt;

    node->x = (int)node->rod_length * sin(node->theta) + node->parent->x;
    node->y = (int)node->rod_length * cos(node->theta) + node->parent->y;

    return;
}
