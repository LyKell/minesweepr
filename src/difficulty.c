#include <stdio.h>
#include <stdlib.h>
#include "../include/difficulty.h"


void set_difficulty(int difficulty, int* sizeX, int* sizeY, int* mines) {
    switch (difficulty) {
        case 1:
            *sizeX = BEGINNER_SIZE;
            *sizeY = BEGINNER_SIZE;
            *mines = BEGINNER_MINES;
            break;
        case 2:
            *sizeX = MEDIUM_SIZE;
            *sizeY = MEDIUM_SIZE;
            *mines = MEDIUM_MINES;
            break;
        case 3:
            *sizeX = EXPERT_SIZE_HEIGHT;
            *sizeY = EXPERT_SIZE_WIDTH;
            *mines = EXPERT_MINES;
            break;
        default:
            *sizeX = MEDIUM_SIZE;
            *sizeY = MEDIUM_SIZE;
            *mines = MEDIUM_MINES;
    }
}