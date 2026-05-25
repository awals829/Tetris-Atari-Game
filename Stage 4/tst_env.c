#include <stdio.h>
#include <osbind.h>
#include "model.h"
#include "raster.h"
#include "render.h"
#include "font.h"
#include "assets.h"
#include "events.h"

extern void clear_screen(unsigned char*);

/* I got tired of typing these */
#define SWEET_STEPPER while(!Cconis()); Cnecin();
#define UINTPTR (UINT16 *)
#define UCHARPTR (UINT8 *)
#define CLEAR_SCREEN clear_screen(UCHARPTR base)

/* Useful for coord etc printing */
/*
    for(i = 0; i < TETROMINO_SIZE; i++) {
        SWEET_STEPPER;
        printf("Tetromino Arena Coord for block[%d] are (%d, %d)\n", i, t.blocks[i].arenaX, t.blocks[i].arenaY);
        printf("Tetromino Screen Coord for block[%d] are (%d, %d)\n", i, t.blocks[i].screenX, t.blocks[i].screenY);
    }
    for(y = 0; y <= PLAY_AREA_MAX_Y; y++) {
        for(x = 0; x <= PLAY_AREA_MAX_X; x++) {
            if(p.arena[x][y].is_tetromino_piece) {
                SWEET_STEPPER;
                printf("Arena Has Tetromino At Array Coord: (%d, %d)\n", p.arena[x][y].arenaX, p.arena[x][y].arenaY);
                printf("Arena Has Tetromino At Screen Coord: (%d, %d)\n", p.arena[x][y].screenX, p.arena[x][y].screenY);
            }
        }
    }
*/

int x, y, i, j, num1, num2;;

/* THIS TEST ENVIRONMENT IS JUST FOR MODEL, EVENT, AND RASTER TRIAL RUNS */
void printTetrominoCoordAndArenaLocation(Tetromino *t, Play_area *p);

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
    Next_tetrom_display ntd;

    void *base = Physbase();

    initializeAllEvent(&p, &t, &sd, &tsl, &tss, &csl, &css, &lvlL, &LvlS, &ntd);
    renderScoreDisplay(&sd, UCHARPTR base);
    renderScoreDisplayValues(&tsl, &tss, &csl, &css, &lvlL, &LvlS, UCHARPTR base);

    SWEET_STEPPER;

    t.tetromino_type = 'J';

    initializeTetrominoSpawn(&t, t.tetromino_type);
    if(spawnTetrominoEvent(&t, &p)) {
        renderTetromino(&t, UINTPTR base);
    }
    renderPlayArea(&p, UCHARPTR base);
    renderNextTetrominoArea(&ntd, UCHARPTR base);
    renderBlocks(&p, UINTPTR base);

    SWEET_STEPPER;

    clearTetrominoRender(&t, UINTPTR base);
    shiftTetrominoDownEvent(&t, &p);
    renderTetromino(&t, UINTPTR base);
    renderBlocks(&p, UINTPTR base);


    SWEET_STEPPER;

    clearTetrominoRender(&t, UINTPTR base);
    rotateTetrominoCWiseEvent(&t, &p);
    renderTetromino(&t, UINTPTR base);
    renderBlocks(&p, UINTPTR base);

    SWEET_STEPPER;

    clearTetrominoRender(&t, UINTPTR base);
    rotateTetrominoCWiseEvent(&t, &p);
    renderTetromino(&t, UINTPTR base);
    renderBlocks(&p, UINTPTR base);

    SWEET_STEPPER;

    clearTetrominoRender(&t, UINTPTR base);
    rotateTetrominoCWiseEvent(&t, &p);
    renderTetromino(&t, UINTPTR base);
    renderBlocks(&p, UINTPTR base);

    SWEET_STEPPER;

    clearTetrominoRender(&t, UINTPTR base);
    rotateTetrominoCWiseEvent(&t, &p);
    renderTetromino(&t, UINTPTR base);
    renderBlocks(&p, UINTPTR base);

    SWEET_STEPPER;

    clearTetrominoRender(&t, UINTPTR base);
    rotateTetrominoCCWiseEvent(&t, &p);
    renderTetromino(&t, UINTPTR base);
    renderBlocks(&p, UINTPTR base);

    SWEET_STEPPER;

    clearTetrominoRender(&t, UINTPTR base);
    rotateTetrominoCCWiseEvent(&t, &p);
    renderTetromino(&t, UINTPTR base);
    renderBlocks(&p, UINTPTR base);

    SWEET_STEPPER;

    clearTetrominoRender(&t, UINTPTR base);
    rotateTetrominoCCWiseEvent(&t, &p);
    renderTetromino(&t, UINTPTR base);
    renderBlocks(&p, UINTPTR base);

    SWEET_STEPPER;

    clearTetrominoRender(&t, UINTPTR base);
    rotateTetrominoCCWiseEvent(&t, &p);
    renderTetromino(&t, UINTPTR base);
    renderBlocks(&p, UINTPTR base);

    SWEET_STEPPER;

    clearTetrominoRender(&t, UINTPTR base);
    p.arena[8][2].is_occupied = TRUE;
    shiftTetrominoRightEvent(&t, &p);
    renderTetromino(&t, UINTPTR base);
    renderBlocks(&p, UINTPTR base);

    SWEET_STEPPER;

    clearTetrominoRender(&t, UINTPTR base);
    shiftTetrominoRightEvent(&t, &p);
    renderTetromino(&t, UINTPTR base);
    renderBlocks(&p, UINTPTR base);

    SWEET_STEPPER;

    clearTetrominoRender(&t, UINTPTR base);
    shiftTetrominoRightEvent(&t, &p);
    renderTetromino(&t, UINTPTR base);
    renderBlocks(&p, UINTPTR base);

    SWEET_STEPPER;

    clearTetrominoRender(&t, UINTPTR base);
    shiftTetrominoRightEvent(&t, &p);
    renderTetromino(&t, UINTPTR base);
    renderBlocks(&p, UINTPTR base);

    SWEET_STEPPER;

    clearTetrominoRender(&t, UINTPTR base);
    shiftTetrominoRightEvent(&t, &p);
    renderTetromino(&t, UINTPTR base);
    renderBlocks(&p, UINTPTR base);

    SWEET_STEPPER;

    clearTetrominoRender(&t, UINTPTR base);
    shiftTetrominoRightEvent(&t, &p);
    renderTetromino(&t, UINTPTR base);
    renderBlocks(&p, UINTPTR base);

    SWEET_STEPPER;

    clearTetrominoRender(&t, UINTPTR base);
    rotateTetrominoCWiseEvent(&t, &p);
    renderTetromino(&t, UINTPTR base);
    renderBlocks(&p, UINTPTR base);
    
    SWEET_STEPPER;

    clearTetrominoRender(&t, UINTPTR base);
    shiftTetrominoRightEvent(&t, &p);
    renderTetromino(&t, UINTPTR base);
    renderBlocks(&p, UINTPTR base);
    
    SWEET_STEPPER;

    placeTetromino(&t, &p);
    clearTetrominoRender(&t, UINTPTR base);
    renderTetromino(&t, UINTPTR base);
    renderBlocks(&p, UINTPTR base);

    SWEET_STEPPER;

    randomize(&t);
    initializeTetrominoSpawn(&t, t.tetromino_type);

    clearTetrominoRender(&t, UINTPTR base);
    spawnTetrominoEvent(&t, &p);
    renderTetromino(&t, UINTPTR base);
    renderBlocks(&p, UINTPTR base);

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
