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
 * @brief Initializes all game objects to default values.
*/
void initializeAllEvent(Game_Model *model);


/** 
 * @name    quit
 * @param   undetermined
 * 
 * @brief   Future quit game event call.
 * 
 * @return  Returns 1 if quit was requested, 0 otherwise.
*/
int quit();


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


void setNewTetrominoEvent(Game_Model *model);


void setNextTetrominoEvent(Game_Model *model);


void placeTetrominoEvent(Game_Model *model);


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

void clearLinesEvent(Game_Model *model);

void dropLinesEvent(Game_Model *model, int row);

void speedIncreaseEvent(Game_Model *model);


/*************************************/
/********** SCORE FUNCTIONS **********/
/*************************************/

void incrementScoreEvent(Game_Model *model);


void incrementLevelEvent(Game_Model *model);


/******************************************/
/********** GAME MODEL FUNCTIONS **********/
/******************************************/

void updateModelEvent(Game_Model *model);

#endif
