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



/********** GENERAL GAME FUNCTIONS **********/

/** 
 * @name    initializeAllEvent
 * @param   p Play area to initialize.
 * @param   t Tetromino object to initialize.
 * @param   sd Score display object to initialize.
 * @param   tsl Top score label object to initialize.
 * @param   tss Top score string object to initialize.
 * @param   csl Current score label object to initialize.
 * @param   css Current score string object to initialize.
 * @param   lvlL Level label object to initialize.
 * @param   lvlS Level string object to initialize.
 * @param   ntd Next Tetromino Display object to initialize.
 * 
 * @brief Initializes all game objects to pre-defined "model.h" default values.
*/
void initializeAllEvent(Play_area *p, 
                    Tetromino *t, 
                    Score_display *sd, 
                    Top_score_label *tsl, 
                    Top_score_string *tss, 
                    Current_score_label *csl, 
                    Current_score_string *css,
                    Level_label *lvlL,
                    Level_string *lvlS,
                    Next_tetrom_display *ntd);


/** 
 * @name    quit
 * @param   undetermined
 * 
 * @brief   Future quit game event call.
 * 
 * @return  Returns 1 if quit was requested, 0 otherwise.
*/
int quit();



/********** TETROMINO FUNCTIONS **********/

/**
 * @name    spawnTetrominoEvent
 * @param   t Tetromino object to spawn to play area.
 * @param   p Play area object to copy Tetromino to.
 * 
 * @brief   Tetromino object values are copied to the Play area
 *          arena grid system.
 * 
 * @return  Returns 1 if the spawn was successful, 0 otherwise.
*/
int spawnTetrominoEvent(Tetromino *t, Play_area *p); /*Tested: Yes */


/**
 * @name    shiftTetrominoDownEvent
 * @param   t Tetromino object to be shifted down.
 * @param   p Play area where the Tetromino is to be shifted.
 * 
 * @brief   Shifts the Tetromino one block down in the play area.
 *          Checks for collisions and boundary conditions.
 * 
 * @return  Returns 1 if the shift was successful, 0 otherwise.
*/
int shiftTetrominoDownEvent(Tetromino *t, Play_area *p); /*Tested: Yes */


/**
 * @name    shiftTetrominoLeftEvent
 * @param   t Tetromino object to be shifted left.
 * @param   p Play area where the Tetromino is to be shifted.
 * 
 * @brief   Shifts the Tetromino one block to the left in the play area.
 *          Checks for collisions and boundary conditions.
 * 
 * @return  Returns 1 if the shift was successful, 0 otherwise.
*/
int shiftTetrominoLeftEvent(Tetromino *t, Play_area *p); /*Tested: Yes */


/**
 * @name    shiftTetrominoRightEvent
 * @param   t Tetromino object to be shifted right.
 * @param   p Play area where the Tetromino is to be shifted.
 * 
 * @brief   Shifts the Tetromino one block to the right in the play area.
 *          Checks for collisions and boundary conditions.
 * 
 * @return  Returns 1 if the shift was successful, 0 otherwise.
*/
int shiftTetrominoRightEvent(Tetromino *t, Play_area *p); /*Tested: Yes */


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
int rotateTetrominoCWiseEvent(Tetromino *t, Play_area *p); /*Tested: Yes */


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
int rotateTetrominoCCWiseEvent(Tetromino *t, Play_area *p); /*Tested: Yes */



/********** SCORE FUNCTIONS **********/

/**
 * @name    scoreIncrementEvent
 * @param   sd Score display object whose score is to be incremented.
 * 
 * @brief   Increments the current score, in response 
 *          to clearing lines.
*/
void scoreIncrementEvent(Score_display *sd);


/**
 * @name    incrementLevelEvent
 * @param   sd Score display object whose level is to be incremented.
 * 
 * @brief   Increments the level in the game, typically in response 
 *          to the player. This is in response to cumulative
 *          10 cleared lines in the game.
*/
void incrementLevelEvent(Score_display *sd);


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
*/
void setScoreDisplayValuesEvent(Score_display *sd, Top_score_string *tss, Current_score_string *css, Level_string *lvlS);


/**
 * @name    updateTopScoreEvent
 * @param   sd Score display object to update the top score on.
 * 
 * @brief   Updates the top score if the current score exceeds the top score.
 *          This function is called during score increments to ensure
 *          the Top score remains current.
*/
void updateTopScoreEvent(Score_display *sd); /*UPDATE CURRENT SCORE; UPDATE TOPSCORE IF CURRENT SCORE> TOP SCORE*/


#endif