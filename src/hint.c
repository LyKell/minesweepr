#include "../include/hint.h"


void set_hint(char **grid, char **grid_secondary, int sizeX, int sizeY, int x, int y) {
    if (grid_secondary[x][y] != ' ') {
        switch (grid_secondary[x][y]) {
            case '!':
                grid_secondary[x][y] = '?';
                break;
            case '?':
                grid_secondary[x][y] = grid[x][y];
                break;
            default:
                grid_secondary[x][y] = '!';
        }
    }
}