#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/mines.h"

const int dir[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};


void count_mines_per_cases(char** grid, int x, int y, int* mines, int sizeX, int sizeY) {
    if (!(x < 0 || x >= sizeX || y < 0 || y >= sizeY)) {
        // printf("%c\n", grid[x][y]);
            if (grid[x][y] == 'x') {
            *mines += 1;
        }
    }
}


int all_mines(char** grid, int x, int y, int sizeX, int sizeY) {
    int mines = 0, i;
    
    for (i = 0; i < 8; i++) {
        count_mines_per_cases(grid, x + dir[i][0], y + dir[i][1], &mines, sizeX, sizeY);
    }

    return mines;
}