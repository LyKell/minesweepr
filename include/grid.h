#ifndef __GRILLE__
#define __GRILLE__

#include "../include/mines.h"

char** allocate_grid(int tailleX, int tailleY);
void fill_grid(char** grid, int tailleX, int tailleY);
void show_grid(char** grid, int tailleX, int tailleY);
void free_grid(char** grid, int tailleX, int tailleY);


#endif