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

void update_node_pos(Node *node, int new_x, int new_y);

bool append_node(Node *parent);

bool pendulum_init(Pendulum *pend);

#endif