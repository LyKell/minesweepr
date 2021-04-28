#ifndef __GRILLE__
#define __GRILLE__

#include "../include/mines.h"
#include "../include/difficulty.h"

char** allocate_grid(int sizeX, int sizeY);
void fill_grid(char** grid, int sizeX, int sizeY);
void show_grid(char** grid, int sizeX, int sizeY);
void free_grid(char** grid, int sizeX, int sizeY);
void complete_grid(char** grid, int sizeX, int sizeY);

#endif