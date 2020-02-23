#include <stdio.h>
#include <stdlib.h>
#include <MLV/MLV_all.h>
#include "../include/IGraph.h"


void create_window(int sizeX, int sizeY) {
    MLV_create_window("Minesweeper", "Minesweeper", sizeY * CASES_SIZE, sizeX * CASES_SIZE);
}


void draw_cases(char** grid, char** grid_secondary, int sizeX, int sizeY) {
    int i, j;
    char string[2] = "\0";
    for (i = 0; i < sizeX; i++) {
        for (j = 0; j < sizeY; j++) {
            if (grid_secondary[i][j] == ' ') {
                if (grid[i][j] == '-') {
                    MLV_draw_filled_rectangle(j * CASES_SIZE, i * CASES_SIZE, CASES_SIZE, CASES_SIZE, MLV_COLOR_LIGHT_GRAY);
                } else if (grid[i][j] == 'x') {
                    MLV_draw_filled_rectangle(j * CASES_SIZE, i * CASES_SIZE, CASES_SIZE, CASES_SIZE, MLV_COLOR_RED);
                } else {
                    string[0] = grid[i][j];
                    MLV_draw_text_box(j * CASES_SIZE, i * CASES_SIZE, CASES_SIZE, CASES_SIZE, string, 9, MLV_COLOR_GRAY60, MLV_COLOR_BLUE, MLV_COLOR_GRAY60, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
                }
            } else {
                MLV_draw_filled_rectangle(j * CASES_SIZE, i * CASES_SIZE, CASES_SIZE, CASES_SIZE, MLV_COLOR_DARK_GRAY);
            }
        }
    }
}


void draw_grid(int sizeX, int sizeY) {
    int i;
    for (i = 0; i < sizeY; i++) {
        MLV_draw_line(i * CASES_SIZE, 0, i * CASES_SIZE, sizeX * CASES_SIZE, MLV_COLOR_BLACK);
    }
    for (i = 0; i < sizeX; i++) {
        MLV_draw_line(0, i * CASES_SIZE, sizeY * CASES_SIZE, i * CASES_SIZE, MLV_COLOR_BLACK);
    }
}


void draw_window(char** grid, char** grid_secondary, int sizeX, int sizeY) {
    draw_cases(grid, grid_secondary, sizeX, sizeY);
    draw_grid(sizeX, sizeY);
    MLV_actualise_window();
}