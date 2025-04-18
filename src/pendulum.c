#include <stdbool.h>
#include <stdlib.h>
#include "pendulum.h"
#include "constants.h"

void free_nodes(Pendulum *pend) {
    Node *node = pend->root;
    Node *next_node;

    while (node) {
        next_node = node->child;
        free(node);
        node = next_node;
    }

    return;
}

void update_node_pos(Node *node, int new_x, int new_y) {
    node->x = new_x;
    node->y = new_y;

    return;
}

bool append_node(Node *parent) {
    Node *new_node = malloc(sizeof(Node));
    if (!new_node) {
        return false;
    }

    new_node->radius = NODE_RADIUS;
    new_node->child = NULL;
    new_node->parent = parent;

    parent->child = new_node;

    return true;
}

bool pendulum_init(Pendulum *pend) {
    Node *node = malloc(sizeof(Node));
    if (!node) {
        return false;
    }

    node->radius = NODE_RADIUS;
    node->x = WINDOW_WIDTH / 2;
    node->y = WINDOW_HEIGHT / 2;
    node->child = NULL;
    node->parent = NULL;

    pend->root = node;

    return true;
}
