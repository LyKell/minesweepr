#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/mines.h"


void count_mines(char** grid, int x, int y, int* nb_mines) {
    if (!(x < 0 || x >= SIZE_X || y < 0 || y >= SIZE_Y)) {
        // printf("%c\n", grid[x][y]);
            if (grid[x][y] == 'x') {
            *nb_mines += 1;
        }
    }
}


int all_mines(char** grid, int x, int y) {
    int nb_mines = 0;
    
    count_mines(grid, x - 1, y - 1, &nb_mines);
    count_mines(grid, x - 1, y, &nb_mines);
    count_mines(grid, x - 1, y + 1, &nb_mines);
    count_mines(grid, x, y - 1, &nb_mines);
    count_mines(grid, x, y + 1, &nb_mines);
    count_mines(grid, x + 1, y - 1, &nb_mines);
    count_mines(grid, x + 1, y, &nb_mines);
    count_mines(grid, x + 1, y + 1, &nb_mines);

    return nb_mines;
}