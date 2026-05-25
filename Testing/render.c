/*
 * File: render.c
 * Author: Andrew Walsh, Marusia Luciuk
 * Team Members: Marusia Luciuk, Andrew Walsh
 *
 * This file contains definitions for all render functions
 * used in the tetris game. These will render model objects
 * to the screen for visualization.
 */

#include "render.h"
#include "assets.h"
#include "model.h"
#include "raster.h"
#include "font.h"


/********************************************/
/********** GENERAL GAME FUNCTIONS **********/
/********************************************/

/**
 * renderAllObjects
 * 
 * Purpose: Renders all Game_model objects to the screen.
 * Input: model - A pointer to the Game_model to be rendered.
 *        base - The base address of the screen where the model 
 *               will be rendered.
 * Output: None.
 * Assumptions: Assumes a valid Game_model pointer and a properly 
 *              initialized screen buffer.
 */
void renderAllObjects(const Game_Model *model, void *base) {
    renderPlayArea(model, (UINT8 *) base);
    renderScoreDisplay(model, (UINT8 *) base);
    renderScoreDisplayValues(model, (UINT8 *) base);
    renderNextTetrominoArea(model, (UINT8 *) base);
    renderBlocks(model, (UINT16 *) base);
}


/*****************************************/
/********** TETROMINO FUNCTIONS **********/
/*****************************************/

/**
 * renderTetromino
 * 
 * Purpose: Renders the given tetromino on the screen at its current position.
 * Input: t - A pointer to the tetromino to be rendered.
 *        base - The base address of the screen where the tetromino will be rendered.
 * Output: None.
 * Assumptions: Assumes a valid tetromino pointer and a properly initialized screen buffer.
 */
void renderTetromino(const Tetromino *t, Play_area *p, UINT16 *base) {
    int i;
    for(i = 0; i < TETROMINO_SIZE; i++) {
        plot_bitmap16(base, p->arena[t->blocks[i].arenaX]->screenX, p->arena[t->blocks[i].arenaY]->screenY, block_bitmap);
    }
}


/**
 * clearTetrominoRender
 * 
 * Purpose: Clears the render of the given tetromino on the screen at its current position.
 * Input: t - A pointer to the tetromino to be cleared.
 *        base - The base address of the screen where the tetromino will be rendered.
 * Output: None.
 * Assumptions: Assumes a valid tetromino pointer and a properly initialized screen buffer.
 */
void clearTetrominoRender(const Tetromino *t, Play_area *p, UINT16 *base) {
    int i;
    for(i = 0; i < TETROMINO_SIZE; i++) {
        clear_region16(base, p->arena[t->blocks[i].arenaX]->screenX, p->arena[t->blocks[i].arenaY]->screenY);
    }
}


/*****************************************/
/********** PLAY AREA FUNCTIONS **********/
/*****************************************/

/**
 * renderPlayArea
 * 
 * Purpose: Renders the tetris play area arena shape on the screen.
 * Input: playArea - A pointer to the play area arena to be rendered.
 *        base - The base address of the screen where the play area will be rendered.
 * Output: None.
 * Assumptions: Assumes a valid play area pointer and a properly initialized screen buffer.
 */
void renderPlayArea(const Game_Model *model, UINT8 *base) {
    plot_rectangle(base, model->p.screenX, model->p.screenY, model->p.width, model->p.height);
}


/**
 * renderNextTetrominoArea
 * 
 * Purpose: Renders the area where the next tetromino will be displayed on the screen. 
 *          This function draws a rectangle that represents the boundary of the next 
 *          tetromino display area.
 * Input: ntd - A constant pointer to the Next_tetrom_display structure containing the 
 *              display area properties.
 *        base - A pointer to the base address of the graphics buffer where the rectangle
 *               will be plotted.
 * Output: None.
 * Assumptions: Assumes that 'ntd' points to a valid Next_tetrom_display structure and 'base' points to a valid graphics buffer.
 *              The function 'plot_rectangle' is used for drawing and it's assumed to take the graphics buffer base address, 
 *              x and y coordinates, width, and height as its parameters, in order to draw the rectangle on the screen.
 */
void renderNextTetrominoArea(const Game_Model *model, UINT8 *base) {
    plot_rectangle(base, model->ntd.screenX, model->ntd.screenY, model->ntd.width, model->ntd.height);
}

/**
 * renderOccupiedBlocks
 * 
 * Purpose: Renders all occupied blocks in the play area.
 * Input: t - A pointer to the tetromino to be rendered.
 *        base - The base address of the screen where the tetromino will be rendered.
 * Output: None.
 * Assumptions: Assumes a valid tetromino pointer and a properly initialized screen buffer.
 */
void renderBlocks(const Game_Model *model, UINT16 *base) {
    int x, y, isOccupied, isTetromino;
    for(y = 0; y <= PLAY_AREA_MAX_Y; y++) {
        for(x = 0; x <= PLAY_AREA_MAX_X; x++) {
            isOccupied = isPositionOccupied(&model->p, x, y);
            isTetromino = isPositionTetromino(&model->p, x, y);
            if (isOccupied || isTetromino) {
                plot_bitmap16(base, model->p.arena[x][y].screenX, model->p.arena[x][y].screenY, block_bitmap);
            } else if (!isOccupied) {
                clear_region16(base, model->p.arena[x][y].screenX, model->p.arena[x][y].screenY);
            }
        }
    }
}


/*************************************/
/********** SCORE FUNCTIONS **********/
/*************************************/

/**
 * renderScoreDisplay
 * 
 * Purpose: Renders the score display area on the screen.
 * Input: sd - A pointer to the score display to be rendered.
 *        base - The base address of the screen where the score display will be rendered.
 * Output: None.
 * Assumptions: Assumes a valid score display pointer and a properly initialized screen buffer.
 */
void renderScoreDisplay(const Game_Model *model, UINT8 *base) {
    plot_rectangle(base, model->sd.screenX, model->sd.screenY, model->sd.width, model->sd.height);
}

/**
 * renderTopScoreLabel
 * 
 * Purpose: Renders the top score label on the screen.
 * Input: tsl - A pointer to the top score label to be rendered.
 *        base - The base address of the screen where the top score label will be rendered.
 * Output: None.
 * Assumptions: Assumes a valid top score label pointer and a properly initialized screen buffer.
 */
void renderTopScoreLabel(const Game_Model *model,  UINT8 *base) {
    int i, x;
    for(x = model->tsl.screenX, i = 0; model->tsl.top_score_label_string[i] != '\0'; x += 8, i++) {
        clear_region8(base, x, model->tsl.screenY);
        plot_bitmap8(base, x, model->tsl.screenY, GLYPH_START(model->tsl.top_score_label_string[i]));
    }
}

/**
 * renderTopScoreNumString
 * 
 * Purpose: Renders the top score numerical string on the screen.
 * Input: tss - A pointer to the top score string to be rendered.
 *        base - The base address of the screen where the top score string will be rendered.
 * Output: None.
 * Assumptions: Assumes a valid top score string pointer and a properly initialized screen buffer.
 */
void renderTopScoreNumString(const Game_Model *model,  UINT8 *base) {
    int i, x;
    for(x = model->tss.screenX, i = 0; model->tss.top_score_num_string[i] != '\0'; x += 8, i++) {
        clear_region8(base, x, model->tss.screenY);
        plot_bitmap8(base, x, model->tss.screenY, GLYPH_START(model->tss.top_score_num_string[i]));
    }
}

/**
 * renderCurrentScoreLabel
 * 
 * Purpose: Renders the current score label on the screen.
 * Input: csl - A pointer to the current score label to be rendered.
 *        base - The base address of the screen where the current score label will be rendered.
 * Output: None.
 * Assumptions: Assumes a valid current score label pointer and a properly initialized screen buffer.
 */
void renderCurrentScoreLabel(const Game_Model *model,  UINT8 *base) {
    int i, x;
    for(x = model->csl.screenX, i = 0; model->csl.current_score_label_string[i] != '\0'; x += 8, i++) {
        clear_region8(base, x, model->csl.screenY);
        plot_bitmap8(base, x, model->csl.screenY, GLYPH_START(model->csl.current_score_label_string[i]));
    }
}

/**
 * renderCurrentScoreNumString
 * 
 * Purpose: Renders the current score numerical string on the screen.
 * Input: css - A pointer to the current score string to be rendered.
 *        base - The base address of the screen where the current score string will be rendered.
 * Output: None.
 * Assumptions: Assumes a valid current score string pointer and a properly initialized screen buffer.
 */
void renderCurrentScoreNumString(const Game_Model *model,  UINT8 *base) {
    int i, x;
    for(x = model->css.screenX, i = 0; model->css.current_score_num_string[i] != '\0'; x += 8, i++) {
        clear_region8(base, x, model->css.screenY);
        plot_bitmap8(base, x, model->css.screenY, GLYPH_START(model->css.current_score_num_string[i]));
    }
}

/**
 * renderLevelLabel
 * 
 * Purpose: Renders the level label on the screen.
 * Input: lvlL - A pointer to the level label to be rendered.
 *        base - The base address of the screen where the level label will be rendered.
 * Output: None.
 * Assumptions: Assumes a valid level label pointer and a properly initialized screen buffer.
 */
void renderLevelLabel(const Game_Model *model,  UINT8 *base) {
    int i, x;
    for(x = model->lvlL.screenX, i = 0; model->lvlL.level_label_string[i] != '\0'; x += 8, i++) {
        clear_region8(base, x, model->lvlL.screenY);
        plot_bitmap8(base, x, model->lvlL.screenY, GLYPH_START(model->lvlL.level_label_string[i]));
    }
}

/**
 * renderLevelNumString
 * 
 * Purpose: Renders the level numerical string on the screen.
 * Input: lvlS - A pointer to the level string to be rendered.
 *        base - The base address of the screen where the level string will be rendered.
 * Output: None.
 * Assumptions: Assumes a valid level string pointer and a properly initialized screen buffer.
 */
void renderLevelNumString(const Game_Model *model,  UINT8 *base) {
    int i, x;
    for(x = model->lvlS.screenX, i = 0; model->lvlS.level_num_string[i] != '\0'; x += 8, i++) {
        clear_region8(base, x, model->lvlS.screenY);
        plot_bitmap8(base, x, model->lvlS.screenY, GLYPH_START(model->lvlS.level_num_string[i]));
    }
}

/**
 * renderScoreDisplayValues
 * 
 * Purpose: Renders all score-related display elements on the screen, 
 *          including top score label and number char string, 
 *          current score label and number char string, 
 *          and level label and number char string.
 * Input: model - Main game model wrapper for all game objects.
 *        base - The base address of the screen buffer where the score display elements will be rendered.
 * Output: None.
 * Assumptions: Assumes valid pointers for all input parameters and a properly initialized screen buffer.
 */
void renderScoreDisplayValues(const Game_Model *model, UINT8 *base) {
    int i, x;
    renderTopScoreLabel(model, base);
    renderTopScoreNumString(model, base);
    renderCurrentScoreLabel(model, base);
    renderCurrentScoreNumString(model, base);
    renderLevelLabel(model, base);
    renderLevelNumString(model, base);
}
