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
    char** grid;
    char** grid_secondary;
    int i = 0, x, y, difficulty;
    MLV_Keyboard_button touche;
    int mouseX, mouseY, realX, realY;

    srand(time(NULL));

    // do {
    //     printf("Chose the difficulty :\n1. Beginner\n2. Advanced\n3. Expert\n");
    //     scanf("%d", &difficulty);
    // } while (0 < difficulty || difficulty > 3);



    grid = allocate_grid(SIZE_X, SIZE_Y);
    fill_grid(grid, SIZE_X, SIZE_Y);

    grid_secondary = allocate_grid(SIZE_X, SIZE_Y);
    fill_grid(grid_secondary, SIZE_X, SIZE_Y);

    while (i < MINES) {
        x = rand() % SIZE_X;
        y = rand() % SIZE_Y;
        if (grid[x][y] == '-') {
            grid[x][y] = 'x';
            grid_secondary[x][y] = 'x';
            i++;
        }
    }
    show_grid(grid, SIZE_X, SIZE_Y);
    complete_grid(grid, SIZE_X, SIZE_Y);

    create_window();
    draw_window(grid, grid_secondary, SIZE_X, SIZE_Y);

    printf("\n");
    show_grid(grid, SIZE_X, SIZE_Y);

    do {
        MLV_wait_mouse(&mouseY, &mouseX);
        realX = mouseX / (MAX_HEIGHT / SIZE_X);
        realY = mouseY / (MAX_WIDTH / SIZE_Y);

        printf("%d %d : %d %d\n", mouseX, mouseY, realX, realY);

        reveal_cases(grid, grid_secondary, SIZE_X, SIZE_Y, realX, realY);
        draw_window(grid, grid_secondary, SIZE_X, SIZE_Y);


    } while (1);

    
    
    free_grid(grid, SIZE_X, SIZE_Y);
    MLV_free_window();

    return 0;
}
