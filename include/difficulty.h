#ifndef __DIFFICULTY__
#define __DIFFICULTY__


#define BEGINNER_SIZE 8
#define MEDIUM_SIZE 16
#define EXPERT_SIZE_HEIGHT 16
#define EXPERT_SIZE_WIDTH 30
#define BEGINNER_MINES 10
#define MEDIUM_MINES 40
#define EXPERT_MINES 99

void set_difficulty(int difficulty, int* sizeX, int* sizeY, int* mines);

#endif