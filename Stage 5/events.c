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
 */

#include "events.h"


/********************************************/
/********** GENERAL GAME FUNCTIONS **********/
/********************************************/

/**
 * initializeAllEvent
 * 
 * Purpose: Initializes all game model components at the start of the game, 
 *          setting them to their default values. This includes setting up 
 *          the next tetromino type, initializing the play area, score display, 
 *          and other UI elements.
 * Input: model - A pointer to the Game_Model structure that 
 *                holds all game state information.
 * Output: None.
 * Assumptions: Assumes 'model' points to a valid Game_Model structure. 
 *              The function depends on various initialization functions 
 *              defined in other parts of the game code.
 */
void initializeAllEvent(Game_Model *model, long seed) {
    model->next.tetromino_type = randomize(&model->t, seed);
    model->isGameOver = FALSE;
    model->horizontalShift = 0;
    model->verticalShift = 0;
    model->rotate = 0;
    model->gameTime = 0;
    initPlayArea(&model->p);
    initializeTetrominoSpawn(&model->t, model->t.tetromino_type);
    initScoreDisplay(&model->sd);
    initNextTetromDisplay(&model->ntd);
    initTopScoreLabel(&model->tsl);
    initCurrentScoreLabel(&model->csl);
    initTopScoreString(&model->tss);
    initCurrentScoreString(&model->css);
    initLevelLabel(&model->lvlL);
    initLevelString(&model->lvlS);
}

/**
 * quit
 * 
 * Purpose: Placeholder for a future function to handle game quit events. 
 *          Currently, it does not have a defined behavior.
 * Input: None.
 * Output: Returns an integer value.
 * Assumptions: This function is a stub and may be implemented in 
 *              future to handle game the game quit event.
 */
int quit() {
    return 0;
}


/*****************************************/
/********** TETROMINO FUNCTIONS **********/
/*****************************************/

/**
 * spawnTetrominoEvent
 * 
 * Purpose: Attempts to spawn a new tetromino in the 
 *          play area at its designated starting position.
 * Input: model - A pointer to the Game_Model structure containing 
 *                the current game state.
 * Output: Returns 1 (true) if the tetromino was successfully spawned 
 *                 without any collisions; 0 (false) otherwise.
 * Assumptions: Assumes 'model' points to a valid Game_Model structure.
 */
int spawnTetrominoEvent(Game_Model *model) {
    int spawned = TRUE;
    int i;
    for(i = 0; i < TETROMINO_SIZE; i++) {
        if(!movementValidityChecker(&model->p, model->t.blocks[i].arenaX, model->t.blocks[i].arenaY)) {
            spawned = FALSE;
            break;
        }
    }
    if(spawned) {
        copyTetrominotoArena(&model->t, &model->p);
    }
    return spawned;
}

/**
 * shiftTetrominoDownEvent
 * 
 * Purpose: Moves the current tetromino one block down if 
 *          the move is valid (no collisions or boundary violations).
 * Input: model - A pointer to the Game_Model structure containing 
 *                the current game state.
 * Output: Returns 1 (true) if the tetromino was successfully moved down; 
 *                 0 (false) otherwise.
 * Assumptions: Assumes 'model' points to a valid Game_Model structure.
 */
int shiftTetrominoDownEvent(Game_Model *model) {
    int isShifted;
    clearTetrominoArena(&model->t, &model->p); /* Wipes original tetromino from the board */
    isShifted = shiftTetrominoDown(&model->t, &model->p);
    copyTetrominotoArena(&model->t, &model->p);
    return isShifted;
}

/**
 * shiftTetrominoLeftEvent
 * 
 * Purpose: Moves the current tetromino one block left if 
 *          the move is valid (no collisions or boundary violations).
 * Input: model - A pointer to the Game_Model structure containing 
 *                the current game state.
 * Output: Returns 1 (true) if the tetromino was successfully moved left; 
 *                 0 (false) otherwise.
 * Assumptions: Assumes 'model' points to a valid Game_Model structure.
 */
int shiftTetrominoLeftEvent(Game_Model *model) {
    int isShifted;
    clearTetrominoArena(&model->t, &model->p); /* Wipes original tetromino from the board */
    isShifted = shiftTetrominoLeft(&model->t, &model->p);
    copyTetrominotoArena(&model->t, &model->p);
    return isShifted;
}

/**
 * shiftTetrominoRightEvent
 * 
 * Purpose: Moves the current tetromino one block right if 
 *          the move is valid (no collisions or boundary violations).
 * Input: model - A pointer to the Game_Model structure containing 
 *                the current game state.
 * Output: Returns 1 (true) if the tetromino was successfully moved right; 
 *                 0 (false) otherwise.
 * Assumptions: Assumes 'model' points to a valid Game_Model structure.
 */
int shiftTetrominoRightEvent(Game_Model *model) {
    int isShifted;
    clearTetrominoArena(&model->t, &model->p); /* Wipes original tetromino from the board */
    isShifted = shiftTetrominoRight(&model->t, &model->p);
    copyTetrominotoArena(&model->t, &model->p);
    return isShifted;
}

/**
 * rotateTetrominoCWiseEvent
 * 
 * Purpose: Rotates the current tetromino 90 degrees clockwise on
 *          its origin block within the play area if the rotation is valid
 *          (no collisions or boundary violations).
 * Input: model - A pointer to the Game_Model structure containing 
 *                the current game state.
 * Output: Returns 1 (true) if the tetromino was successfully rotated; 
 *                 0 (false) otherwise.
 * Assumptions: Assumes 'model' points to a valid Game_Model structure.
 */
int rotateTetrominoCWiseEvent(Game_Model *model) {
    int rotatedEvent;
    if(model->t.tetromino_type != 'O') {
        clearTetrominoArena(&model->t, &model->p);
        rotatedEvent = rotateTetrominoCWise(&model->t, &model->p);
        copyTetrominotoArena(&model->t, &model->p);
    }
    return rotatedEvent;
}

/**
 * rotateTetrominoCCWiseEvent
 * 
 * Purpose: Rotates the current tetromino 90 degrees counter-clockwise on
 *          its origin block within the play area if the rotation is valid
 *          (no collisions or boundary violations).
 * Input: model - A pointer to the Game_Model structure containing 
 *                the current game state.
 * Output: Returns 1 (true) if the tetromino was successfully rotated; 
 *                 0 (false) otherwise.
 * Assumptions: Assumes 'model' points to a valid Game_Model structure.
 */
int rotateTetrominoCCWiseEvent(Game_Model *model) {
    int rotatedEvent;
    if(model->t.tetromino_type != 'O') {
        clearTetrominoArena(&model->t, &model->p);
        rotatedEvent = rotateTetrominoCCWise(&model->t, &model->p);
        copyTetrominotoArena(&model->t, &model->p);
    }
    return rotatedEvent;
}


/*************************************/
/********** SCORE FUNCTIONS **********/
/*************************************/

/**
 * scoreIncrementEvent
 * 
 * Purpose: Increments the current score based on the game level. 
 *          The amount added to the score depends on the current level.
 * Input: model - A pointer to the Game_Model structure containing the 
 *                game's score and level information.
 * Output: None. The function updates the current score in the Game_Model 
 *               structure based on the level.
 * Assumptions: Assumes a valid Game_Model pointer and that the level is 
 *              within the defined range (1-10).
 */
void scoreIncrementEvent(Game_Model *model) {
        switch (model->sd.level) {
        case 1: model->sd.current_score += SCORE_INCREMENT_L1; break;
        case 2: model->sd.current_score += SCORE_INCREMENT_L2; break;
        case 3: model->sd.current_score += SCORE_INCREMENT_L3; break;
        case 4: model->sd.current_score += SCORE_INCREMENT_L4; break;
        case 5: model->sd.current_score += SCORE_INCREMENT_L5; break;
        case 6: model->sd.current_score += SCORE_INCREMENT_L6; break;
        case 7: model->sd.current_score += SCORE_INCREMENT_L7; break;
        case 8: model->sd.current_score += SCORE_INCREMENT_L8; break;
        case 9: model->sd.current_score += SCORE_INCREMENT_L9; break;
        case 10: model->sd.current_score += SCORE_INCREMENT_L10; break;
        default: break;
    }
}

/**
 * incrementLevelEvent
 * 
 * Purpose: Increments the level value of the game in the models score display.
 * Input: model - A pointer to the Game_Model structure containing 
 *                the score display with the game's level information.
 * Output: None.
 * Assumptions: Assumes a valid Game_Model pointer. 
 *              The function does not check for a maximum level.
 */
void incrementLevelEvent(Game_Model *model) {
    model->sd.level += 1;
}

/**
 * setScoreDisplayValuesEvent
 * 
 * Purpose: Updates the top score if the current score exceeds it, 
 *          then updates the score display values for top score, 
 *          current score, and level. This function ensures that the background
 *          score display values reflect the most recent game state, including any 
 *          new high scores or level advancements.
 * Input: model - A pointer to the Game_Model structure containing all 
 *                relevant information for score and level display.
 * Output: None.
 * Assumptions: Assumes a valid Game_Model pointer. This function assumes 
 *              that the 'scoreToString' and 'levelToString' functions are 
 *              used to convert numerical values to string representations 
 *              for display purposes. The function also assumes that the 
 *              current score, top score, and level values are maintained 
 *              accurately in the score display game logic to compare to
 *              the running rendered scores.
 */
void setScoreDisplayValuesEvent(Game_Model *model) {

    /* Sets the top score equal to the current score if current score is greater */
    if (model->sd.current_score > model->sd.top_score) {
        model->sd.top_score = model->sd.current_score;
    }
    /* Sets the top score if it has incremented beyond the previous current top score value */
    if(model->sd.top_score > model->tss.top_score) {
        model->tss.top_score = model->sd.top_score;
        scoreToString(model->tss.top_score, &model->tss.top_score_num_string);
    }
    /* Sets the current score if it has incremented beyond the previous current score value */
    if(model->sd.current_score > model->css.current_score) {
        model->css.current_score =  model->sd.current_score;
        scoreToString(model->css.current_score, &model->css.current_score_num_string);
    }
    /* Sets the level if it has incremented beyond the previous level value */
    if(model->sd.level > model->lvlS.level) {
        model->lvlS.level = model->sd.level;
        levelToString(model->lvlS.level, &model->lvlS.level_num_string);
    }
}

void updateModel(Game_Model *model, long seed) {
    model->gameTime++;
    if(model->verticalShift == 1) {
        if(!shiftTetrominoDownEvent(model)){
            newTetromino(model, seed);
        }
        model->verticalShift = 0;
        model->gameTime = 0;
    } else if(model->horizontalShift == -1) {
        modelTetrominoCopyToTemp(model);
        shiftTetrominoLeftEvent(model);
        model->horizontalShift = 0;
    } else if(model->horizontalShift == 1) {
        modelTetrominoCopyToTemp(model);
        shiftTetrominoRightEvent(model);
        model->horizontalShift = 0;
    } else if(model->rotate == -1) {
        modelTetrominoCopyToTemp(model);
        rotateTetrominoCCWiseEvent(model);
        model->rotate = 0;
    } else if(model->rotate == 1) {
        modelTetrominoCopyToTemp(model);
        rotateTetrominoCWiseEvent(model);
        model->rotate = 0;
    } 
    if(model->gameTime >= model->p.gravity) {
        if(!shiftTetrominoDownEvent(model)) {
            newTetromino(model, seed);
        }
        model->verticalShift = 0;
        model->gameTime = 0;
    }
}

void newTetromino(Game_Model *model, long seed) {
    char nextType = model->next.tetromino_type;/* Save next type before assigning new one */
    placeTetromino(&model->t, &model->p);
    model->next.tetromino_type = randomize(&model->t, seed);
    initializeTetrominoSpawn(&model->t, nextType);
    model->isGameOver = !spawnTetrominoEvent(model);
}


