/*
 * File: render.c
 * Author: Andrew Walsh, Marusia Luciuk
 * Team Members: Marusia Luciuk, Andrew Walsh
 *
 * This file contains definitions for all render functions
 * used in the tetris game. These will render model objects
 * to the screen for visualization.
 * 
 */

#include "render.h"
#include "assets.h"
#include "model.h"
#include "raster.h"
#include "font.h"

/**
 * renderTetromino
 * 
 * Purpose: Renders the given tetromino on the screen at its current position.
 * Input: t - A pointer to the tetromino to be rendered.
 *        base - The base address of the screen where the tetromino will be rendered.
 * Output: None.
 * Assumptions: Assumes a valid tetromino pointer and a properly initialized screen buffer.
 */
void renderTetromino(const Tetromino *t, UINT16 *base) {
    int i;
    for(i = 0; i < TETROMINO_SIZE; i++) {
        plot_bitmap16(base, t->blocks[i].screenX, t->blocks[i].screenY, block_bitmap);
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
void clearTetrominoRender(const Tetromino *t, UINT16 *base) {
    int i;
    for(i = 0; i < TETROMINO_SIZE; i++) {
        clear_region16(base, t->blocks[i].screenX, t->blocks[i].screenY);
    }
}

/**
 * renderPlayArea
 * 
 * Purpose: Renders the tetris play area arena shape on the screen.
 * Input: playArea - A pointer to the play area arena to be rendered.
 *        base - The base address of the screen where the play area will be rendered.
 * Output: None.
 * Assumptions: Assumes a valid play area pointer and a properly initialized screen buffer.
 */
void renderPlayArea(const Play_area *p, unsigned char *base) {
    plot_rectangle(base, p->screenX, p->screenY, p->width, p->height);
}

void renderNextTetrominoArea(const Next_tetrom_display *ntd, unsigned char *base) {
    plot_rectangle(base, ntd->screenX, ntd->screenY, ntd->width, ntd->height);
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
void renderBlocks(const Play_area *p, UINT16 *base) {
    int x, y, isOccupied, isTetromino;
    for(y = 0; y <= PLAY_AREA_MAX_Y; y++) {
        for(x = 0; x <= PLAY_AREA_MAX_X; x++) {
            isOccupied = isPositionOccupied(p, x, y);
            isTetromino = isPositionTetromino(p, x, y);
            if (isOccupied && !isTetromino) {
                plot_bitmap16(base, p->arena[x][y].screenX, p->arena[x][y].screenY, block_bitmap);
            } else if (!isOccupied) {
                clear_region16(base, p->arena[x][y].screenX, p->arena[x][y].screenY);
            }
        }
    }
}

/**
 * renderScoreDisplay
 * 
 * Purpose: Renders the score display area on the screen.
 * Input: sd - A pointer to the score display to be rendered.
 *        base - The base address of the screen where the score display will be rendered.
 * Output: None.
 * Assumptions: Assumes a valid score display pointer and a properly initialized screen buffer.
 */
void renderScoreDisplay(const Score_display *sd, unsigned char *base) {
    plot_rectangle(base, sd->screenX, sd->screenY, sd->width, sd->height);
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
void renderTopScoreLabel(const Top_score_label *tsl,  UINT8* base) {
    int i, x;
    for(x = tsl->screenX, i = 0; tsl->top_score_label_string[i] != '\0'; x += 8, i++) {
        clear_region8(base, x, tsl->screenY);
        plot_bitmap8(base, x, tsl->screenY, GLYPH_START(tsl->top_score_label_string[i]));
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
void renderTopScoreNumString(const Top_score_string *tss,  UINT8* base) {
    int i, x;
    for(x = tss->screenX, i = 0; tss->top_score_num_string[i] != '\0'; x += 8, i++) {
        clear_region8(base, x, tss->screenY);
        plot_bitmap8(base, x, tss->screenY, GLYPH_START(tss->top_score_num_string[i]));
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
void renderCurrentScoreLabel(const Current_score_label *csl,  UINT8* base) {
    int i, x;
    for(x = csl->screenX, i = 0; csl->current_score_label_string[i] != '\0'; x += 8, i++) {
        clear_region8(base, x, csl->screenY);
        plot_bitmap8(base, x, csl->screenY, GLYPH_START(csl->current_score_label_string[i]));
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
void renderCurrentScoreNumString(const Current_score_string *css,  UINT8* base) {
    int i, x;
    for(x = css->screenX, i = 0; css->current_score_num_string[i] != '\0'; x += 8, i++) {
        clear_region8(base, x, css->screenY);
        plot_bitmap8(base, x, css->screenY, GLYPH_START(css->current_score_num_string[i]));
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
void renderLevelLabel(const Level_label *lvlL,  UINT8* base) {
    int i, x;
    for(x = lvlL->screenX, i = 0; lvlL->level_label_string[i] != '\0'; x += 8, i++) {
        clear_region8(base, x, lvlL->screenY);
        plot_bitmap8(base, x, lvlL->screenY, GLYPH_START(lvlL->level_label_string[i]));
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
void renderLevelNumString(const Level_string *lvlS,  UINT8* base) {
    int i, x;
    for(x = lvlS->screenX, i = 0; lvlS->level_num_string[i] != '\0'; x += 8, i++) {
        clear_region8(base, x, lvlS->screenY);
        plot_bitmap8(base, x, lvlS->screenY, GLYPH_START(lvlS->level_num_string[i]));
    }
}

/**
 * renderScoreDisplayValues
 * 
 * Purpose: Renders all score-related display elements on the screen, 
 *          including top score label and number char string, 
 *          current score label and number char string, 
 *          and level label and number char string.
 * Input: tsl - A pointer to the top score label.
 *        tss - A pointer to the top score string.
 *        csl - A pointer to the current score label.
 *        css - A pointer to the current score string.
 *        lvlL - A pointer to the level label.
 *        lvlS - A pointer to the level string.
 *        base - The base address of the screen buffer where the score display elements will be rendered.
 * Output: None.
 * Assumptions: Assumes valid pointers for all input parameters and a properly initialized screen buffer.
 */
void renderScoreDisplayValues(const Top_score_label *tsl, const Top_score_string *tss, 
                              const Current_score_label *csl, const Current_score_string *css, 
                              const Level_label *lvlL, const Level_string *lvlS, 
                              UINT8 *base) {
    int i, x;
    renderTopScoreLabel(tsl, base);
    renderTopScoreNumString(tss, base);
    renderCurrentScoreLabel(csl, base);
    renderCurrentScoreNumString(css, base);
    renderLevelLabel(lvlL, base);
    renderLevelNumString(lvlS, base);
}