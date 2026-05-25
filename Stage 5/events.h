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
void initializeAllEvent(Game_Model *model, long seed);


/** 
 * @name    quit
 * @param   undetermined
 * 
 * @brief   Future quit game event call.
 * 
 * @return  Returns 1 if quit was requested, 0 otherwise.
*/
int quit();


/******************************************/
/********** GAME MODEL FUNCTIONS **********/
/******************************************/

void updateModel(Game_Model *model, long seed);


void newTetromino(Game_Model *model, long seed);


/*****************************************/
/********** TETROMINO FUNCTIONS **********/
/*****************************************/

/**
 * @name    spawnTetrominoEvent
 * @param   model Game model object.
 * 
 * @brief   Tetromino object values are copied to the Play area
 *          arena grid system.
 * 
 * @return  Returns 1 if the spawn was successful, 0 otherwise.
*/
int spawnTetrominoEvent(Game_Model *model); /*Tested: Yes */

/**
 * @name    shiftTetrominoDownEvent
 * @param   model Game model object.
 * 
 * @brief   Shifts the Tetromino one block down in the play area.
 *          Checks for collisions and boundary conditions.
 * 
 * @return  Returns 1 if the shift was successful, 0 otherwise.
*/
int shiftTetrominoDownEvent(Game_Model *model); /*Tested: Yes */

/**
 * @name    shiftTetrominoLeftEvent
 * @param   model Game model object.
 * 
 * @brief   Shifts the Tetromino one block to the left in the play area.
 *          Checks for collisions and boundary conditions.
 * 
 * @return  Returns 1 if the shift was successful, 0 otherwise.
*/
int shiftTetrominoLeftEvent(Game_Model *model); /*Tested: Yes */

/**
 * @name    shiftTetrominoRightEvent
 * @param   model Game model object.
 * 
 * @brief   Shifts the Tetromino one block to the right in the play area.
 *          Checks for collisions and boundary conditions.
 * 
 * @return  Returns 1 if the shift was successful, 0 otherwise.
*/
int shiftTetrominoRightEvent(Game_Model *model); /*Tested: Yes */

/**
 * @name    rotateTetrominoCWiseEvent
 * @param   t Tetromino object to be rotated clockwise.
 * @param   p Play area where the Tetromino is to be rotated.
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
 * @param   t Tetromino object to be rotated counter-clockwise.
 * @param   p Play area where the Tetromino is to be rotated.
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



/*************************************/
/********** SCORE FUNCTIONS **********/
/*************************************/

/**
 * @name    scoreIncrementEvent
 * @param   sd Score display object whose score is to be incremented.
 * 
 * @brief   Increments the current score, based on the 
 *          model level multiplier.
*/
void scoreIncrementEvent(Game_Model *model);

/**
 * @name    incrementLevelEvent
 * @param   sd Score display object whose level is to be incremented.
 * 
 * @brief   Increments the level in the game, typically in response 
 *          to the player. This is in response to cumulative
 *          10 cleared lines in the game.
*/
void incrementLevelEvent(Game_Model *model);

/**
 * @name    setScoreDisplayValuesEvent
 * @param   sd Score display object to update scores on.
 * @param   tss Top score string object to update.
 * @param   css Current score string object to update.
 * @param   lvlS Level string object to update.
 * 
 * @brief   Sets the current and top scores on the score display.
 *          This function is called to update the UI elements with the 
 *          new scores. It will only ever update values that have changed, 
 *          ignoring any score values that have not adjusted.
 * 
 * @note    Does not render values to screen!
*/
void setScoreDisplayValuesEvent(Game_Model *model);

#endif
