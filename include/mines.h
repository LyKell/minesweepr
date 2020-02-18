#ifndef __MINES__
#define __MINES__

#define TAILLE_X 16
#define TAILLE_Y 32
#define MINES 99

typedef struct position {
    int x;
    int y;
} Position;

int mines(char** grid, int x, int y, int nb_mines);
int all_mines(char** grid, int x, int y);


#endif