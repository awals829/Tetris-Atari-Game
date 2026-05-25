/*
 * File: events.h
 * Author: Marusia Luciuk, Andrew Walsh
 * Team Members: Marusia Luciuk, Andrew Walsh
 *
 * Header file for game event functions in a Tetris-like game. It declares
 * functions for manipulating tetrominos, such as rotation, shifting, dropping,
 * and spawning, as well as functions related to the play area and scoring system,
 * including clearing lines and updating scores. This header file facilitates
 * the interaction between game elements and the gameplay mechanics.
 */

#ifndef EVENTS_H
#define EVENTS_H

#include "model.h"


/********************************************/
/********** GENERAL GAME FUNCTIONS **********/
/********************************************/

/** 
 * @name    initializeAllEvent
 * @param   model Game model object.
 * 
 * @brief   Initializes all game objects to default values.
*/
void initializeAllEvent(Game_Model *model); /*Tested: Yes */


/*****************************************/
/********** TETROMINO FUNCTIONS **********/
/*****************************************/

/**
 * @name    spawnTetrominoEvent
 * @param   model Game model object containing initialized Play_area object
 *                and initialized Tetromino object.
 * 
 * @brief   Tetromino object values are copied to the Play area
 *          arena grid system.
 * 
 * @return  Returns 1 if the spawn was successful, 0 otherwise.
*/
int spawnTetrominoEvent(Game_Model *model); /*Tested: Yes */

/**
 * @name    setNewTetrominoEvent
 * @param   model Game model object containing initialized Play_area object
 *                and initialized Tetromino object.
 * 
 * @brief   Sets up the new gameplay Tetromino from the next Tetromino.
*/
void setNewTetrominoEvent(Game_Model *model); /*Tested: Yes */

/**
 * @name    setNextTetrominoEvent
 * @param   model Game model object containing initialized Play_area object
 *                and initialized Tetromino object.
 * 
 * @brief   Sets up the next gameplay Tetromino for the next Tetromino object in the Game Model.
*/
void setNextTetrominoEvent(Game_Model *model); /*Tested: Yes */

/**
 * @name    placeTetrominoEvent
 * @param   model Game model object containing initialized Play_area object
 *                and initialized Tetromino object.
 * 
 * @brief   Sets the Tetromino location in the Play Area object as occupied
 *          space.
 * 
 * @note    This is different from spawning a Tetromino, as this function
 *          is designed to place a Tetromino at a location in the Play Area
 *          permanently.
*/
void placeTetrominoEvent(Game_Model *model); /*Tested: Yes */

/**
 * @name    shiftTetrominoDownEvent
 * @param   model Game model object containing initialized Play_area object
 *                and initialized Tetromino object.
 * 
 * @brief   Shifts the Tetromino one block down in the play area.
 *          Checks for collisions and boundary conditions.
 * 
 * @return  Returns 1 if the shift was successful, 0 otherwise.
*/
int shiftTetrominoDownEvent(Game_Model *model); /*Tested: Yes */

/**
 * @name    shiftTetrominoLeftEvent
 * @param   model Game model object containing initialized Play_area object
 *                and initialized Tetromino object.
 * 
 * @brief   Shifts the Tetromino one block to the left in the play area.
 *          Checks for collisions and boundary conditions.
 * 
 * @return  Returns 1 if the shift was successful, 0 otherwise.
*/
int shiftTetrominoLeftEvent(Game_Model *model); /*Tested: Yes */

/**
 * @name    shiftTetrominoRightEvent
 * @param   model Game model object containing initialized Play_area object
 *                and initialized Tetromino object.
 * 
 * @brief   Shifts the Tetromino one block to the right in the play area.
 *          Checks for collisions and boundary conditions.
 * 
 * @return  Returns 1 if the shift was successful, 0 otherwise.
*/
int shiftTetrominoRightEvent(Game_Model *model); /*Tested: Yes */

/**
 * @name    rotateTetrominoCWiseEvent
 * @param   model Game model object containing initialized Play_area object
 *                and initialized Tetromino object.
 * 
 * @brief   Rotates the Tetromino 90 degrees clockwise within the play area.
 *          Checks for collisions and boundary conditions.
 * 
 * @return  Returns 1 if the rotation was successful, 0 otherwise.
 * 
 * @note    Rotation only checks points of rotation destination.
 *          Therefore a rotation "through" objects to a valid destination
 *          will occur.
*/
int rotateTetrominoCWiseEvent(Game_Model *model); /*Tested: Yes */

/**
 * @name    rotateTetrominoCCWiseEvent
 * @param   model Game model object containing initialized Play_area object
 *                and initialized Tetromino object.
 * 
 * @brief   Rotates the Tetromino 90 degrees counter-clockwise within the play area.
 *          Checks for collisions and boundary conditions.
 * 
 * @return  Returns 1 if the rotation was successful, 0 otherwise.
 * 
 * @note    Rotation only checks points of rotation destination.
 *          Therefore a rotation "through" objects to a valid destination
 *          will occur.
*/
int rotateTetrominoCCWiseEvent(Game_Model *model); /*Tested: Yes */


/*****************************************/
/********** PLAY AREA FUNCTIONS **********/
/*****************************************/

/**
 * @name    clearLinesEvent
 * @param   model Game model object containing initialized Play_area object
 *                and initialized Tetromino object.
 * 
 * @brief   Clears any filled lines, increments the score, and keeps count 
 *          of the total cleared lines acheived during a clear line cycle.
 *          The total cleared lines is used for level incrementing.
*/
void clearLinesEvent(Game_Model *model); /*Tested: Yes */

/**
 * @name    speedIncreaseEvent
 * @param   model Game model object
 * 
 * @brief   Decrements the Game Model objects gravity for the default 
 *          Tetromino falling rate per second. This increases the synchronous
 *          falling rate.
*/
void speedIncreaseEvent(Game_Model *model); /*Tested: Yes */


/*************************************/
/********** SCORE FUNCTIONS **********/
/*************************************/

/**
 * @name    incrementLevelEvent
 * @param   model Game model object
 * 
 * @brief   Increments the Game Model objects level and increments
 *          the game speed
*/
void incrementLevelEvent(Game_Model *model); /*Tested: Yes */


/******************************************/
/********** GAME MODEL FUNCTIONS **********/
/******************************************/

/**
 * @name    updateModelEvent
 * @param   model Game model object
 * 
 * @brief   Updates the model state based on asynchronous and synchronous
 *          gameplay event flags.
*/
void updateModelEvent(Game_Model *model); /*Tested: Yes */

#endif
