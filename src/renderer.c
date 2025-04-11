#include <SDL2/SDL.h>
#include "renderer.h"

void draw_background(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    return;
}

void draw_sample_circle(SDL_Renderer *renderer, int xc, int yc, int r) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    int d = r * 2;

    int x = r;
    int y = 0;
    int tx = 1;
    int ty = 1;
    int error = tx - d;

    while (x >= y) {
        SDL_Point points[] = {
            {xc + x, yc - y},
            {xc + x, yc + y},
            {xc - x, yc - y},
            {xc - x, yc + y},
            {xc + y, yc - x},
            {xc + y, yc + x},
            {xc - y, yc - x},
            {xc - y, yc + x}
        };

        SDL_RenderDrawLines(renderer, points, 8);

        if (error <= 0) {
            y++;
            error += ty;
            ty += 2;
        }

        if (error > 0) {
            x--;
            tx += 2;
            error += tx - d;
        }
    }
    return;
}

void draw_node(SDL_Renderer *renderer, Node *node) {
    draw_sample_circle(renderer, node->x, node->y, node->radius);
    
    return;
}

void draw_arm(SDL_Renderer *renderer, Node *node) {
    Node *node_parent = node->parent;
    SDL_SetRenderDrawColor(renderer, 215, 215, 215, 255);
    SDL_RenderDrawLine(renderer, node->x, node->y, node_parent->x, node_parent->y);

    return;
}

void draw_pendulum(SDL_Renderer *renderer, Pendulum *pend) {
    draw_node(renderer, pend->root);

    Node *node = pend->root->child;

    while (node) {
        draw_node(renderer, node);
        draw_arm(renderer, node);
        node = node->child;
    }
    
    return;
}
