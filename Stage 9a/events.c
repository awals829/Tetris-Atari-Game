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
void initializeAllEvent(Game_Model *model) {
    initModelValues(model);
    setNextTetrominoEvent(model);
    setNewTetrominoEvent(model);
    initPlayArea(model);
    initScoreDisplay(model);
    initNextTetromDisplay(model);
    initTopScoreLabel(model);
    initCurrentScoreLabel(model);
    initTopScoreString(model);
    initCurrentScoreString(model);
    initLevelLabel(model);
    initLevelString(model);
    setScoresAndLevel(model);
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
        copyTetrominotoToPlayArea(&model->t, &model->p);
    }
    return spawned;
}


/**
 * setNewTetrominoEvent
 * 
 * Purpose: Sets up the new gameplay Tetromino from the next Tetromino.
 * Input: model - A pointer to the Game_Model structure containing 
 *                the current game state.
 * Output: None
 * Assumptions: Assumes 'model' points to a valid Game_Model structure.
 */
void setNewTetrominoEvent(Game_Model *model) {
    copyTetromino(&model->next, &model->temp);
    setNextTetrominoEvent(model);
    copyTetromino(&model->temp, &model->t); /* Sets next Tetromino info into gameplay Tetromino */
    initializeAllTetrominoSpawn(&model->t, model->t.tetromino_type);
}


/**
 * setNextTetrominoEvent
 * 
 * Purpose: Sets up the next gameplay Tetromino for the next Tetromino object in the Game Model.
 * Input: model - A pointer to the Game_Model structure containing 
 *                the current game state.
 * Output: None
 * Assumptions: Assumes 'model' points to a valid Game_Model structure.
 */
void setNextTetrominoEvent(Game_Model *model) {
    model->next.tetromino_type = randomize(&model->t); /* Sets next Tetromino */
    initializeAllTetrominoSpawn(&model->next, model->next.tetromino_type);
}


/**
 * placeTetrominoEvent
 * 
 * Purpose: Sets the Tetromino location in the Play Area object as occupied
 *          space. This is different from spawning a Tetromino in play.
 * Input: model - A pointer to the Game_Model structure containing 
 *                the current game state.
 * Output: None
 * Assumptions: Assumes 'model' points to a valid Game_Model structure.
 */
void placeTetrominoEvent(Game_Model *model) {
    placeTetromino(&model->t, &model->p);
}


/**
 * shiftTetrominoDownEvent
 * 
 * Purpose: Moves the current tetromino one block down if 
 *          the move is valid (no collisions or boundary violations).
 *          This function will remove the tetromino from the board,
 *          attempt to move, and copy the resulting changed or unchanged
 *          tetromino
 * Input: model - A pointer to the Game_Model structure containing 
 *                the current game state.
 * Output: Returns 1 (true) if the tetromino was successfully moved down; 
 *                 0 (false) otherwise.
 * Assumptions: Assumes 'model' points to a valid Game_Model structure.
 */
int shiftTetrominoDownEvent(Game_Model *model) {
    int isShifted;
    clearTetrominoFromPlayArea(&model->t, &model->p); /* Wipes original tetromino from the board */
    isShifted = shiftTetrominoDown(&model->t, &model->p); /* Shifting Attempted Or Completed */
    copyTetrominotoToPlayArea(&model->t, &model->p); /* Copies Tetromino with or without changes back to the board */
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
    clearTetrominoFromPlayArea(&model->t, &model->p); /* Wipes original tetromino from the board */
    isShifted = shiftTetrominoLeft(&model->t, &model->p); /* Shifting Attempted Or Completed */
    copyTetrominotoToPlayArea(&model->t, &model->p); /* Copies Tetromino with or without changes back to the board */
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
    clearTetrominoFromPlayArea(&model->t, &model->p); /* Wipes original tetromino from the board */
    isShifted = shiftTetrominoRight(&model->t, &model->p); /* Shifting Attempted Or Completed */
    copyTetrominotoToPlayArea(&model->t, &model->p); /* Copies Tetromino with or without changes back to the board */
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
    if(model->t.tetromino_type != 'O') { /* Square "O-Shapes", do not rotate */
        clearTetrominoFromPlayArea(&model->t, &model->p); /* Wipes original tetromino from the board */
        rotatedEvent = rotateTetrominoCWise(&model->t, &model->p); /* Rotation Attempted Or Completed */
        copyTetrominotoToPlayArea(&model->t, &model->p); /* Copies Tetromino with or without changes back to the board */
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
    if(model->t.tetromino_type != 'O') { /* Square "O-Shapes", do not rotate */
        clearTetrominoFromPlayArea(&model->t, &model->p); /* Wipes original tetromino from the board */
        rotatedEvent = rotateTetrominoCCWise(&model->t, &model->p); /* Rotation Attempted Or Completed */
        copyTetrominotoToPlayArea(&model->t, &model->p); /* Copies Tetromino with or without changes back to the board */
    }
    return rotatedEvent;
}


/*****************************************/
/********** PLAY AREA FUNCTIONS **********/
/*****************************************/

/**
 * clearLinesEvent
 * 
 * Purpose: Clears lines, updates scores, and updates level based on total cleared lines. 
 * Input: model - A pointer to the Game_Model structure containing 
 *                the current game state.
 * Output: None.
 * Assumptions: Assumes 'model' points to a valid Game_Model structure.
 */
void clearLinesEvent(Game_Model *model) {
    int x, y, count = 0;
    for(y = PLAY_AREA_MAX_Y; y >= PLAY_AREA_MIN_Y; y--) {
        if(isRowFull(model, y)) {
            model->totalClearedLinesCounter++;
            clearRow(model, y);
            incrementScore(model);
            y++;
        }
    }
}


/**
 * speedIncreaseEvent
 * 
 * Purpose: Decrements the Game Model objects gravity for the default 
 *          Tetromino falling rate per second. This increases the synchronous
 *          falling rate.
 * Input: model - A pointer to the Game_Model structure containing 
 *                the current game state.
 * Output: None.
 * Assumptions: Assumes 'model' points to a valid Game_Model structure.
 */
void speedIncreaseEvent(Game_Model *model) {
    if(model->p.gravity > (DEFAULT_PLAY_AREA_GRAVITY - 10)) { /* Max level is 10, so max decrements are 10 */
        model->p.gravity--;
    }
}


/*************************************/
/********** SCORE FUNCTIONS **********/
/*************************************/

/**
 * incrementLevelEvent
 * 
 * Purpose: Increments the Game Model objects level and increments
 *          the game speed via the speedIncreaseEvent().
 * Input: model - A pointer to the Game_Model structure containing 
 *                the current game state.
 * Output: None.
 * Assumptions: Assumes 'model' points to a valid Game_Model structure.
 */
void incrementLevelEvent(Game_Model *model) {
    if(model->totalClearedLinesCounter >= LINE_CLEAR_COUNT_LEVEL_INCREASE) {
        /* Could Grandfather any excess lines over to new iteration in the future */
        model->totalClearedLinesCounter = 0;
        incrementLevel(model);
        speedIncreaseEvent(model);
    }
}


/******************************************/
/********** GAME MODEL FUNCTIONS **********/
/******************************************/

/**
 * updateModelEvent
 * 
 * Purpose: Updates the model state based on asynchronous and synchronous
 *          gameplay event flags.
 * Input: model - A pointer to the Game_Model structure containing 
 *                the current game state.
 * Output: None.
 * Assumptions: Assumes 'model' points to a valid Game_Model structure.
 */
void updateModelEvent(Game_Model *model) {
    int spawned;
    model->gameTime++;
    /* Asynchronous Model Update Events */
    if(model->verticalShift == 1) {         /* If there has been a downward shift requested */
        if(!shiftTetrominoDownEvent(model)) {
            placeTetrominoEvent(model);     /* Place the Tetromino if it can't shift down */
            setNewTetrominoEvent(model);    /* Setup a new gameplay Tetromino */
            clearLinesEvent(model);         /* Clear any lines that have been filled */
            updateTopScore(model);          /* Update the Top score if top score is exceeded */
            incrementLevelEvent(model);     /* Increment the game level as needed */
            setScoresAndLevel(model);       /* Set the visual scores and level to reflect any changes */
            spawned = spawnTetrominoEvent(model);
        }
        model->verticalShift = 0;           /* Reset the vertical shift flag to avoid repeats unless requested */
        model->gameTime = 0;                /* Reset the model gameTime flag to avoid an immediate natural drop occuring after a drop */

    } else if(model->horizontalShift == -1) {/* Shift left request handler */
        shiftTetrominoLeftEvent(model);
        model->horizontalShift = 0;
    } else if(model->horizontalShift == 1) { /* Shift right request handler */
        shiftTetrominoRightEvent(model);
        model->horizontalShift = 0;
    } else if(model->rotate == -1) {         /* Rotate Counterclockwise request handler */
        rotateTetrominoCCWiseEvent(model);
        model->rotate = 0;
    } else if(model->rotate == 1) {          /* Rotate Clockwise request handler */
        rotateTetrominoCWiseEvent(model);
        model->rotate = 0;
    }

    /* Synchronous Model Update Events */
    if(model->gameTime >= model->p.gravity) {
        if(!shiftTetrominoDownEvent(model)) {
            placeTetrominoEvent(model);     /* Place the Tetromino if it can't shift down */
            setNewTetrominoEvent(model);    /* Setup a new gameplay Tetromino */
            clearLinesEvent(model);         /* Clear any lines that have been filled */
            updateTopScore(model);          /* Update the Top score if top score is exceeded */
            incrementLevelEvent(model);     /* Increment the game level as needed */
            setScoresAndLevel(model);       /* Set the visual scores and level to reflect any changes */
            spawned = spawnTetrominoEvent(model);
        }
        model->verticalShift = 0;           /* Reset the vertical shift flag to avoid repeats unless requested */
        model->gameTime = 0;                /* Reset the gameTime flag to avoid an immediate natural drop occuring after a drop */
    }
    if(!spawned) {                          /* If a Tetromino piece could not spawn, set game over flag */
        model->isGameOver = TRUE;
    }
}
