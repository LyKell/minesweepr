#ifndef __MINES__
#define __MINES__

#include "../include/difficulty.h"

extern const int dir[8][2];

void count_mines_per_cases(char** grid, int x, int y, int* mines, int sizeX, int sizeY);
int all_mines(char** grid, int x, int y, int sizeX, int sizeY);
void generate_mines(int mines, int sizeX, int sizeY, int gridX, int gridY, char** grid, char** grid_secondary);

#endif