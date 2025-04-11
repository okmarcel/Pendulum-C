#ifndef PENDULUM_H
#define PENDULUM_H

#include <SDL2/SDL.h>

typedef struct {
    int size;

    int x;
    int y;

    struct Node *parent;
    struct Node *child;
} Node;

typedef struct {
    Node *root;
} Pendulum;

#endif