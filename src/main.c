#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <MLV/MLV_all.h>
#include "../include/difficulty.h"
#include "../include/grid.h"
#include "../include/hint.h"
#include "../include/IGraph.h"
#include "../include/mines.h"
#include "../include/solver.h"





int main(int argc, char const *argv[]) {
    char** grid;    // Grid containing the layout of the board
    char** grid_secondary;  // Grid containing data on what has been revealed
    char** empty_string;
    MLV_Input_box** empty_box;
    MLV_Mouse_button mouse_button;
    MLV_Button_state button_state;
    int difficulty; // Difficulty of the game
    int mouseX, mouseY; // Mouse position as real coordinates (X = abscissa, Y = ordinate)
    int gridX, gridY;   // Mouse position as real coordinates and grid coordinates (X = abscissa, Y = ordinate)
    int sizeX, sizeY, mines;    // Size of the board and number of mines
    int endgame = 0;
    int unicode;
    int init_done = 0;
    MLV_Keyboard_button sym;
    MLV_Keyboard_modifier mod;

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

    create_window(sizeX, sizeY);
    draw_window(grid, grid_secondary, sizeX, sizeY, endgame);

    do {
        MLV_wait_mouse(&mouseY, &mouseX);
        gridX = mouseX / CASES_SIZE;
        gridY = mouseY / CASES_SIZE;

        if (!init_done) {
            generate_mines(mines, sizeX, sizeY, gridX, gridY, grid, grid_secondary);
            complete_grid(grid, sizeX, sizeY);
            init_done = 1;
        }

        if (MLV_get_mouse_button_state(MLV_BUTTON_LEFT) == MLV_PRESSED) {
            reveal_cases(grid, grid_secondary, sizeX, sizeY, gridX, gridY);
            if (grid[gridX][gridY] == 'x') {
                endgame = 1;
            }
        } else if (MLV_get_mouse_button_state(MLV_BUTTON_RIGHT) == MLV_PRESSED) {
            set_hint(grid, grid_secondary, sizeX, sizeY, gridX, gridY);
        }

        draw_window(grid, grid_secondary, sizeX, sizeY, endgame);
        // show_grid(grid, sizeX, sizeY);
        // show_grid(grid_secondary, sizeX, sizeY);
        
        if (endgame) {
            break;
        }

    } while (1);

    MLV_wait_keyboard_or_mouse(&sym, &mod, &unicode, &mouseY, &mouseX);
    
    free_grid(grid, sizeX, sizeY);
    MLV_free_window();

    return 0;
}
