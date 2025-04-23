#ifndef PENDULUM_H
#define PENDULUM_H

#include <SDL2/SDL.h>
#include <stdbool.h>

typedef struct Node {
    int radius;

    double rod_length;
    int x;
    int y;
    double theta; // current angle in radians
    double omega; // current angular velocity

    struct Node *parent;
    struct Node *child;
} Node;

typedef struct {
    Node *root;
} Pendulum;

void free_nodes(Pendulum *pend);

void new_node_init_values(Node *node);

bool append_node(Node *parent);

bool pendulum_init(Pendulum *pend);

#endif