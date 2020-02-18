#include <stdio.h>
#include <stdlib.h>
#include "../include/grid.h"


char** allocate_grid(int tailleX, int tailleY) {
    int i;
    char** grid = (char**) malloc(sizeof(char*) * tailleX);
    
    if (grid == NULL) {
        perror("Malloc error\n");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < tailleX; i++) {
        grid[i] = (char*) malloc(sizeof(char) * tailleY);
        if (grid[i] == NULL) {
            perror("Malloc error\n");
            exit(EXIT_FAILURE);
        }
    }

    return grid;
}


void fill_grid(char** grid, int tailleX, int tailleY) {
    int i, j;

    for (i = 0; i < tailleX; i++) {
        for (j = 0; j < tailleY; j++) {
            grid[i][j] = '-';
        }
    }
}


void show_grid(char** grid, int tailleX, int tailleY) {
    int i, j;
    for (i = 0; i < tailleX; i++) {
        for (j = 0; j < tailleY; j++) {
            printf("%c", grid[i][j]);
        }
        printf("\n");
    }
}


void free_grid(char** grid, int tailleX, int tailleY) {
    int i;
    for (i = 0; i < tailleX; i++) {
        free(grid[i]);
    }
    free(grid);
}


void complete_grid(char** grid, int tailleX, int tailleY) {
    int i, j, nb_mines = 0;
    for (i = 0; i < tailleX; i++) {
        for (j = 0; j < tailleY; j++) {
            if (grid[i][j] != 'x') {
                nb_mines = all_mines(grid, i, j);
            }
            if (nb_mines > 0 && grid[i][j] != 'x') {
                grid[i][j] = nb_mines + '0';
            }
        }
    }
}