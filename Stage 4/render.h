/*
 * File: render.h
 * Author: Andrew Walsh, Marusia Luciuk
 * Team Members: Marusia Luciuk, Andrew Walsh
 *
 * This file contains declarations for all render functions
 * used in the tetris game. These will render model objects
 * to the screen for visualization.
 * 
 */

#ifndef RENDER_H
#define RENDER_H

#include "model.h"
#include "raster.h"
#include "assets.h"

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
void renderTetromino(const Tetromino *t, UINT16 *base);


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
void clearTetrominoRender(const Tetromino *t, UINT16 *base);


/**
 * @name renderPlayArea
 * 
 * @param p Initialized Play Area object to render to the screen.
 * @param base pointer to the screen to render to.
 * 
 * @brief Renders a Play Area object to its respective screen coordindates.
 * 
 * @return None.
*/
void renderPlayArea(const Play_area *playArea, unsigned char *base);


/**
 * @name renderNextTetrominoArea
 * 
 * @param ntd Initialized Next tetromino display object to render to the screen.
 * @param base pointer to the screen to render to.
 * 
 * @brief (W.I.P) Renders a Next tetromino display object to its respective screen coordindates.
 * 
 * @return None.
*/
void renderNextTetrominoArea(const Next_tetrom_display *ntd, unsigned char *base);


/**
 * @name renderBlocks
 * 
 * @param p Initialized Play Area object.
 * @param base pointer to the screen to render to.
 * 
 * @brief Renders all occupied blocks to the screen, clearing
 *        any rendered, and now unnocupied, blocks in the process.
 * 
 * @return None.
*/
void renderBlocks(const Play_area *p, UINT16 *base);


/**
 * @name renderScoreDisplay
 * 
 * @param p Initialized Score Display object to render to the screen.
 * @param base pointer to the screen to render to.
 * 
 * @brief Renders a Score Display object to its respective screen coordindates.
 * 
 * @return None.
*/
void renderScoreDisplay(const Score_display *sd, unsigned char *base);


/**
 * @name renderTopScoreLabel
 * 
 * @param p Initialized Top Score Label object to render to the screen.
 * @param base pointer to the screen to render to.
 * 
 * @brief Renders a Top Score Label object to its respective screen coordindates.
 * 
 * @return None.
*/
void renderTopScoreLabel(const Top_score_label *tsl,  UINT8* base);


/**
 * @name renderTopScoreNumString
 * 
 * @param p Initialized Top Score String object to render to the screen.
 * @param base pointer to the screen to render to.
 * 
 * @brief Renders a Top Score String object to its respective screen coordindates.
 * 
 * @return None.
*/
void renderTopScoreNumString(const Top_score_string *tss,  UINT8* base);


/**
 * @name renderCurrentScoreLabel
 * 
 * @param p Initialized Current Score Label object to render to the screen.
 * @param base pointer to the screen to render to.
 * 
 * @brief Renders a Current Score Label object to its respective screen coordindates.
 * 
 * @return None.
*/
void renderCurrentScoreLabel(const Current_score_label *csl,  UINT8* base);


/**
 * @name renderCurrentScoreNumString
 * 
 * @param p Initialized Current Score String object to render to the screen.
 * @param base pointer to the screen to render to.
 * 
 * @brief Renders a Current Score String object to its respective screen coordindates.
 * 
 * @return None.
*/
void renderCurrentScoreNumString(const Current_score_string *css,  UINT8* base);


/**
 * @name renderLevelLabel
 * 
 * @param p Initialized Level Label object to render to the screen.
 * @param base pointer to the screen to render to.
 * 
 * @brief Renders a Level Label object to its respective screen coordindates.
 * 
 * @return None.
*/
void renderLevelLabel(const Level_label *lvlL,  UINT8* base);


/**
 * @name renderLevelNumString
 * 
 * @param p Initialized Level String object to render to the screen.
 * @param base pointer to the screen to render to.
 * 
 * @brief Renders a Level String object to its respective screen coordindates.
 * 
 * @return None.
*/
void renderLevelNumString(const Level_string *lvlS,  UINT8* base);


/**
 * @name renderLevelNumString
 * 
 * @param tsl pointer to Top Score Label object to render.
 * @param tss pointer to Top Score String object to render.
 * @param csl pointer to Current Score Label object to render.
 * @param css pointer to Current Score String object to render.
 * @param lvlL pointer to Level Label object to render.
 * @param lvlS pointer to Level String object to render.
 * @param base pointer to the screen to render to.
 * 
 * @brief Wrapper function for all score display render functions.
 *        Renders each paramater object.
 * 
 * @return None.
*/
void renderScoreDisplayValues(const Top_score_label *tsl, const Top_score_string *tss,
                              const Current_score_label *csl, const Current_score_string *css,
                              const Level_label *lvlL, const Level_string *lvlS, 
                              UINT8 *base);

#endif
