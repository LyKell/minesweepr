#include <stdio.h>
#include <stdlib.h>
#include "../include/grid.h"


char** allocate_grid(int sizeX, int sizeY) {
    int i;
    char** grid = (char**) malloc(sizeof(char*) * sizeX);
    
    if (grid == NULL) {
        perror("Malloc error\n");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < sizeX; i++) {
        grid[i] = (char*) malloc(sizeof(char) * sizeY);
        if (grid[i] == NULL) {
            perror("Malloc error\n");
            exit(EXIT_FAILURE);
        }
    }

    return grid;
}


void fill_grid(char** grid, int sizeX, int sizeY) {
    int i, j;

    for (i = 0; i < sizeX; i++) {
        for (j = 0; j < sizeY; j++) {
            grid[i][j] = '-';
        }
    }
}


void show_grid(char** grid, int sizeX, int sizeY) {
    int i, j;
    for (i = 0; i < sizeX; i++) {
        for (j = 0; j < sizeY; j++) {
            printf("%c", grid[i][j]);
        }
        printf("\n");
    }
}


void free_grid(char** grid, int sizeX, int sizeY) {
    int i;
    for (i = 0; i < sizeX; i++) {
        free(grid[i]);
    }
    free(grid);
}


void complete_grid(char** grid, int sizeX, int sizeY) {
    int i, j, nb_mines = 0;
    for (i = 0; i < sizeX; i++) {
        for (j = 0; j < sizeY; j++) {
            if (grid[i][j] != 'x') {
                nb_mines = all_mines(grid, i, j, sizeX, sizeY);
            }
            if (nb_mines > 0 && grid[i][j] != 'x') {
                grid[i][j] = nb_mines + '0';
            }
        }
    }
}