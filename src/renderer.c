#include <SDL2/SDL.h>
#include "renderer.h"
#include "constants.h"

void set_color(SDL_Renderer *renderer, SDL_Color color) {
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    return;
}

void draw_background(SDL_Renderer *renderer) {
    set_color(renderer, COLOR_BACKGROUND);
    SDL_RenderClear(renderer);
    return;
}

void draw_node(SDL_Renderer *renderer, Node *node) {
    set_color(renderer, COLOR_NODE);
    const int r = node->radius;
    const int xc = node->x;
    const int yc = node->y;
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

void draw_rod(SDL_Renderer *renderer, Node *node) {
    Node *node_parent = node->parent;
    set_color(renderer, COLOR_ROD);
    SDL_RenderDrawLine(renderer, node->x, node->y, node_parent->x, node_parent->y);

    return;
}

void draw_pendulum(SDL_Renderer *renderer, Pendulum *pend) {
    draw_node(renderer, pend->root);

    Node *node = pend->root->child;

    while (node) {
        draw_node(renderer, node);
        draw_rod(renderer, node);
        node = node->child;
    }
    
    return;
}
