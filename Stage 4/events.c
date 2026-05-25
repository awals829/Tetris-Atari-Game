/*
 * File: events.c
 * Author: Marusia Luciuk, Andrew Walsh 
 * Team Members: Marusia Luciuk, Andrew Walsh 
 * 
 * This file implements the key gameplay event mechanics for a Tetris-like game,
 * including rotation, movement, and line clearing within the play area. It
 * defines interactions between tetrominos (game pieces) and the play area,
 * such as dropping, shifting, and rotating tetrominos, clearing lines, and
 * updating the score and next piece display.
 * 
 * Documentation in header file.
 */

#include "events.h"


/********** GENERAL GAME FUNCTIONS **********/

void initializeAllEvent(Play_area *p, 
                    Tetromino *t, 
                    Score_display *sd, 
                    Top_score_label *tsl, 
                    Top_score_string *tss, 
                    Current_score_label *csl, 
                    Current_score_string *css,
                    Level_label *lvlL,
                    Level_string *lvlS,
                    Next_tetrom_display *ntd) {
    initPlayArea(p);
    initializeTetrominoSpawn(t, t->tetromino_type);
    initScoreDisplay(sd);
    initTopScoreLabel(tsl);
    initCurrentScoreLabel(csl);
    initTopScoreString(tss);
    initCurrentScoreString(css);
    initLevelLabel(lvlL);
    initLevelString(lvlS);
    initNextTetromDisplay(ntd);
}


int quit() {
}


/********** TETROMINO FUNCTIONS **********/

int spawnTetrominoEvent(Tetromino *t, Play_area *p) {
    int spawned = TRUE;
    int i;
    for(i = 0; i < TETROMINO_SIZE; i++) {
        if(!movementValidityChecker(p, t->blocks[i].arenaX, t->blocks[i].arenaY)) {
            spawned = FALSE;
            break;
        }
    }
    if(spawned) {
        copyTetrominotoArena(t, p);
    }
    return spawned;
}


int shiftTetrominoDownEvent(Tetromino *t, Play_area *p) {
    int isShifted;
    clearTetrominoArena(t, p); /* Wipes original tetromino from the board */
    isShifted = shiftTetrominoDown(t, p);
    copyTetrominotoArena(t, p);
    return isShifted;
}


int shiftTetrominoLeftEvent(Tetromino *t, Play_area *p) {
    int isShifted;
    clearTetrominoArena(t, p); /* Wipes original tetromino from the board */
    isShifted = shiftTetrominoLeft(t, p);
    copyTetrominotoArena(t, p);
    return isShifted;
}


int shiftTetrominoRightEvent(Tetromino *t, Play_area *p) {
    int isShifted;
    clearTetrominoArena(t, p); /* Wipes original tetromino from the board */
    isShifted = shiftTetrominoRight(t, p);
    copyTetrominotoArena(t, p);
    return isShifted;
}


int rotateTetrominoCWiseEvent(Tetromino *t, Play_area *p) {
    int rotatedEvent;
    if(t->tetromino_type != 'O') {
        clearTetrominoArena(t, p);
        rotatedEvent = rotateTetrominoCWise(t, p);
        copyTetrominotoArena(t, p);
    }
    return rotatedEvent;
}


int rotateTetrominoCCWiseEvent(Tetromino *t, Play_area *p) {
    int rotatedEvent;
    if(t->tetromino_type != 'O') {
        clearTetrominoArena(t, p);
        rotatedEvent = rotateTetrominoCCWise(t, p);
        copyTetrominotoArena(t, p);
    }
    return rotatedEvent;
}


/********** SCORE FUNCTIONS **********/

void scoreIncrementEvent(Score_display *sd) {
        switch (sd->level) {
        case 1: sd->current_score += SCORE_INCREMENT_L1; break;
        case 2: sd->current_score += SCORE_INCREMENT_L2; break;
        case 3: sd->current_score += SCORE_INCREMENT_L3; break;
        case 4: sd->current_score += SCORE_INCREMENT_L4; break;
        case 5: sd->current_score += SCORE_INCREMENT_L5; break;
        case 6: sd->current_score += SCORE_INCREMENT_L6; break;
        case 7: sd->current_score += SCORE_INCREMENT_L7; break;
        case 8: sd->current_score += SCORE_INCREMENT_L8; break;
        case 9: sd->current_score += SCORE_INCREMENT_L9; break;
        case 10: sd->current_score += SCORE_INCREMENT_L10; break;
        default: break;
    }
}


void incrementLevelEvent(Score_display *sd) {
    sd->level += 1;
}


void setScoreDisplayValuesEvent(Score_display *sd, Top_score_string *tss, Current_score_string *css, Level_string *lvlS) {
    if(sd->top_score > tss->top_score) {
        tss->top_score = sd->top_score;
        scoreToString(tss->top_score, tss->top_score_num_string);
    }
    if(sd->current_score > css->current_score) {
        css->current_score = sd->current_score;
        scoreToString(css->current_score, css->current_score_num_string);
    }
    if(sd->level > lvlS->level) {
        lvlS->level = sd->level;
        levelToString(lvlS->level, lvlS->level_num_string);
    }
}


void updateTopScoreEvent(Score_display *sd) {
    if (sd->current_score > sd->top_score) {
        sd->top_score = sd->current_score;   
    }
}
