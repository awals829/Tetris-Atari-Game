/*
 * File: model.h
 * Author: Marusia Luciuk, Andrew Walsh
 * Team Members: Marusia Luciuk, Andrew Walsh
 *
 * The definitions file for the functions used 
 * to manipulate and instantiate the objects
 * in the tetris game.
 */

#include <stdlib.h>
#include "model.h"
#include "string.h"

/**
 * initModelValues
 * 
 * Purpose: Initializes all the non-object variable fields in a Game_Model object.
 * Input: model - pointer to a Game_Model object.
 *        seed  - integer number to help generate a random Tetromino object type.
 * Output: None.
 * Assumptions: Assumes a valid pointer to a Game_Model object.
 */
void initModelValues(Game_Model *model) {
    model->next.tetromino_type = randomize(&model->t);
    model->totalClearedLinesCounter = 0;
    model->scoreIncrementCounter = 0;
    model->isGameOver = FALSE;
    model->horizontalShift = FALSE;
    model->verticalShift = FALSE;
    model->rotate = FALSE;
    model->gameTime = 0;
}


/********************************************************************/
/********** GRID COORD & SCREEN COORD CONVERSION FUNCTIONS **********/
/********************************************************************/

/**
 * arenaX_to_screenX
 * 
 * Purpose: Converts arena array x-coordinate to screen x-coordinate 
 *          for a Block.
 * Input: b - A pointer to the Block to convert.
 * Output: None.
 * Assumptions: Assumes a valid pointer to a Block.
 */
int arenaX_to_screenX(Block b) {
    return (b.arenaX << 4) + BLOCK_PLAY_START_SCREENX;
}


/**
 * arenaY_to_screenY
 * 
 * Purpose: Converts arena array y-coordinate to screen y-coordinate 
 *          for a Block.
 * Input: b - A pointer to the Block to convert.
 * Output: None.
 * Assumptions: Assumes a valid pointer to a Block.
 */
int arenaY_to_screenY(Block b) {
    return (b.arenaY << 4) + BLOCK_PLAY_START_SCREENY;
}


/**
 * screenX_to_arenaX
 * 
 * Purpose: Converts screen x-coordinate to arena array x-coordinate for a Block.
 * Input: b - A pointer to the Block to convert.
 * Output: None.
 * Assumptions: Assumes a valid pointer to a Block.
 */
int screenX_to_arenaX(Block b) {
    return (b.screenX - BLOCK_PLAY_START_SCREENX) >> 4;
}


/**
 * screenY_to_arenaY
 * 
 * Purpose: Converts screen y-coordinate to arena array y-coordinate for a Block.
 * Input: b - A pointer to the Block to convert.
 * Output: None.
 * Assumptions: Assumes a valid pointer to a Block.
 */
int screenY_to_arenaY(Block b) {
    return (b.screenY - BLOCK_PLAY_START_SCREENY) >> 4;
}


/*************************************/
/********** BLOCK FUNCTIONS **********/
/*************************************/

/**
 * init_block
 * 
 * Purpose: Initializes a block with given grid coordinates.
 * Input: b - A pointer to the block to initialize.
 *        arenaX - The grid x-coordinate.
 *        arenaY - The grid y-coordinate.
 * Output: None.
 * Assumptions: Assumes a valid pointer to a block and valid coordinates.
 */
void initBlock(Block *b, int arenaX, int arenaY) {
    b->arenaX = arenaX;
    b->arenaY = arenaY;
    b->screenX = arenaX_to_screenX(*b);
    b->screenY = arenaY_to_screenY(*b);
    b->is_occupied = 0;
    b->is_tetromino_piece = 0;
}


/**
 * isArenaXViable
 * 
 * Purpose: Checks if the given x-coordinate is within the playable area of the arena array.
 * Input: arenaX - The arena array x-coordinate to check.
 * Output: Returns 1 if the x-coordinate is within the playable area, 0 otherwise.
 */
int isArenaXViable(int arenaX) {
    return (arenaX >= PLAY_AREA_MIN_X && arenaX <= PLAY_AREA_MAX_X);
}


/**
 * isArenaYViable
 * 
 * Purpose: Checks if the given y-coordinate is within the playable area of the arena array.
 * Input: arenaX - The arena array y-coordinate to check.
 * Output: Returns 1 if the y-coordinate is within the playable area, 0 otherwise.
 */
int isArenaYViable(int arenaY) {
    return (arenaY >= PLAY_AREA_MIN_Y && arenaY <= PLAY_AREA_MAX_Y);
}


/**
 * isPositionOccupied
 * 
 * Purpose: Checks if the specified position in the play area is occupied.
 * Input: p - A pointer to the play area.
 *        arenaX - The arena array x-coordinate of the position to check.
 *        arenaY - The arena array y-coordinate of the position to check.
 * Output: Returns 1 if the position is occupied, 0 otherwise.
 * Assumptions: Assumes a valid arena x and y array coordinates.
 */
int isPositionOccupied(Play_area *p, int arenaX, int arenaY) {
    return (p->arena[arenaX][arenaY].is_occupied);
}


/**
 * isPositionTetromino
 * 
 * Purpose: Checks if the specified position in the play area is a tetromino block.
 * Input: p - A pointer to the play area.
 *        arenaX - The arena array x-coordinate of the position to check.
 *        arenaY - The arena array y-coordinate of the position to check.
 * Output: Returns 1 if the position is occupied, 0 otherwise.
 * Assumptions: Assumes a valid arena x and y array coordinates.
 */
int isPositionTetromino(Play_area *p, int arenaX, int arenaY) {
    return (p->arena[arenaX][arenaY].is_tetromino_piece);
}


/*****************************************/
/********** TETROMINO FUNCTIONS **********/
/*****************************************/

/** randomize
 * 
 * Purpose: Cycles through an array of tetromino shape types to assign to a tetromino.
 * Input: tetronimo t - A tetronimo object to assigne the shape to.
 * Assumptions: Assumes a valid pointer to a tetromino object.
 */
char randomize(Tetromino *t) {
    static int index;
    char randomChar;
    char blocks[7] = {'J', 'S', 'T', 'O', 'Z', 'L', 'I'};
    index = (int)(rand() % 7);
    randomChar = blocks[index];
    return randomChar;
}


/**
 * copyTetromino
 * 
 * Purpose: Copies all Tetromino object values from one Tetromino object to another.
 *          This does not change the values of the 'from' tetromino.
 * Input: from - Tetromino object to copy data from.
 *          to - Tetromino object to copy data to.
 * Output: None.
 * Assumptions: Assumes a valid pointer to two Tetromino objects.
 */
void copyTetromino(Tetromino *from, Tetromino *to) {
    int i;
    for(i = 0; i < TETROMINO_SIZE; i++) {
        to->blocks[i].arenaX = from->blocks[i].arenaX;
        to->blocks[i].screenX = from->blocks[i].screenX;
        to->blocks[i].arenaY = from->blocks[i].arenaY;
        to->blocks[i].screenY = from->blocks[i].screenY;
        to->blocks[i].is_occupied = from->blocks[i].is_occupied;
        to->blocks[i].is_tetromino_piece = from->blocks[i].is_tetromino_piece;
    }
    to->tetromino_type = from->tetromino_type;
}


/** clearTetrominoValues
 * 
 * Purpose: Sets a tetromino values to be cleared (set to zero) for all
 *          its block coordinates. This tetromino will no longer hold
 *          any game values.
 * Input: tetronimo t - A tetronimo structure to clear previous coordinate
 *                      and other values from.
 */
void clearTetrominoValues(Tetromino *t) {
    int i;
    t->tetromino_type = ' ';
    for (i = 0; i < TETROMINO_SIZE; i++) {
        t->blocks[i].arenaX = 0;
        t->blocks[i].arenaY = 0;
        t->blocks[i].screenX = 0;
        t->blocks[i].screenY = 0;
        t->blocks[i].is_occupied = FALSE;
        t->blocks[i].is_tetromino_piece = FALSE;
    }
}


/**
 * copyTetrominotoToPlayArea
 * 
 * Purpose: Copies the specified tetromino blocks to the play area, 
 *          marking them as occupied and as part of a tetromino.
 * Input: t - A pointer to the tetromino to be copied.
 *        p - A pointer to the play area where the tetromino will be copied.
 * Output: None.
 * Assumptions: Assumes valid pointers for both the tetromino and the play area.
 */
void copyTetrominotoToPlayArea(Tetromino *t, Play_area *p) {
    int i;
    for(i = 0; i < TETROMINO_SIZE; i++) {
        p->arena[t->blocks[i].arenaX][t->blocks[i].arenaY].is_occupied = TRUE;
        p->arena[t->blocks[i].arenaX][t->blocks[i].arenaY].is_tetromino_piece = TRUE;
    }
}


/**
 * clearTetrominoFromPlayArea
 * 
 * Purpose: Clears the specified tetromino blocks from the play area, 
 *          marking them as unoccupied and not part of a tetromino.
 * Input: t - A pointer to the tetromino to be cleared.
 *        p - A pointer to the play area from which the tetromino will be cleared.
 * Output: None.
 * Assumptions: Assumes valid pointers for both the tetromino and the play area.
 * 
 * Note: Useful for clearing a copy of the old tetromino positions, which can be stored
 *       in the Game_Model Tetromino temp object, before changes are made to the original.
 */
void clearTetrominoFromPlayArea(Tetromino *t, Play_area *p) {
    int i;
    for(i = 0; i < TETROMINO_SIZE; i++) {
        p->arena[t->blocks[i].arenaX][t->blocks[i].arenaY].is_occupied = FALSE;
        p->arena[t->blocks[i].arenaX][t->blocks[i].arenaY].is_tetromino_piece = FALSE;
    }
}


/**
 * placeTetromino
 * 
 * Purpose: Places the tetromino in the play area, marking its blocks as occupied 
 *          but not as part of a tetromino (useful for when the tetromino is locked in place).
 * Input: t - A pointer to the tetromino to be placed.
 *        p - A pointer to the play area where the tetromino will be placed.
 * Output: None.
 * Assumptions: Assumes valid pointers for both the tetromino and the play area.
 */
void placeTetromino(Tetromino *t, Play_area *p) {
    int i;
    for(i = 0; i < TETROMINO_SIZE; i++) {
        p->arena[t->blocks[i].arenaX][t->blocks[i].arenaY].is_occupied = TRUE;
        p->arena[t->blocks[i].arenaX][t->blocks[i].arenaY].is_tetromino_piece = FALSE;
    }
}


/**
 * shiftTetrominoDown
 * 
 * Purpose: Moves the tetromino one block down within the play area if the movement is valid.
 * Input: t - A pointer to the tetromino to move.
 *        p - A pointer to the play area where the tetromino resides.
 * Output: Returns 1 (true) if the tetromino was successfully moved down; 
 *         0 (false) if the movement was invalid due to collision or boundary limits.
 * Assumptions: Assumes valid pointers for both the tetromino and the play area.
 */
int shiftTetrominoDown(Tetromino *t, Play_area *p) {
    int i, nextX, nextY, next_occupied, next_tetromino;
    int validMove = 1;
    Tetromino tempTetromino;
    tempTetromino = *t;

    for (i = 0; i < TETROMINO_SIZE; i++) {
        nextX = tempTetromino.blocks[i].arenaX;
        nextY = tempTetromino.blocks[i].arenaY + 1;   
        validMove = movementValidityChecker(p, nextX, nextY);
        if(!validMove) break; /* Collision found on block shift, exit loop */
        shift(&tempTetromino, nextX, nextY, i);
    }
    if(validMove) {
        *t = tempTetromino;
    }
    return validMove;
}


/**
 * shiftTetrominoLeft
 * 
 * Purpose: Moves the tetromino one block left within the play area if the movement is valid.
 * Input: t - A pointer to the tetromino to move.
 *        p - A pointer to the play area where the tetromino resides.
 * Output: Returns 1 (true) if the tetromino was successfully moved left; 
 *         0 (false) if the movement was invalid due to collision or boundary limits.
 * Assumptions: Assumes valid pointers for both the tetromino and the play area.
 */
int shiftTetrominoLeft(Tetromino *t, Play_area *p) {
    int i, nextX, nextY, next_occupied, next_tetromino;
    int validMove = 1;
    Tetromino tempTetromino;
    tempTetromino = *t;

    for (i = 0; i < TETROMINO_SIZE; i++) {
        nextX = tempTetromino.blocks[i].arenaX - 1;
        nextY = tempTetromino.blocks[i].arenaY;        
        validMove = movementValidityChecker(p, nextX, nextY);
        if(!validMove) break; /* Collision found on block shift, exit loop */
        shift(&tempTetromino, nextX, nextY, i);
    }
    if(validMove) {
        *t = tempTetromino;
    }
    return validMove;
}


/**
 * shiftTetrominoRight
 * 
 * Purpose: Moves the tetromino one block right within the play area if the movement is valid.
 * Input: t - A pointer to the tetromino to move.
 *        p - A pointer to the play area where the tetromino resides.
 * Output: Returns 1 (true) if the tetromino was successfully moved right;
 *         0 (false) if the movement was invalid due to collision or boundary limits.
 * Assumptions: Assumes valid pointers for both the tetromino and the play area.
 */
int shiftTetrominoRight(Tetromino *t, Play_area *p) {
    int i, nextX, nextY, next_occupied, next_tetromino;
    int validMove = 1;
    Tetromino tempTetromino;
    tempTetromino = *t;

    for (i = 0; i < TETROMINO_SIZE; i++) {
        nextX = tempTetromino.blocks[i].arenaX + 1;
        nextY = tempTetromino.blocks[i].arenaY;      
        validMove = movementValidityChecker(p, nextX, nextY);
        if(!validMove) break; /* Collision found on block shift, exit loop */
        shift(&tempTetromino, nextX, nextY, i);
    }
    if(validMove) {
        *t = tempTetromino;
    }
    return validMove;
}


/**
 * rotateTetrominoCWise
 * 
 * Purpose: Rotates the tetromino 90 degrees clockwise.
 * Input: t - A pointer to the tetromino.
 *        p - A pointer to the play area.
 * Output: Returns 1 if the rotation is valid, 0 otherwise.
 * Assumptions: Assumes valid tetromino and play area pointers.
 */
int rotateTetrominoCWise(Tetromino *t, Play_area *p) {
    int isValid = TRUE; /* Use unsigned char for boolean logic */
    int i; /* Loop counter */
    int relativeX, relativeY; /* Relative positions */
    int newX, newY; /* New positions after rotation */
    Tetromino tempTetromino; /* Using a copy of the tetromino parameter to avoid changes until determined valid */
    tempTetromino = *t;
    /* Calculate new positions using a copy of the tetromino and check validity for non-origin blocks */
    for (i = 1; i < TETROMINO_SIZE; i++) { /* Start from 1, skipping the origin block */
        relativeX = tempTetromino.blocks[i].arenaX - tempTetromino.blocks[0].arenaX;
        relativeY = tempTetromino.blocks[i].arenaY - tempTetromino.blocks[0].arenaY;

        /* Calculate new position using 90-degree clockwise rotation formula */
        newX = tempTetromino.blocks[0].arenaX - relativeY;
        newY = tempTetromino.blocks[0].arenaY + relativeX;

        isValid = movementValidityChecker(p, newX, newY);
        if(!isValid) break; /* Collision found on block rotation, exit loop */
        
        /* Store new positions in temp for potential valid deep copy. */
        shift(&tempTetromino, newX, newY, i);
    }
    /* Apply new positions if all are valid */
    if (isValid) {
        *t = tempTetromino; /* Assigning copy back to parameter tetromino if changes are valid */
    }
    return isValid;
}


/**
 * rotateTetrominoCCWise
 * 
 * Purpose: Rotates the tetromino 90 degrees counter-clockwise.
 * Input: t - A pointer to the tetromino.
 *        p - A pointer to the play area.
 * Output: Returns 1 if the rotation is valid, 0 otherwise.
 * Assumptions: Assumes valid tetromino and play area pointers.
 */
int rotateTetrominoCCWise(Tetromino *t, Play_area *p) {
    int isValid = TRUE; /* Use unsigned char for boolean logic */
    int i; /* Loop counter */
    int relativeX, relativeY; /* Relative positions */
    int newX, newY; /* New positions after rotation */
    Tetromino tempTetromino; /* Using a copy of the tetromino parameter to avoid changes until determined valid */
    tempTetromino = *t;
    /* Calculate new positions using a copy of the tetromino and check validity for non-origin blocks */
    for (i = 1; i < TETROMINO_SIZE; i++) { /* Start from 1, skipping the origin block */
        relativeX = tempTetromino.blocks[i].arenaX - tempTetromino.blocks[0].arenaX;
        relativeY = tempTetromino.blocks[i].arenaY - tempTetromino.blocks[0].arenaY;

        /* Calculate new position using 90-degree counterclockwise rotation formula */
        newX = tempTetromino.blocks[0].arenaX + relativeY;
        newY = tempTetromino.blocks[0].arenaY - relativeX;

        isValid = movementValidityChecker(p, newX, newY);
        if(!isValid) break; /* Collision found on block rotation, exit loop */

        /* Store new positions in temp for potential valid deep copy. */
        shift(&tempTetromino, newX, newY, i);
    }
    /* Apply new positions if all are valid */
    if (isValid) {
        *t = tempTetromino; /* Assigning copy back to parameter tetromino if changes are valid */
    }
    return isValid;
}


/**
 * shift
 * 
 * Purpose: Moves the tetromino one block right within the play area if the movement is valid.
 * Input: t - A pointer to the tetromino to move.
 *        nextX - Next X arena coordinate for the block. (0 - 9)
 *        nextY - Next Y arena coordinate for the block. (0 - 19)
 *        i - selected block index value in the tetromino.
 * Output: None.
 * Assumptions: Assumes a valid pointer to a tetrmonio and an i value from 0 to 3.
 */
void shift(Tetromino *t, int nextX, int nextY, int i) {
    t->blocks[i].arenaX = nextX;
    t->blocks[i].arenaY = nextY;
    t->blocks[i].screenX = arenaX_to_screenX(t->blocks[i]);
    t->blocks[i].screenY = arenaY_to_screenY(t->blocks[i]);
}


/**
 * initializeTetrominoSpawn
 * 
 * Purpose: Initializes the specified tetromino to the char type's
 *          predesigned arena array spawn coordinates.
 * Input: t - A pointer to the tetromino to be initialized.
 *        type - The character representing the type of tetromino to 
 *               initialize ('I', 'O', 'T', 'S', 'Z', 'L', 'J').
 * Output: None.
 * Assumptions: Assumes a valid pointer for the tetromino and 
 *              a valid character for the tetromino type.
 */
void initializeAllTetrominoSpawn(Tetromino *t, char type) {
    int i;
    switch (type) {
        case 'T': initializeTetrominoTshape(t); t->tetromino_type = 'T'; break;
        case 'L': initializeTetrominoLshape(t); t->tetromino_type = 'L'; break;
        case 'J': initializeTetrominoJshape(t); t->tetromino_type = 'J'; break;
        case 'S': initializeTetrominoSshape(t); t->tetromino_type = 'S'; break;
        case 'Z': initializeTetrominoZshape(t); t->tetromino_type = 'Z'; break;
        case 'I': initializeTetrominoIshape(t); t->tetromino_type = 'I'; break;
        case 'O': initializeTetrominoOshape(t); t->tetromino_type = 'O'; break;
        default: initializeTetrominoOshape(t); t->tetromino_type = 'T'; break;
    }

    for(i = 0; i < TETROMINO_SIZE; i++) {
        initBlock(&t->blocks[i], t->blocks[i].arenaX, t->blocks[i].arenaY);
        /* 
            Initialize blocks as part of the Tetromino as initBlock() 
            sets these values to FALSE initially. 
        */
        t->blocks[i].is_occupied = TRUE;
        t->blocks[i].is_tetromino_piece = TRUE;
    }
}


/**
 * initializeTetrominoTshape
 * 
 * Purpose: Initializes a tetromino object to the T-shape spawn coordinates.
 * Input: t - A pointer to the tetromino to be initialized.
 * Output: None.
 * Assumptions: Assumes a valid pointer for the tetromino.
 */
void initializeTetrominoTshape(Tetromino *t) {
    int i;
    /* Set up in arean is ( x , y )*/
    /* Set Up Origin Block Spawn Point */
    t->blocks[0].arenaX = 4; t->blocks[0].arenaY = 0;

    /* Set Up Block 1 Spawn Point */
    t->blocks[1].arenaX = 3; t->blocks[1].arenaY = 0;

    /* Set Up Block 2 Spawn Point */
    t->blocks[2].arenaX = 5; t->blocks[2].arenaY = 0;

    /* Set Up Block 3 Spawn Point */
    t->blocks[3].arenaX = 4; t->blocks[3].arenaY = 1;
}


/**
 * initializeTetrominoLshape
 * 
 * Purpose: Initializes a tetromino object to the L-shape spawn coordinates.
 * Input: t - A pointer to the tetromino to be initialized.
 * Output: None.
 * Assumptions: Assumes a valid pointer for the tetromino.
 */
void initializeTetrominoLshape(Tetromino *t) {
    int i;
    /* Set up in arean is ( x , y )*/
    /* Set Up Origin Block Spawn Point */
    t->blocks[0].arenaX = 4; t->blocks[0].arenaY = 0;

    /* Set Up Block 1 Spawn Point */
    t->blocks[1].arenaX = 3; t->blocks[1].arenaY = 1;

    /* Set Up Block 2 Spawn Point */
    t->blocks[2].arenaX = 3; t->blocks[2].arenaY = 0;

    /* Set Up Block 3 Spawn Point */
    t->blocks[3].arenaX = 5; t->blocks[3].arenaY = 0;
}


/**
 * initializeTetrominoJshape
 * 
 * Purpose: Initializes a tetromino object to the J-shape spawn coordinates.
 * Input: t - A pointer to the tetromino to be initialized.
 * Output: None.
 * Assumptions: Assumes a valid pointer for the tetromino.
 */
void initializeTetrominoJshape(Tetromino *t) {
    int i;
    /* Set up in arean is ( x , y )*/
    /* Set Up Origin Block Spawn Point */
    t->blocks[0].arenaX = 4; t->blocks[0].arenaY = 0;

    /* Set Up Block 1 Spawn Point */
    t->blocks[1].arenaX = 3; t->blocks[1].arenaY = 0;

    /* Set Up Block 2 Spawn Point */
    t->blocks[2].arenaX = 5; t->blocks[2].arenaY = 0;

    /* Set Up Block 3 Spawn Point */
    t->blocks[3].arenaX = 5; t->blocks[3].arenaY = 1;
}


/**
 * initializeTetrominoSshape
 * 
 * Purpose: Initializes a tetromino object to the S-shape spawn coordinates.
 * Input: t - A pointer to the tetromino to be initialized.
 * Output: None.
 * Assumptions: Assumes a valid pointer for the tetromino.
 */
void initializeTetrominoSshape(Tetromino *t) {
    int i;
    /* Set up in arean is ( x , y )*/
    /* Set Up Origin Block Spawn Point */
    t->blocks[0].arenaX = 4; t->blocks[0].arenaY = 0;

    /* Set Up Block 1 Spawn Point */
    t->blocks[1].arenaX = 3; t->blocks[1].arenaY = 1;

    /* Set Up Block 2 Spawn Point */
    t->blocks[2].arenaX = 4; t->blocks[2].arenaY = 1;

    /* Set Up Block 3 Spawn Point */
    t->blocks[3].arenaX = 5; t->blocks[3].arenaY = 0;
}


/**
 * initializeTetrominoZshape
 * 
 * Purpose: Initializes a tetromino object to the Z-shape spawn coordinates.
 * Input: t - A pointer to the tetromino to be initialized.
 * Output: None.
 * Assumptions: Assumes a valid pointer for the tetromino.
 */
void initializeTetrominoZshape(Tetromino *t) {
    int i;
    /* Set up in arean is ( x , y )*/
    /* Set Up Origin Block Spawn Point */
    t->blocks[0].arenaX = 4; t->blocks[0].arenaY = 0;

    /* Set Up Block 1 Spawn Point */
    t->blocks[1].arenaX = 3; t->blocks[1].arenaY = 0;

    /* Set Up Block 2 Spawn Point */
    t->blocks[2].arenaX = 4; t->blocks[2].arenaY = 1;

    /* Set Up Block 3 Spawn Point */
    t->blocks[3].arenaX = 5; t->blocks[3].arenaY = 1;
}


/**
 * initializeTetrominoIshape
 * 
 * Purpose: Initializes a tetromino object to the I-shape spawn coordinates.
 * Input: t - A pointer to the tetromino to be initialized.
 * Output: None.
 * Assumptions: Assumes a valid pointer for the tetromino.
 */
void initializeTetrominoIshape(Tetromino *t) {
    int i;
    /* Set up in arean is ( x , y )*/
    /* Set Up Origin Block Spawn Point */
    t->blocks[0].arenaX = 4; t->blocks[0].arenaY = 0;

    /* Set Up Block 1 Spawn Point */
    t->blocks[1].arenaX = 3; t->blocks[1].arenaY = 0;

    /* Set Up Block 2 Spawn Point */
    t->blocks[2].arenaX = 5; t->blocks[2].arenaY = 0;

    /* Set Up Block 3 Spawn Point */
    t->blocks[3].arenaX = 6; t->blocks[3].arenaY = 0;
}


/**
 * initializeTetrominoOshape
 * 
 * Purpose: Initializes a tetromino object to the O-shape spawn coordinates.
 * Input: t - A pointer to the tetromino to be initialized.
 * Output: None.
 * Assumptions: Assumes a valid pointer for the tetromino.
 */
void initializeTetrominoOshape(Tetromino *t) {
    int i;
    /* Set up in arean is ( x , y )*/
    /* Set Up Origin Block Spawn Point */
    t->blocks[0].arenaX = 4; t->blocks[0].arenaY = 0;

    /* Set Up Block 1 Spawn Point */
    t->blocks[1].arenaX = 5; t->blocks[1].arenaY = 0;

    /* Set Up Block 2 Spawn Point */
    t->blocks[2].arenaX = 4; t->blocks[2].arenaY = 1;

    /* Set Up Block 3 Spawn Point */
    t->blocks[3].arenaX = 5; t->blocks[3].arenaY = 1;
}


/**
 * movementValidityChecker
 * 
 * Purpose: Checks if moving to the specified position is a valid move.
 * Input: p - A pointer to the play area.
 *        arenaX - The array x-coordinate of the position to check.
 *        arenaY - The array y-coordinate of the position to check.
 * Output: Returns 1 if the move is valid, 0 otherwise.
 * Assumptions: The final position is the only position to check.
 */
int movementValidityChecker(Play_area *p, int arenaX, int arenaY) {
    int valid = TRUE;
    int next_occupied, next_tetromino;
    if(isArenaXViable(arenaX) && isArenaYViable(arenaY)) {
        next_occupied = isPositionOccupied(p, arenaX, arenaY);
        next_tetromino = isPositionTetromino(p, arenaX, arenaY);
        if ((!next_tetromino || !next_occupied) && next_occupied) {
            valid = FALSE;
        }
    } else {
        valid = FALSE;
    }
    return valid;
}


/*****************************************/
/********** PLAY AREA FUNCTIONS **********/
/*****************************************/

/**
 * initPlayArea
 * 
 * Purpose: Initializes the play area with pre-defined values.
 * Input: model - A pointer to the Game_Model object containing a
 *                Play_area object to initialize.
 * Output: None.
 * Assumptions: Assumes a valid pointer to a Game_Model object and 
 *              access to pre-defined values in header file.
 */
void initPlayArea(Game_Model *model) {
    int x, y;
    model->p.screenX = PLAY_AREA_START_SCREENX;
    model->p.screenY = PLAY_AREA_START_SCREENY;
    model->p.width = PLAY_AREA_WIDTH_SCREEN;
    model->p.height = PLAY_AREA_HEIGHT_SCREEN;
    model->p.gravity = DEFAULT_PLAY_AREA_GRAVITY;

    for(y = 0; y <= PLAY_AREA_MAX_Y; y++) {
        for(x = 0; x <= PLAY_AREA_MAX_X; x++) {
            model->p.arena[x][y].is_occupied = FALSE;
            model->p.arena[x][y].is_tetromino_piece = FALSE;
            initBlock(&model->p.arena[x][y], x, y);
        }
    }
}


/**
 * isRowFull
 * 
 * Purpose: Assesses if the specfied row in the Game_Model's Play_area 
 *          is full or not. Returns TRUE if each column in the row
 *          is set to occupied, otherwise it returns FALSE.
 * Input: model - A pointer to the Game_Model object containing an
 *                initialized Play_area object.
 *        yRow - The 2D array arena value for the y coordinate row
 *               to check.
 * Output: True (1) or FALSE (0) int value.
 * Assumptions: Assumes a valid pointer to a Game_Model object, and
 *              a valid y-coordinate within the bounds of the Play_area.
 */
int isRowFull(Game_Model *model, int yRow) {
    int x,isFull;
    isFull = TRUE;
    for(x = 0; x <= PLAY_AREA_MAX_X; x++) {
        if(model->p.arena[x][yRow].is_occupied == FALSE) {
            isFull = FALSE;
            break;
        }
    }
    return isFull;
}


/**
 * clearRow
 * 
 * Purpose: Clears an entire specified Play_area row (y-coordinate) 
 *          of occupied blocks.
 * Input: model - A pointer to the Game_Model object containing an
 *                initialized Play_area object.
 *        yRow - The 2D array arena value for the y coordinate row
 *               to check.
 * Output: None.
 * Assumptions: Assumes a valid pointer to a Game_Model object, and
 *              a valid y-coordinate within the bounds of the Play_area.
 */
void clearRow(Game_Model *model, int yRow) {
    int x, y;
    for(y = yRow; y > PLAY_AREA_MIN_Y; y--) {
        for(x = 0; x <= PLAY_AREA_MAX_X; x++) { 
            model->p.arena[x][y].is_occupied = model->p.arena[x][y-1].is_occupied;
        }
    }
}


/*************************************/
/********** SCORE FUNCTIONS **********/
/*************************************/

/**
 * initScoreDisplay
 * 
 * Purpose: Initializes the score display with default values.
 * Input: sd - A pointer to the score display to initialize.
 * Output: None.
 * Assumptions: Assumes a valid Game_Model pointer containing a 
 *              score display object and access to pre-defined values 
 *              in header file.
 */
void initScoreDisplay(Game_Model *model) {
    model->sd.current_score = 0UL;
    model->sd.top_score = 0UL; /* Goal to load top score from prior run if possible */
    model->sd.screenX = SCORE_DISPLAY_SCREENX;
    model->sd.screenY = SCORE_DISPLAY_SCREENY;
    model->sd.width = SCORE_DISPLAY_WIDTH_PX;
    model->sd.height = SCORE_DISPLAY_HEIGHT_PX;
    model->sd.level = 1; /* Starting level is 1 */
}


/**
 * initTopScoreLabel
 * 
 * Purpose: Initializes the top score label with default values.
 * Input: tsl - A pointer to the top score label to initialize.
 * Output: None.
 * Assumptions: Assumes a valid Game_Model pointer containing a 
 *              top score label object and access to pre-defined values 
 *              in header file.
 */
void initTopScoreLabel(Game_Model *model) {
    model->tsl.screenX = TOP_SCORE_LABEL_SCREENX;
    model->tsl.screenY = TOP_SCORE_LABEL_SCREENY;
    model->tsl.string_length = 9;
    strcpy(model->tsl.top_score_label_string, "TOP SCORE");
}


/**
 * initCurrentScoreLabel
 * 
 * Purpose: Initializes the current score label with default values.
 * Input: csl - A pointer to the current score label to initialize.
 * Output: None.
 * Assumptions: Assumes a valid Game_Model pointer containing a 
 *              current score label object and access to pre-defined values 
 *              in header file.
 */
void initCurrentScoreLabel(Game_Model *model) {
    model->csl.screenX = CURRENT_SCORE_LABEL_SCREENX;
    model->csl.screenY = CURRENT_SCORE_LABEL_SCREENY;
    model->csl.string_length = 5;
    strcpy(model->csl.current_score_label_string, "SCORE");
}


/**
 * initTopScoreString
 * 
 * Purpose: Initializes the top score string display with default values.
 * Input: tss - A pointer to the top score string object to initialize.
 * Output: None.
 * Assumptions: Assumes a valid Game_Model pointer containing a 
 *              top score string object and access to pre-defined values 
 *              in header file.
 */
void initTopScoreString(Game_Model *model) {
    model->tss.screenX = TOP_SCORE_STRING_SCREENX;
    model->tss.screenY = TOP_SCORE_STRING_SCREENY;
    model->tss.string_length = 6;
    strcpy(model->tss.top_score_num_string, "000000");
}


/**
 * initCurrentScoreString
 * 
 * Purpose: Initializes the current score string display with default values.
 * Input: css - A pointer to the current score string object to initialize.
 * Output: None.
 * Assumptions: Assumes a valid Game_Model pointer containing a 
 *              current score string object and access to pre-defined values 
 *              in header file.
 */
void initCurrentScoreString(Game_Model *model) {
    model->css.screenX = CURRENT_SCORE_STRING_SCREENX;
    model->css.screenY = CURRENT_SCORE_STRING_SCREENY;
    model->css.string_length = 6;
    strcpy(model->css.current_score_num_string, "000000");
}


/**
 * initLevelLabel
 * 
 * Purpose: Initializes the level label display with default values.
 * Input: lvlL - A pointer to the level label object to initialize.
 * Output: None.
 * Assumptions: Assumes a valid Game_Model pointer containing a 
 *              level label object and access to pre-defined values 
 *              in header file.
 */
void initLevelLabel(Game_Model *model) {
    model->lvlL.screenY = CURRENT_LEVEL_LABEL_SCREENY;
    model->lvlL.screenX = CURRENT_LEVEL_LABEL_SCREENX;
    model->lvlL.string_length = 5;
    strcpy(model->lvlL.level_label_string, "LEVEL");
}


/**
 * initLevelString
 * 
 * Purpose: Initializes the level string display with default values.
 * Input: lvlS - A pointer to the level string object to initialize.
 * Output: None.
 * Assumptions: Assumes a valid Game_Model pointer containing a 
 *              level string object and access to pre-defined values 
 *              in header file.
 */
void initLevelString(Game_Model *model) {
    model->lvlS.screenX = CURRENT_LEVEL_STRING_SCREENX;
    model->lvlS.screenY = CURRENT_LEVEL_STRING_SCREENY;
    model->lvlS.string_length = 2;
    strcpy(model->lvlS.level_num_string, "00"); /* Highest allowable value is 10 */
}


/**
 * setScoresAndLevel
 * 
 * Purpose: Sets all game score and level number string values to reflect
 *          the Game_Model Score_display object values.
 * Input: model - A pointer to the Game_model object.
 * Output: None
 * Assumption: Assumes all Score related objects are
 *             intialized prior to use, such as the score display,
 *             top score string, current score string, and level label.
*/
void setScoresAndLevel(Game_Model *model) {
    scoreToString(model->sd.top_score, &model->tss.top_score_num_string);
    scoreToString(model->sd.current_score, &model->css.current_score_num_string);
    levelToString(model->sd.level, &model->lvlS.level_num_string);
}


/**
 * incrementScore
 * 
 * Purpose: Increments the current score by 40 "multiplied" by the level value.
 * Input: model - A pointer to the Score_display structure with the game's 
 *                current score information.
 * Output: None.
 * Assumptions: Assumes a valid Game_Model pointer.
 */
void incrementScore(Game_Model *model) {
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
 * setTopScore
 * 
 * Purpose: Sets the top score to a predesired value. This value can't
 *          exceed 6 digits.
 * Input: model - A pointer to the Game_Model object containing the
 *                Score_display structure with the game's top score information.
 * Output: None.
 * Assumptions: Assumes a valid Game_Model pointer containing a 
 *              Score_display object.
 */
void setTopScore(Game_Model *model, unsigned long top_score) {
    model->sd.top_score = top_score;
}


/**
 * incrementLevel
 * 
 * Purpose: Increments the level value of the game in the models score display.
 *          Level maximum is 10.
 * Input: model - A pointer to the Game_Model object containing the
 *                Score_display structure with the game's level information.
 * Output: None.
 * Assumptions: Assumes a valid Game_Model pointer containing a 
 *              Score_display object.
 */
void incrementLevel(Game_Model *model) {
    if(model->sd.level < 10) {
        model->sd.level++;
    }
}


/**
 * updateTopScore
 * 
 * Purpose: Adjusts the top score to be equal to the current score if the
 *          current score exceeds the top score value.
 * Input: model - A pointer to the Score_display structure with the game's 
 *                top score and current score information.
 * Output: None.
 * Assumptions: Assumes a valid Game_Model pointer containing a 
 *              Score_display object.
 */
void updateTopScore(Game_Model *model) {
    if(model->sd.current_score > model->sd.top_score) {
        model->sd.top_score = model->sd.current_score;
    }
}


/**
 * scoreToString
 * 
 * Purpose: Converts an integer score into a char string representation.
 * Input: score - The integer score to be converted.
 *        score_string - A pointer to an unsigned char array to 
 *                      store the resulting string.
 * Output: None.
 * Assumptions: Assumes a valid pointer to an unsigned char array 
 *              with sufficient space to store the string.
 */
void scoreToString(unsigned long score, char score_string[]) {
    int i;
    score_string[6] = '\0';
    if(score == 0) { /* First score value will be zero, set score string to all 0's */
        for (i = 0; score_string[i] != '\0'; i++) {
            score_string[i] = '0';
        }
    }
    else if (score > 999999) { /* Else if score exceeds 6 digits, set score string to 999999 */
        for (i = 0; score_string[i] != '\0'; i++) {
            score_string[i] = '9';
        }
    } else {
        for (i = 5; score != 0; i--) { /* Else use regular score string numeric value to string converter */
        /* Works from the end of the score string (before the 
            terminator) going backwards since we are grabbing 
            the right most digit each time */
            score_string[i] = (unsigned char)((score % 10) + '0');
            score /= 10;
        }
    }
}


/**
 * levelToString
 * 
 * Purpose: Converts an integer for the level into a char string representation.
 * Input: level - The integer value of the level to be converted.
 *        level_string - A pointer to an array to store the resulting string.
 * Output: None.
 * Assumptions: Assumes a valid pointer to an array 
 *              with sufficient space to store the string.
 */
void levelToString(unsigned long level, char level_string[]) {
    level_string[2] = '\0';
    if (level > 10) {
        level = 10;
    }
    switch (level) {
        case 1: level_string[0] = '0'; level_string[1] = '1'; break;
        case 2: level_string[0] = '0'; level_string[1] = '2'; break;
        case 3: level_string[0] = '0'; level_string[1] = '3'; break;
        case 4: level_string[0] = '0'; level_string[1] = '4'; break;
        case 5: level_string[0] = '0'; level_string[1] = '5'; break;
        case 6: level_string[0] = '0'; level_string[1] = '6'; break;
        case 7: level_string[0] = '0'; level_string[1] = '7'; break;
        case 8: level_string[0] = '0'; level_string[1] = '8'; break;
        case 9: level_string[0] = '0'; level_string[1] = '9'; break;
        case 10: level_string[0] = '1'; level_string[1] = '0'; break;
        default: level_string[0] = '0'; level_string[1] = '0'; break;
    }
}


/******************************************************/
/********** NEXT TETROMINO DISPLAY FUNCTIONS **********/
/******************************************************/

/**
 * initNextTetromDisplay
 * 
 * Purpose: Initializes the display area for the next tetromino, 
 *          setting up its position, size, and appearance.
 * Input: model - A pointer to the Game_Model containing the Next Tetromino Display 
 *                to be initialized.
 * Output: None.
 * Assumptions: Assumes a valid pointer to a Next_tetrom_display structure. 
 *              The display area for the next tetromino is defined by pre-set 
 *              screen coordinates, width, and height.
 */
void initNextTetromDisplay(Game_Model *model) {
    model->ntd.screenX = NEXT_TETROM_DISPLAY_SCREENX;
    model->ntd.screenY = NEXT_TETROM_DISPLAY_SCREENY;
    model->ntd.width = NEXT_TETROM_DISPLAY_WIDTH_PX;
    model->ntd.height = NEXT_TETROM_DISPLAY_HEIGHT_PX;
}