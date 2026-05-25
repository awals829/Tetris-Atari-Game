#include <stdio.h>
#include <stdlib.h>
#include <osbind.h>
#include "model.h"
#include "events.h"

#define SWEET_STEPPER while(!Cconis()); Cnecin();

int x, y, i, j, num1, num2;;

/* THIS TEST ENVIRONMENT IS JUST FOR MODEL, EVENT, AND RASTER TRIAL RUNS */
void printTetrominoCoordAndArenaLocation(Tetromino *t, Play_area *p);
void random_grid_occupation_fill(Play_area *p);
void random_grid_tetromino_fill(Play_area *p);

int main() {

    Block b;
    Tetromino t;
    Play_area p;
    Score_display sd;
    Top_score_label tsl;
    Top_score_string tss;
    Current_score_label csl;
    Current_score_string css;
    Level_label lvlL;
    Level_string LvlS;

    initializeAllEvent(&p, &t, &sd, &tsl, &tss, &csl, &css, &lvlL, &LvlS);

    t.tetromino_type = 'J';

    initializeTetrominoSpawn(&t, t.tetromino_type);
    printf("Tetromino type is %c\n", t.tetromino_type);

    SWEET_STEPPER;

    spawnTetrominoEvent(&t, &p);
    printTetrominoCoordAndArenaLocation(&t, &p);

    SWEET_STEPPER;

    printf("***** Shift Down Event #1 *****\n");
    shiftTetrominoDownEvent(&t, &p);
    printTetrominoCoordAndArenaLocation(&t, &p);

    SWEET_STEPPER;


    printf("***** Rotate CWise(x1) *****\n");

    rotateTetrominoCWiseEvent(&t, &p);

    SWEET_STEPPER;

    printTetrominoCoordAndArenaLocation(&t, &p);

    SWEET_STEPPER;

    printf("***** Placing Tetromino at last coordinates *****\n");
    placeTetromino(&t, &p);

    SWEET_STEPPER;

    /* Should only print the tetromino coordinates, but play area should not print */
    printTetrominoCoordAndArenaLocation(&t, &p);

    SWEET_STEPPER;

    randomize(&t);
    initializeTetrominoSpawn(&t, t.tetromino_type);
    printf("Tetromino type is %c\n", t.tetromino_type);

    SWEET_STEPPER;

    

    printf("**** End of tests *****\n");

    return 0;
}

void printTetrominoCoordAndArenaLocation(Tetromino *t, Play_area *p) {
    for(i = 0; i < TETROMINO_SIZE; i++) {
        printf("Tetromino block[%d] location is [%d, %d]\n", i, t->blocks[i].arenaX, t->blocks[i].arenaY);
    }

    SWEET_STEPPER;

    for(y = 0; y <= PLAY_AREA_MAX_Y; y++) {
        for(x = 0; x <= PLAY_AREA_MAX_X; x++) {
            if(p->arena[x][y].is_tetromino_piece) {
                printf("Arena Tetromino location is [%d, %d]\n", x, y);
            }
        }
    }
}

/* Generates A Randomly Filled Grid (Up To 5 Blocks) */
void random_grid_occupation_fill(Play_area *p) {
    int count = 0;
    printf("*** Random Grid Occupied Fill Executing ***\n");
    for(y = 0; y < 20 && count < 5; y++) {
        for(x = 0; x < 10 && count < 5; x++) {
            p->arena[x][y].is_occupied = rand() & 1;
            if(p->arena[x][y].is_occupied) {
                count++;
                SWEET_STEPPER;
                printf("Arena (%d, %d) is Occupied\n", x, y);
            }
        }
    }
    printf("Occupied Count = %d\n", count);
}

/* Generates A Randomly Filled Grid (Up To 5 Blocks) */
void random_grid_tetromino_fill(Play_area *p) {
    int count = 0;
    printf("*** Random Grid Tetromino Fill Executing ***\n");
    for(y = 0; y < 20 && count < 5; y++) {
        for(x = 0; x < 10 && count < 5; x++) {
            p->arena[x][y].is_tetromino_piece = rand() & 1;
            if(p->arena[x][y].is_tetromino_piece) {
                count++;
                SWEET_STEPPER;
                printf("Arena (%d, %d) Is A Tetromino\n", x, y);
            }
        }
    }
    printf("Tetromino Count = %d\n", count);
}
