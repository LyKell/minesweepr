#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <MLV/MLV_all.h>
#include "../include/grid.h"
#include "../include/mines.h"
#include "../include/IGraph.h"
#include "../include/difficulty.h"
#include "../include/solver.h"





int main(int argc, char const *argv[]) {
    char** grid;    // Grid containing the layout of the board
    char** grid_secondary;  // Grid containing data on what has been revealed
    int i = 0;
    int x, y;   // Coordinates to place the bombs
    int difficulty; // Difficulty of the game
    int mouseX, mouseY, realX, realY;   // Mouse position as real coordinates and grid coordinates
    int sizeX, sizeY, mines;    // Size of the board and number of mines
    int endgame = 0;

    srand(time(NULL));

    do {
        printf("Chose the difficulty :\n1. Beginner\n2. Advanced\n3. Expert\n");
        scanf("%d", &difficulty);

        set_difficulty(difficulty, &sizeX, &sizeY, &mines);
    } while (0 >= difficulty || difficulty > 3);



    grid = allocate_grid(sizeX, sizeY);
    fill_grid(grid, sizeX, sizeY);

    grid_secondary = allocate_grid(sizeX, sizeY);
    fill_grid(grid_secondary, sizeX, sizeY);

    while (i < mines) {
        x = rand() % sizeX;
        y = rand() % sizeY;
        if (grid[x][y] == '-') {
            grid[x][y] = 'x';
            grid_secondary[x][y] = 'x';
            i++;
        }
    }
    complete_grid(grid, sizeX, sizeY);

    create_window(sizeX, sizeY);
    draw_window(grid, grid_secondary, sizeX, sizeY, endgame);

    do {
        MLV_get_mouse_position(&mouseY, &mouseX);
        realX = mouseX / CASES_SIZE;
        realY = mouseY / CASES_SIZE;

        if (MLV_get_mouse_button_state(MLV_BUTTON_LEFT) == MLV_PRESSED) {
            reveal_cases(grid, grid_secondary, sizeX, sizeY, realX, realY);
            if (grid[realX][realY] == 'x') {
                endgame = 1;
            }
        } else if (MLV_get_mouse_button_state(MLV_BUTTON_RIGHT) == MLV_PRESSED) {
            // Hint
        }
        draw_window(grid, grid_secondary, sizeX, sizeY, endgame);

    } while (1);

    
    
    free_grid(grid, sizeX, sizeY);
    MLV_free_window();

    return 0;
}
