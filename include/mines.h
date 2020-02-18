#ifndef __MINES__
#define __MINES__

#define SIZE_X 16
#define SIZE_Y 32
#define MINES 80


int mines(char** grid, int x, int y, int nb_mines);
int all_mines(char** grid, int x, int y);


#endif