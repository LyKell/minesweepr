#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/mines.h"

const int dir[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};


void count_mines_per_cases(char** grid, int x, int y, int* mines, int sizeX, int sizeY) {
    if (!(x < 0 || x >= sizeX || y < 0 || y >= sizeY)) {
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


void generate_mines(int mines, int sizeX, int sizeY, int gridX, int gridY, char** grid, char** grid_secondary) {
    int i = 0;
    int x, y;
    int illegal = 0;
    while (i < mines) {
        x = rand() % sizeX;
        y = rand() % sizeY;
        
        if (grid[x][y] == '-' && x != gridX && y != gridY) {
            int k;
            for (k = 0; k < 8; k++) {
                if (x + dir[k][0] == gridX && y + dir[k][1] == gridY) {
                    illegal = 1;
                    break;
                }
            }
            
            if (illegal) {
                illegal = 0;
                continue;
            }
            
            grid[x][y] = 'x';
            grid_secondary[x][y] = 'x';
            i++;
        }
    }
}