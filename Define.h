#ifndef DEFINE_H_
    #define DEFINE_H_

#include <stdio.h>
#include <string.h>
#include <SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>

using namespace std;

#define PRINT_DEBUG true

#define WINDOW_TITLE "SDL Tutorial"
#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 600
#define TILE_SIZE 200

enum { PLAYER_X, PLAYER_O };

enum GRID_TYPE {
    GRID_TYPE_NONE = 0,
    GRID_TYPE_X,
    GRID_TYPE_O
};
#endif
