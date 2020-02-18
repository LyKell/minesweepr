#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/grid.h"
#include "../include/mines.h"
#include "../include/IGraph.h"
#include "../include/solver.h"





int main(int argc, char const *argv[]) {
    char** grid;
    int i = 0, x, y;

    srand(time(NULL));

    grid = allocate_grid(TAILLE_X, TAILLE_Y);
    fill_grid(grid, TAILLE_X, TAILLE_Y);

    while (i < MINES) {
        x = rand() % TAILLE_X;
        y = rand() % TAILLE_Y;
        if (grid[x][y] == '-') {
            grid[x][y] = 'x';
            i++;
        }
    }
    show_grid(grid, TAILLE_X, TAILLE_Y);
    complete_grid(grid, TAILLE_X, TAILLE_Y);

    printf("\n");
    show_grid(grid, TAILLE_X, TAILLE_Y);
    free_grid(grid, TAILLE_X, TAILLE_Y);

    return 0;
}
