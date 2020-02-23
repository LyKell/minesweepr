#include <stdio.h>
#include <stdlib.h>
#include <MLV/MLV_all.h>
#include "../include/IGraph.h"


void create_window() {
    MLV_create_window("Minesweeper", "Minesweeper", MAX_WIDTH, MAX_HEIGHT);
}


void draw_cases(char** grid, char** grid_secondary, int sizeX, int sizeY) {
    int i, j;
    int caseX = MAX_HEIGHT / SIZE_X;
    int caseY = MAX_WIDTH / SIZE_Y;
    char string[2] = "\0";
    for (i = 0; i < sizeX; i++) {
        for (j = 0; j < sizeY; j++) {
            if (grid_secondary[i][j] == ' ') {
                if (grid[i][j] == '-') {
                    MLV_draw_filled_rectangle(j * caseY, i * caseX, caseY, caseX, MLV_COLOR_LIGHT_GRAY);
                } else if (grid[i][j] == 'x') {
                    MLV_draw_filled_rectangle(j * caseY, i * caseX, caseY, caseX, MLV_COLOR_RED);
                } else {
                    string[0] = grid[i][j];
                    MLV_draw_text_box(j * caseY, i * caseX, caseY, caseX, string, 9, MLV_COLOR_GRAY60, MLV_COLOR_BLUE, MLV_COLOR_GRAY60, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
                }
            } else {
                MLV_draw_filled_rectangle(j * caseY, i * caseX, caseY, caseX, MLV_COLOR_DARK_GRAY);
            }
        }
    }
}


void draw_grid(int sizeX, int sizeY) {
    int i;
    int caseX = MAX_HEIGHT / SIZE_X;
    int caseY = MAX_WIDTH / SIZE_Y;
    for (i = 0; i < sizeY; i++) {
        MLV_draw_line(i * caseY, 0, i * caseY, MAX_HEIGHT, MLV_COLOR_BLACK);
    }
    for (i = 0; i < sizeX; i++) {
        MLV_draw_line(0, i * caseX, MAX_WIDTH, i * caseX, MLV_COLOR_BLACK);
    }
}


void draw_window(char** grid, char** grid_secondary, int sizeX, int sizeY) {
    draw_cases(grid, grid_secondary, sizeX, sizeY);
    draw_grid(sizeX, sizeY);
    MLV_actualise_window();
}