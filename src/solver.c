#include <stdio.h>
#include <stdlib.h>
#include "../include/solver.h"

/*
Algorithme "devoiler"
1. Si la case est un chiffre, on l'affiche et on arrête

2. Sinon, pour chaque direction :
    Si la case n'est pas affichée, devoiler()
    Sinon, regarder la case suivante

*/


void reveal_cases(char** grid, char** grid_secondary, int sizeX, int sizeY, int x, int y) {
    grid_secondary[x][y] = ' ';
    if (!(grid[x][y] == '-' || grid[x][y] == x)) {  // The case contains a number
        return;
    } else {
        int i;
        for (i = 0; i < 8; i++) {
            if (0 <= x + dir[i][0] && x + dir[i][0] < sizeX && 0 <= y + dir[i][1] && y + dir[i][1] < sizeY) {
                if (grid_secondary[x + dir[i][0]][y + dir[i][1]] == '-') {
                    reveal_cases(grid, grid_secondary, sizeX, sizeY, x + dir[i][0], y + dir[i][1]);
                }
            }
        }
    }
}