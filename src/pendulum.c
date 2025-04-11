#include <stdbool.h>
#include "pendulum.h"

void free_nodes(Pendulum *pend) {
    free(pend->root);
}

bool append_node(Node *parent, int radius, int x, int y) {
    Node *new_node = malloc(sizeof(Node));
    if (new_node == NULL) {
        return false;
    }

    new_node->child = NULL;
    new_node->parent = parent;
    new_node->radius = radius;
    new_node->x = x;
    new_node->y = y;

    parent->child = new_node;

    return true;
}

bool pendulum_init(Pendulum *pend) {
    Node *node = malloc(sizeof(Node));
    if (node == NULL) {
        return false;
    }

    node->child = NULL;
    node->parent = NULL;
    node->radius = 12;
    node->x = 400;
    node->y = 300;
    pend->root = node;

    return true;
}
