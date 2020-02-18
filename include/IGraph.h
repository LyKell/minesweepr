#ifndef __IGRAPH__
#define __IGRAPH__

#include <MLV/MLV_all.h>
#include "../include/grid.h"
#include "../include/mines.h"
#include "../include/solver.h"

#define MAX_WIDTH 1280
#define MAX_HEIGHT 720

void create_window();
void draw_grid(char** grid, char** grid_secondary, int sizeX, int sizeY);
void draw_window(char** grid, char** grid_secondary, int sizeX, int sizeY);


#endif