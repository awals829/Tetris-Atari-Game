/*
 * File: raster.h
 * Author: Andrew Walsh, Marusia Luciuk
 * Team Members: Marusia Luciuk, Andrew Walsh
 *
 * This file contains function declarations for plotting pixels, 
 * bitmaps, and geometric shapes on a raster display on the STeem 
 * system display.
 */

#ifndef RASTER_H
#define RASTER_H

#include "types.h"


/* ====================================================== */
/* ====================================================== */


/**
 * @name    plot_pixel8_RS
 * @param   base - pointer to an address location of the screen.
 * @param   x - x-coordinate on the screen.
 * @param   y - y-coordinate on the screen.
 * @return  None
 * @brief   Plots a pixel to the requested (x, y) location of the
 *          screen without removing prior plotted objects.
 * 
*/
void plot_pixel8_RShift(UINT8 *base, int x, int y);


/* ====================================================== */
/* ====================================================== */


/**
 * @name    plot_pixel8_LS
 * @param   base - pointer to an address location of the screen.
 * @param   x - x-coordinate on the screen.
 * @param   y - y-coordinate on the screen.
 * @return  None
 *
 * @brief   Plots a pixel to the requested (x, y) location of the
 *          screen without removing prior plotted objects.
 * 
*/
void plot_pixel8_LShift(UINT8 *base, int x, int y);


/* ====================================================== */
/* ====================================================== */


/**
 * @name    plot_bitmap8 
 * @param   base - pointer to an address location of the screen.
 * @param   x - x-coordinate on the screen.
 * @param   y - y-coordinate on the screen.
 * @param   bitmap - 8x8 bitmap to be printed to the screen.
 *                   When using fonts, provide the function
 *                   GLYPH_START(i) method from font.h header file 
 *                   as the bitmap.
 * @return  None
 * 
 * @brief   The function will print across the entirety 
 *          of a single 1-byte char-sized address location if the
 *          x-coordinate is divisible by 8-bits. However, if the 
 *          x-coordinate is not divisible by 8, then the function 
 *          will print the bitmap correctly across multiple address 
 *          locations keeping the 8x8 image accurate.
 * 
 * @note    No screen limit checking is done. Must be done
 *          by the user.
 * 
*/
void plot_bitmap8(UINT8 *base, 
                    int x, int y,
                    const UINT8 *bitmap);


/* ====================================================== */
/* ====================================================== */


/**
 * @name    clear_bitmap8 
 * @param   base - pointer to an address location of the screen.
 * @param   x - x-coordinate on the screen.
 * @param   y - y-coordinate on the screen.
 * @param   bitmap - 8x8 bitmap to be printed to the screen
 * @return  None
 * 
 * @brief   The purpose of this function is to clear a prior
 *          printed bitmap and clear it without removing any
 *          other plotted pixels in the same location. When
 *          clearing a specific bitmap, you must proved the
 *          same bitmap that needs to be cleared, as well
 *          as the same coordinates.
 * 
 * @note    No screen limit checking is done. Must be done
 *          by the user.
 * 
*/
void clear_bitmap8(UINT8 *base, 
                    int x, int y,
                    const UINT8 *bitmap);


/* ====================================================== */
/* ====================================================== */


/**
 * @name    clear_region8
 * @param   base - pointer to an address location of the screen.
 * @param   x - x-coordinate on the screen.
 * @param   y - y-coordinate on the screen.
 * @return  None
 * 
 * @brief   The region given at the x to x + 8 pixels and 
 *          y to y + 8 pixels will be completely set the bits
 *          to all 0's. This will clear the region to a white
 *          background.
 * 
 * @note    No screen limit checking is done. Must be done
 *          by the user.
 * 
*/
void clear_region8(UINT8 *base, 
                    int x, int y);


/* ====================================================== */
/* ====================================================== */


/**
 * @name    plot_bitmap16 
 * @param   base - pointer to an address location of the screen.
 * @param   x - x-coordinate on the screen.
 * @param   y - y-coordinate on the screen.
 * @param   bitmap - 16x16 bitmap to be printed to the screen
 * @return  None
 * 
 * @brief   The function will print either across the entirety 
 *          of a single 2-byte word-sized address location if the
 *          x-coordinate is divisible by 16-bits. 
 *          Alternatively, if the x-coordinate is not divisible by 16, 
 *          then the function will print the bitmap correctly across 
 *          multiple address locations keeping the 16x16 image accurate.
 * 
 * @note    No screen limit checking is done. Must be done
 *          by the user.
 * 
*/
void plot_bitmap16(UINT16 *base, 
                    int x, int y,
                    const UINT16 *bitmap);


/* ====================================================== */
/* ====================================================== */


/**
 * @name    clear_bitmap16 
 * @param   base - pointer to an address location of the screen.
 * @param   x - x-coordinate on the screen.
 * @param   y - y-coordinate on the screen.
 * @param   bitmap - 8x8 bitmap to be printed to the screen
 * @return  None
 * 
 * @brief   The purpose of this function is to clear a prior
 *          printed bitmap and clear it without removing any
 *          other plotted pixels in the same location. When
 *          clearing a specific bitmap, you must proved the
 *          same bitmap that needs to be cleared, as well
 *          as the same coordinates.
 * 
 * @note    No screen limit checking is done. Must be done
 *          by the user.
 * 
*/
void clear_bitmap16(UINT16 *base, 
                    int x, int y,
                    const UINT16 *bitmap);


/* ====================================================== */
/* ====================================================== */


/**
 * @name    clear_region16
 * @param   base - pointer to an address location of the screen.
 * @param   x - x-coordinate on the screen.
 * @param   y - y-coordinate on the screen.
 * @return  None
 * 
 * @brief   The region given at the x to x + 16 pixels and 
 *          y to y + 16 pixels will be completely set the bits
 *          to all 0's. This will clear the region to a white
 *          background.
 * 
 * @note    No screen limit checking is done. Must be done
 *          by the user.
 * 
*/
void clear_region16(UINT16 *base, 
                    int x, int y);


/* ====================================================== */
/* ====================================================== */


/**
 * @name    plot_vline  
 * @param   base - pointer to an address location of the screen.
 * @param   x - x-coordinate on the screen.
 * @param   y1 - y1-coordinate on the screen.
 * @param   y2 - y2-coordinate on the screen.
 * @return  None
 * 
 * @brief   Plots a vertical line at the x-coordinate, that
 *          ranges from the one y-coordinate to another.
 *          The order of the y-coordinates does not matter,
 *          y1 can be greater than or less than y2.
 * 
 * @note    No screen limit checking is done. Must be done
 *          by the user. (Function definition contains commented 
 *          out screen checking conditions)
 * 
*/
void plot_vline(UINT8 *base, int x, int y1, int y2);


/* ====================================================== */
/* ====================================================== */


/**
 * @name    plot_hline  
 * @param   base - pointer to an address location of the screen.
 * @param   x1 - x1-coordinate on the screen.
 * @param   x2 - x2-coordinate on the screen.
 * @param   y - y-coordinate on the screen.
 * @return  None
 * 
 * @brief   Plots a horizontal line at the y-coordinate, that
 *          ranges from the one x-coordinate to another.
 *          The order of the x-coordinates does not matter,
 *          x1 can be greater than or less than x2.
 * 
 *  @note   No screen limit checking is done. Must be done
 *          by the user. (Function definition contains commented 
 *          out screen checking conditions)
 * 
*/
void plot_hline(UINT8 *base, int x1, int x2, int y);


/* ====================================================== */
/* ====================================================== */

/**
 * @name    plot_square
 * @param   base - pointer to an address location of the screen.
 * @param   x1 - x1-coordinate on the screen.
 * @param   y - y-coordinate on the screen.
 * @param   size - width and height of square in pixels.
 * @return  None
 * 
 * @brief   plots a simple square shape to the screen from
 *          the starting top-left x and y-coordinates using
 *          the size to plot the full shape.
 * 
 *  @note   No screen limit checking is done. Must be done
 *          by the user. (Function definition contains commented 
 *          out screen checking conditions)
 * 
*/
void plot_square(UINT8 *base, int x, int y, int size);


/* ====================================================== */
/* ====================================================== */

/**
 * @name    plot_rectangle
 * @param   base - pointer to an address location of the screen.
 * @param   x - x-coordinate on the screen.
 * @param   y - y-coordinate on the screen.
 * @param   width - width of rectangle in pixels.
 * @param   height - height of rectangle in pixels.
 * @return  None
 * 
 * @brief   plots a simple rectangle shape to the screen from
 *          the starting top-left x and y-coordinates using
 *          the wdith and height to plot the full shape.
 * 
 *  @note   No screen limit checking is done. Must be done
 *          by the user. (Function definition contains commented 
 *          out screen checking conditions)
 * 
*/
void plot_rectangle(UINT8 *base, int x, int y, int width, int height);


#endif
