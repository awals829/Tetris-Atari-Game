/*
 * File: render.h
 * Author: Andrew Walsh, Marusia Luciuk
 * Team Members: Marusia Luciuk, Andrew Walsh
 *
 * This file contains declarations for all render functions
 * used in the tetris game. These will render model objects
 * to the screen for visualization.
 */

#ifndef RENDER_H
#define RENDER_H

#include "model.h"
#include "raster.h"
#include "assets.h"


/**
 * @name renderAllObjects
 * 
 * @param model Initialized Game_model object to render to the screen.
 * @param base pointer to the screen to render to.
 * 
 * @brief Calls all render functions to render the entire
 *        Game_model object to the screen.
 * 
 * @return None.
*/
void renderAllObjects(const Game_Model *model, void *base);


/**
 * @name renderTetromino
 * 
 * @param t Initialized Tetromino object to render to the screen.
 * @param base pointer to the screen to render to.
 * 
 * @brief Renders a Tetromino object to its respective screen coordindates.
 * 
 * @return None.
*/
void renderTetromino(const Tetromino *t, Play_area *p, UINT16 *base);


/**
 * @name clearTetrominoRender
 * 
 * @param t Initialized Tetromino object to clear from the screen.
 * @param base pointer to the screen to clear the render from.
 * 
 * @brief Clears a Tetromino object from its respective screen coordindates.
 * 
 * @return None.
*/
void clearTetrominoRender(const Tetromino *t, Play_area *p, UINT16 *base);


/**
 * @name renderPlayArea
 * 
 * @param model Game Model containing initialized Play Area object to render to the screen.
 * @param base pointer to the screen to render to.
 * 
 * @brief Renders a Play Area object to its respective screen coordindates.
 * 
 * @return None.
*/
void renderPlayArea(const Game_Model *model, UINT8 *base);


/**
 * @name renderNextTetrominoArea
 * 
 * @param model Game Model containing initialized Next tetromino display object to render to the screen.
 * @param base pointer to the screen to render to.
 * 
 * @brief (W.I.P) Renders a Next tetromino display object to its respective screen coordindates.
 * 
 * @return None.
*/
void renderNextTetrominoArea(const Game_Model *model, UINT8 *base);


/**
 * @name renderBlocks
 * 
 * @param model Game Model containing initialized Play Area object.
 * @param base pointer to the screen to render to.
 * 
 * @brief Renders all occupied blocks to the screen, clearing
 *        any rendered, and now unnocupied, blocks in the process.
 * 
 * @return None.
*/
void renderBlocks(const Game_Model *model, UINT16 *base);


/**
 * @name renderScoreDisplay
 * 
 * @param model Game Model containing initialized Score Display object to render to the screen.
 * @param base pointer to the screen to render to.
 * 
 * @brief Renders a Score Display object to its respective screen coordindates.
 * 
 * @return None.
*/
void renderScoreDisplay(const Game_Model *model, UINT8 *base);


/**
 * @name renderTopScoreLabel
 * 
 * @param model Game Model containing initialized Top Score Label object to render to the screen.
 * @param base pointer to the screen to render to.
 * 
 * @brief Renders a Top Score Label object to its respective screen coordindates.
 * 
 * @return None.
*/
void renderTopScoreLabel(const Game_Model *model,  UINT8 *base);


/**
 * @name renderTopScoreNumString
 * 
 * @param model Game Model containing initialized Top Score String object to render to the screen.
 * @param base pointer to the screen to render to.
 * 
 * @brief Renders a Top Score String object to its respective screen coordindates.
 * 
 * @return None.
*/
void renderTopScoreNumString(const Game_Model *model,  UINT8 *base);


/**
 * @name renderCurrentScoreLabel
 * 
 * @param model Game Model containing initialized Current Score Label object to render to the screen.
 * @param base pointer to the screen to render to.
 * 
 * @brief Renders a Current Score Label object to its respective screen coordindates.
 * 
 * @return None.
*/
void renderCurrentScoreLabel(const Game_Model *model,  UINT8 *base);


/**
 * @name renderCurrentScoreNumString
 * 
 * @param model Game Model containing initialized Current Score String object to render to the screen.
 * @param base pointer to the screen to render to.
 * 
 * @brief Renders a Current Score String object to its respective screen coordindates.
 * 
 * @return None.
*/
void renderCurrentScoreNumString(const Game_Model *model,  UINT8 *base);


/**
 * @name renderLevelLabel
 * 
 * @param model Game Model containing initialized Level Label object to render to the screen.
 * @param base pointer to the screen to render to.
 * 
 * @brief Renders a Level Label object to its respective screen coordindates.
 * 
 * @return None.
*/
void renderLevelLabel(const Game_Model *model,  UINT8 *base);


/**
 * @name renderLevelNumString
 * 
 * @param model Game Model containing initialized Level String object to render to the screen.
 * @param base pointer to the screen to render to.
 * 
 * @brief Renders a Level String object to its respective screen coordindates.
 * 
 * @return None.
*/
void renderLevelNumString(const Game_Model *model,  UINT8* base);


/**
 * @name renderScoreDisplayValues
 * 
 * @param model Game Model.
 * @param base pointer to the screen to render to.
 * 
 * @brief Wrapper function for all score display render functions.
 *        Renders each paramater object.
 * 
 * @return None.
*/
void renderScoreDisplayValues(const Game_Model *model, UINT8 *base);

/**
 * @name renderAllObjects
 * 
 * @param model Game Model.
 * @param base pointer to the screen to render to.
 * 
 * @brief Wrapper function for all render object functions.
 *        Renders each object in the Game Model.
 * 
 * @return None.
*/
void renderAllObjects(const Game_Model *model, void *base);


#endif
