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
            if (grid_secondary[i][j] == ' ') { // Case has been revealed
                if (grid[i][j] == '-') { // Case is empty
                    MLV_draw_filled_rectangle(j * CASES_SIZE, i * CASES_SIZE, CASES_SIZE, CASES_SIZE, MLV_COLOR_LIGHT_GRAY);
                } else if (grid[i][j] == 'x') { // Case is mine
                    MLV_draw_filled_rectangle(j * CASES_SIZE, i * CASES_SIZE, CASES_SIZE, CASES_SIZE, MLV_COLOR_RED);
                } else { // Case is number
                    string[0] = grid[i][j];
                    draw_number(i, j, string);
                }
            } else { // Case is hidden
                MLV_draw_filled_rectangle(j * CASES_SIZE, i * CASES_SIZE, CASES_SIZE, CASES_SIZE, MLV_COLOR_DARK_GRAY);
            }
        }
    }
}


void draw_number(int i, int j, char string[2]) {
    MLV_Color color;
    switch (string[0]) {
        case '1':
            color = MLV_COLOR_BLUE;
            break;
        case '2':
            color = MLV_COLOR_DARK_GREEN;
            break;
        case '3':
            color = MLV_COLOR_RED;
            break;
        case '4':
            color = MLV_COLOR_DARK_BLUE;
            break;
        case '5':
            color = MLV_COLOR_DARK_RED;
            break;
        case '6':
            color = MLV_COLOR_CYAN1;
            break;
        case '7':
            color = MLV_COLOR_BLACK;
            break;
        case '8':
            color = MLV_COLOR_GREY;
            break;
        default:
            color = MLV_COLOR_BLUE;
    }
    MLV_draw_text_box(j * CASES_SIZE, i * CASES_SIZE, CASES_SIZE, CASES_SIZE, string, 9, MLV_COLOR_LIGHT_GRAY, color, MLV_COLOR_LIGHT_GRAY, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
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


void draw_endgame(int sizeX, int sizeY) {
    int width, height;
    width = sizeY * CASES_SIZE;
    height = sizeX * CASES_SIZE;

    MLV_draw_text_box(0, 0, width, height, "BOOM !", 9, MLV_rgba(0, 0, 0, 0), MLV_COLOR_RED, MLV_rgba(255, 255, 255, 200), MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
}


void draw_window(char** grid, char** grid_secondary, int sizeX, int sizeY, int endgame) {
    draw_cases(grid, grid_secondary, sizeX, sizeY);
    draw_grid(sizeX, sizeY);
    if (endgame) {
        draw_endgame(sizeX, sizeY);
    }
    MLV_actualise_window();
}