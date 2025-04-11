#ifndef PENDULUM_H
#define PENDULUM_H

#include <SDL2/SDL.h>
#include <stdbool.h>

typedef struct Node {
    int radius;

    int x;
    int y;

    struct Node *parent;
    struct Node *child;
} Node;

typedef struct {
    Node *root;
} Pendulum;

void free_nodes(Pendulum *pend);

bool append_node(Node *parent, int radius, int x, int y);

bool pendulum_init(Pendulum *pend);

#endif