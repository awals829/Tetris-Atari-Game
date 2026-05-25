/*
 * File: model.h
 * Author: Marusia Luciuk, Andrew Walsh
 * Team Members: Marusia Luciuk, Andrew Walsh
 *
 * The definitions file for the functions used 
 * to manipulate and instantiate the objects
 * in the tetris game.
 */
#include "model.h"
#include "string.h"


/********** GRID COORD & SCREEN COORD CONVERSION FUNCTIONS **********/


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


/********** BLOCK FUNCTIONS **********/


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
 * Input: play_area - A pointer to the play area.
 *        arenaX - The arena array x-coordinate of the position to check.
 *        arenaY - The arena array y-coordinate of the position to check.
 * Output: Returns 1 if the position is occupied, 0 otherwise.
 * Assumptions: Assumes a valid arena x and y array coordinates.
 */
int isPositionOccupied(Play_area *play_area, int arenaX, int arenaY) {
    return (play_area->arena[arenaX][arenaY].is_occupied);
}


/**
 * isPositionTetromino
 * 
 * Purpose: Checks if the specified position in the play area is a tetromino block.
 * Input: play_area - A pointer to the play area.
 *        arenaX - The arena array x-coordinate of the position to check.
 *        arenaY - The arena array y-coordinate of the position to check.
 * Output: Returns 1 if the position is occupied, 0 otherwise.
 * Assumptions: Assumes a valid arena x and y array coordinates.
 */
int isPositionTetromino(Play_area *play_area, int arenaX, int arenaY) {
    return (play_area->arena[arenaX][arenaY].is_tetromino_piece);
}


/********** TETROMINO FUNCTIONS **********/


/** randomize
 * 
 * Purpose: Selects a random tetronimo type based on the current piece's position.
 *          (Recommended use after a piece is placed since the coordinates will vary)
 * Input: tetronimo t - A tetronimo structure, used to seed the random choice.
 * Assumptions: The randomness is pseudo-random, based on the piece's entered
 *              position, and limited to a predefined set of types.
 */
void randomize(Tetromino *t) {
    char blocks[6] = {'I', 'O', 'T', 'S', 'Z', 'L'};
    int seed = t->blocks[1].arenaX + t->blocks[3].arenaY;
    int index = seed & 5;
    char randomChar = blocks[index];
    t->tetromino_type = randomChar;
}


/**
 * copyTetrominotoArena
 * 
 * Purpose: Copies the tetromino blocks to the play area, 
 *          marking them as occupied and as part of a tetromino.
 * Input: t - A pointer to the tetromino to be copied.
 *        p - A pointer to the play area where the tetromino will be copied.
 * Output: None.
 * Assumptions: Assumes valid pointers for both the tetromino and the play area.
 */
void copyTetrominotoArena(Tetromino *t, Play_area *p) {
    int i;
    for(i = 0; i < TETROMINO_SIZE; i++) {
        p->arena[t->blocks[i].arenaX][t->blocks[i].arenaY].is_occupied = TRUE;
        p->arena[t->blocks[i].arenaX][t->blocks[i].arenaY].is_tetromino_piece = TRUE;
    }
}


/**
 * clearTetrominoArena
 * 
 * Purpose: Clears the tetromino blocks from the play area, 
 *          marking them as unoccupied and not part of a tetromino.
 * Input: t - A pointer to the tetromino to be cleared.
 *        p - A pointer to the play area from which the tetromino will be cleared.
 * Output: None.
 * Assumptions: Assumes valid pointers for both the tetromino and the play area.
 */
void clearTetrominoArena(Tetromino *t, Play_area *p) {
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


int shiftTetrominoDown(Tetromino *t, Play_area *p) {
    int i, nextX, nextY, next_occupied, next_tetromino;
    int validMove = 1;
    Tetromino tempTetromino;
    tempTetromino = *t;

    for (i = 0; i < TETROMINO_SIZE; i++) {
        nextX = tempTetromino.blocks[i].arenaX;
        nextY = tempTetromino.blocks[i].arenaY + 1;   
        validMove = movementValidityChecker(p, nextX, nextY);
        if(!validMove) break;
        tempTetromino.blocks[i].arenaX = nextX;
        tempTetromino.blocks[i].arenaY = nextY;
        tempTetromino.blocks[i].screenX = arenaX_to_screenX(tempTetromino.blocks[i]);
        tempTetromino.blocks[i].screenY = arenaY_to_screenY(tempTetromino.blocks[i]);
    }
    if(validMove) {
        *t = tempTetromino;
    }
    return validMove;
}


int shiftTetrominoLeft(Tetromino *t, Play_area *p) {
    int i, nextX, nextY, next_occupied, next_tetromino;
    int validMove = 1;
    Tetromino tempTetromino;
    tempTetromino = *t;

    for (i = 0; i < TETROMINO_SIZE; i++) {
        nextX = tempTetromino.blocks[i].arenaX - 1;
        nextY = tempTetromino.blocks[i].arenaY;        
        validMove = movementValidityChecker(p, nextX, nextY);
        if(!validMove) break;
        tempTetromino.blocks[i].arenaX = nextX;
        tempTetromino.blocks[i].arenaY = nextY;
        tempTetromino.blocks[i].screenX = arenaX_to_screenX(tempTetromino.blocks[i]);
        tempTetromino.blocks[i].screenY = arenaY_to_screenY(tempTetromino.blocks[i]);
    }
    if(validMove) {
        *t = tempTetromino;
    }
    return validMove;
}


int shiftTetrominoRight(Tetromino *t, Play_area *p) {
    int i, nextX, nextY, next_occupied, next_tetromino;
    int validMove = 1;
    Tetromino tempTetromino;
    tempTetromino = *t;

    for (i = 0; i < TETROMINO_SIZE; i++) {
        nextX = tempTetromino.blocks[i].arenaX + 1;
        nextY = tempTetromino.blocks[i].arenaY;      
        validMove = movementValidityChecker(p, nextX, nextY);
        if(!validMove) break;
        tempTetromino.blocks[i].arenaX = nextX;
        tempTetromino.blocks[i].arenaY = nextY;
        tempTetromino.blocks[i].screenX = arenaX_to_screenX(tempTetromino.blocks[i]);
        tempTetromino.blocks[i].screenY = arenaY_to_screenY(tempTetromino.blocks[i]);
    }
    if(validMove) {
        *t = tempTetromino;
    }
    return validMove;
}

/**
 * initializeTetrominoSpawn
 * 
 * Purpose: Initializes the specified type of tetromino to its types 
 *          arena array spawn coordinates.
 * Input: t - A pointer to the tetromino to be initialized.
 *        type - The character representing the type of tetromino to 
 *               initialize ('I', 'O', 'T', 'S', 'Z', 'L', 'J').
 * Output: None.
 * Assumptions: Assumes a valid pointer for the tetromino and 
 *              a valid character for the tetromino type.
 */
void initializeTetrominoSpawn(Tetromino *t, char type) {
    int i;
    switch (type) {
        case 'T': initializeTetrominoTshape(t); t->tetromino_type = 'T'; break;
        case 'L': initializeTetrominoLshape(t); t->tetromino_type = 'L'; break;
        case 'J': initializeTetrominoJshape(t); t->tetromino_type = 'J'; break;
        case 'S': initializeTetrominoSshape(t); t->tetromino_type = 'S'; break;
        case 'Z': initializeTetrominoZshape(t); t->tetromino_type = 'Z'; break;
        case 'I': initializeTetrominoIshape(t); t->tetromino_type = 'I';break;
        case 'O': initializeTetrominoOshape(t); t->tetromino_type = 'O'; break;
        default: initializeTetrominoOshape(t); t->tetromino_type = 'O'; break;
    }

    for(i = 0; i < TETROMINO_SIZE; i++) {
        initBlock(&t->blocks[i], t->blocks[i].arenaX, t->blocks[i].arenaY);
        /* Initialize blocks as part of the Tetromino as initBlock() 
            sets these values to FALSE initially. */
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
void initializeTetrominoSshape(Tetromino *t)  {
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
 * Purpose: Checks if moving to the specified position in the play area is valid.
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


/**
 * tetrominoShiftDown
 * 
 * Purpose: Moves the tetromino down by one block in the play area.
 * Input: t - A pointer to the tetromino.
 *        p - A pointer to the play area.
 * Output: None.
 * Assumptions: Assumes valid tetromino and play area pointers.
 */
void tetrominoShiftDown(Tetromino *t, Play_area *p) {
    int i = 0;
    clearTetrominoArena(t, p);
    for(i = 0; i < TETROMINO_SIZE; i++) {
        t->blocks[i].arenaY += 1;
        t->blocks[i].screenX = arenaX_to_screenX(t->blocks[i]);
        t->blocks[i].screenY = arenaY_to_screenY(t->blocks[i]);
    }
    copyTetrominotoArena(t, p);
}


/**
 * tetrominoShiftLeft
 * 
 * Purpose: Moves the tetromino left by one block in the play area.
 * Input: t - A pointer to the tetromino.
 *        p - A pointer to the play area.
 * Output: None.
 * Assumptions: Assumes valid tetromino and play area pointers.
 */
void tetrominoShiftLeft(Tetromino *t, Play_area *p) {
    int i = 0;
    clearTetrominoArena(t, p);
    for(i = 0; i < TETROMINO_SIZE; i++) {
        t->blocks[i].arenaX -= 1;
        t->blocks[i].screenX = arenaX_to_screenX(t->blocks[i]);
        t->blocks[i].screenY = arenaY_to_screenY(t->blocks[i]);
    }
    copyTetrominotoArena(t, p);
}


/**
 * tetrominoShiftRight
 * 
 * Purpose: Moves the tetromino right by one block in the play area.
 * Input: t - A pointer to the tetromino.
 *        p - A pointer to the play area.
 * Output: None.
 * Assumptions: Assumes valid tetromino and play area pointers.
 */
void tetrominoShiftRight(Tetromino *t, Play_area *p) {
    int i = 0;
    clearTetrominoArena(t, p);
    for(i = 0; i < TETROMINO_SIZE; i++) {
        t->blocks[i].arenaX += 1;
        t->blocks[i].screenX = arenaX_to_screenX(t->blocks[i]);
        t->blocks[i].screenY = arenaY_to_screenY(t->blocks[i]);
    }
    copyTetrominotoArena(t, p);
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
        if(!isValid) break;

        /* Store new positions in temp for potential valid deep copy. */
        tempTetromino.blocks[i].arenaX = newX;
        tempTetromino.blocks[i].arenaY = newY;
        tempTetromino.blocks[i].screenX = arenaX_to_screenX(tempTetromino.blocks[i]);
        tempTetromino.blocks[i].screenY = arenaY_to_screenY(tempTetromino.blocks[i]);
    }
    /* Apply new positions if all are valid */
    if (isValid) {
        *t = tempTetromino; /* Assigning copy back to parameter tetromino when changes are valid */
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
        if(!isValid) break;

        /* Store new positions in temp for potential valid deep copy. */
        tempTetromino.blocks[i].arenaX = newX;
        tempTetromino.blocks[i].arenaY = newY;
        tempTetromino.blocks[i].screenX = arenaX_to_screenX(tempTetromino.blocks[i]);
        tempTetromino.blocks[i].screenY = arenaY_to_screenY(tempTetromino.blocks[i]);
    }

    /* Apply new positions if all are valid */
    if (isValid) {
        *t = tempTetromino; /* Assigning copy back to parameter tetromino when changes are valid */
    }

    return isValid;
}


/********** PLAY AREA FUNCTIONS **********/


/**
 * initPlayArea
 * 
 * Purpose: Initializes the play area with pre-defined values.
 * Input: p - A pointer to the play area to initialize.
 * Output: None.
 * Assumptions: Assumes a valid pointer to a play area and 
 *              access to pre-defined values in header file.
 */
void initPlayArea(Play_area *p) {
    int x, y;
    p->screenX = PLAY_AREA_START_SCREENX;
    p->screenY = PLAY_AREA_START_SCREENY;
    p->width = PLAY_AREA_WIDTH_SCREEN;
    p->height = PLAY_AREA_HEIGHT_SCREEN;

    for(y = 0; y < PLAY_AREA_HEIGHT_GRID; y++)
        for(x = 0; x < PLAY_AREA_WIDTH_GRID; x++) {
            p->arena[x][y].is_occupied = FALSE;
            p->arena[x][y].is_tetromino_piece = FALSE;
            initBlock(&p->arena[x][y], x, y);
        }
}


/********** SCORE FUNCTIONS **********/


/**
 * initScoreDisplay
 * 
 * Purpose: Initializes the score display with default values.
 * Input: sd - A pointer to the score display to initialize.
 * Output: None.
 * Assumptions: Assumes a valid pointer to a score display and 
 *              access to pre-defined values in header file.
 */
void initScoreDisplay(Score_display *sd) {
    sd->current_score = 0;
    sd->top_score = 0; /* Goal to load top score from prior run if possible */
    sd->screenX = SCORE_DISPLAY_SCREENX;
    sd->screenY = SCORE_DISPLAY_SCREENY;
    sd->width = SCORE_DISPLAY_WIDTH_PX;
    sd->height = SCORE_DISPLAY_HEIGHT_PX;
    sd->level = 1; /* Starting level is 1 */
}


/**
 * initTopScoreLabel
 * 
 * Purpose: Initializes the top score label with default values.
 * Input: tsl - A pointer to the top score label to initialize.
 * Output: None.
 * Assumptions: Assumes a valid pointer to a top score label and 
 *              access to pre-defined values in header file.
 */
void initTopScoreLabel(Top_score_label *tsl) {
    tsl->screenX = TOP_SCORE_LABEL_SCREENX;
    tsl->screenY = TOP_SCORE_LABEL_SCREENY;
    tsl->string_length = 9;
    strcpy(tsl->top_score_label_string, "TOP SCORE");
}


/**
 * initCurrentScoreLabel
 * 
 * Purpose: Initializes the current score label with default values.
 * Input: csl - A pointer to the current score label to initialize.
 * Output: None.
 * Assumptions: Assumes a valid pointer to a current score label and
 *              access to pre-defined values in header file.
 */
void initCurrentScoreLabel(Current_score_label *csl) {
    csl->screenX = CURRENT_SCORE_LABEL_SCREENX;
    csl->screenY = CURRENT_SCORE_LABEL_SCREENY;
    csl->string_length = 5;
    strcpy(csl->current_score_label_string, "SCORE");
}


/**
 * initTopScoreString
 * 
 * Purpose: Initializes the top score string display with default values.
 * Input: tss - A pointer to the top score string object to initialize.
 * Output: None.
 * Assumptions: Assumes a valid pointer to the top score string object.
 */
void initTopScoreString(Top_score_string *tss) {
    tss->screenX = TOP_SCORE_STRING_SCREENX;
    tss->screenY = TOP_SCORE_STRING_SCREENY;
    tss->string_length = 6;
    tss->top_score = 0;
    strcpy(tss->top_score_num_string, "000000");
}


/**
 * initCurrentScoreString
 * 
 * Purpose: Initializes the current score string display with default values.
 * Input: css - A pointer to the current score string object to initialize.
 * Output: None.
 * Assumptions: Assumes a valid pointer to the current score string object.
 */
void initCurrentScoreString(Current_score_string *css) {
    css->screenX = CURRENT_SCORE_STRING_SCREENX;
    css->screenY = CURRENT_SCORE_STRING_SCREENY;
    css->string_length = 6;
    strcpy(css->current_score_num_string, "000000");
}


/**
 * initLevelLabel
 * 
 * Purpose: Initializes the level label display with default values.
 * Input: lvlL - A pointer to the level label object to initialize.
 * Output: None.
 * Assumptions: Assumes a valid pointer to the level label object.
 */
void initLevelLabel(Level_label *lvlL) {
    lvlL->screenX = CURRENT_LEVEL_LABEL_SCREENX;
    lvlL->screenY = CURRENT_LEVEL_LABEL_SCREENY;
    lvlL->string_length = 5;
    strcpy(lvlL->level_label_string, "LEVEL");
}


/**
 * initLevelString
 * 
 * Purpose: Initializes the level string display with default values.
 * Input: lvlS - A pointer to the level string object to initialize.
 * Output: None.
 * Assumptions: Assumes a valid pointer to the level string object.
 */
void initLevelString(Level_string *lvlS) {
    lvlS->screenX = CURRENT_LEVEL_STRING_SCREENX;
    lvlS->screenY = CURRENT_LEVEL_STRING_SCREENY;
    lvlS->string_length = 2;
    strcpy(lvlS->level_num_string, "00"); /* Highest allowable value is 10 */
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


/**
 * updateAllScoreDisplayNum
 * 
 * Purpose: Updates all score-related display numbers.
 * Input: sd - A pointer to the score display.
 *        tss - A pointer to the top score string.
 *        css - A pointer to the current score string.
 *        lvlS - A pointer to the level string.
 * Output: None.
 * Assumptions: Assumes valid pointers to score display, top score string, 
 *              current score string, and level string.
 */
void updateAllScoreDisplayNum(Score_display *sd, Top_score_string *tss, Current_score_string *css, Level_string *lvlS) {
    scoreToString(sd->top_score, tss->top_score_num_string);
    scoreToString(sd->current_score, css->current_score_num_string);
    levelToString(sd->level, lvlS->level_num_string);
}