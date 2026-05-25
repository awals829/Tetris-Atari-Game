/*
 * File: raster.c
 * Author: Andrew Walsh, Marusia Luciuk
 * Team Members: Marusia Luciuk, Andrew Walsh
 *
 * This file contains function definitions for plotting pixels, 
 * bitmaps, and geometric shapes on a raster display on the STeem 
 * system display.
 */

#include "raster.h"


/* ========================= */
/* ======= Functions  ====== */
/* ========================= */

/**
 * plot_pixel8_RShift
 * 
 * Purpose: Sets a pixel in an 8-bit byte sized display address using a right shift operation.
 * Input: base - Pointer to the base address of the display.
 *        x - X-coordinate of the pixel.
 *        y - Y-coordinate of the pixel.
 * Output: None.
 * Assumptions: Assumes valid display dimensions and pointer to display memory.
 */
void plot_pixel8_RShift(UINT8 *base, int x, int y) {
    if (x >= SCREEN_WIDTH_MIN && x < SCREEN_WIDTH_MAX && 
	y >= SCREEN_HEIGHT_MIN && y < SCREEN_HEIGHT_MAX) {
        *(base + y * Y_OFFSET_CHAR + (x >> X_OFFSET_CHAR)) 
        |= (PXL_CHR_PTRN_RS >> (x & (BITS_IN_CHAR - 1)));
    }
}

/**
 * plot_pixel8_LShift (Using Rshift as primary function if needed, No testing needed currently).
 * 
 * Purpose: Sets a pixel in an 8-bit byte display address using a left shift operation.
 * Input: base - Pointer to the base address of the display.
 *        x - X-coordinate of the pixel.
 *        y - Y-coordinate of the pixel.
 * Output: None.
 * Assumptions: Assumes valid display dimensions and pointer to display memory.
 */
void plot_pixel8_LShift(UINT8 *base, int x, int y) {
    if (x >= SCREEN_WIDTH_MIN && x < SCREEN_WIDTH_MAX && 
	y >= SCREEN_HEIGHT_MIN && y < SCREEN_HEIGHT_MAX) {
        *(base + y * Y_OFFSET_CHAR + (x >> X_OFFSET_CHAR)) 
        |= (PXL_CHR_PTRN_LS << (7 - (x & (BITS_IN_CHAR - 1))));
    }
}


/**
 * plot_bitmap8
 * 
 * Purpose: Plots an 8-bit bitmap on a display.
 * Input: base - Pointer to the base address of the display.
 *        x - X-coordinate of the top-left corner of the bitmap.
 *        y - Y-coordinate of the top-left corner of the bitmap.
 *        bitmap - Pointer to the bitmap data.
 * Output: None.
 * Assumptions: Assumes valid display dimensions and pointer to display memory, 
 *              bitmap, coordinates, and height.
 */
void plot_bitmap8(UINT8 * base,
                    int x, int y,
                    const UINT8 *bitmap)
{
   int offset = (x >> X_OFFSET_CHAR) + (y * Y_OFFSET_CHAR),
   x_pixel_start = (x & (BITS_IN_CHAR-1)),
   i;

   if (x_pixel_start == 0) { /* If x-coordinate is divisible by 8 */
        for(i = 0; i < BITS_IN_CHAR; i++)
            *(base + offset + (i*Y_OFFSET_CHAR)) |= bitmap[i];
   } 
   else /* If x-coordinate is offset */
   {
    for(i = 0; i < BITS_IN_CHAR; i++) {
        *(base + offset + (i*Y_OFFSET_CHAR)) 
        |= bitmap[i] >> x_pixel_start;
        base++; /* Move to the next address to print into */

        *(base + offset + (i*Y_OFFSET_CHAR))
        |= bitmap[i] << (BITS_IN_CHAR - x_pixel_start);
        --base; /* Move to prior address for the next offset of 'y' */
        }
   }
   return;
}


/**
 * clear_bitmap8
 * 
 * Purpose: Clears an 8-bit bitmap from a display.
 * Input: base - Pointer to the base address of the display.
 *        x - X-coordinate of the top-left corner of the bitmap.
 *        y - Y-coordinate of the top-left corner of the bitmap.
 *        bitmap - Pointer to the bitmap data.
 * Output: None.
 * Assumptions: Assumes valid display dimensions and pointer to display memory, 
 *              bitmap, coordinates, and height.
 */
void clear_bitmap8(UINT8 * base,
                    int x, int y,
                    const UINT8 *bitmap)
{
   int offset = (x >> X_OFFSET_CHAR) + (y * Y_OFFSET_CHAR),
   x_pixel_start = (x & (BITS_IN_CHAR-1)),
   i;

   if (x_pixel_start == 0) { /* If x-coordinate is divisible by 16 */
        for(i = 0; i < BITS_IN_CHAR; i++)
            *(base + offset + (i*Y_OFFSET_CHAR)) ^= bitmap[i];
   } 
   else /* If x-coordinate is offset */
   {
    for(i = 0; i < BITS_IN_CHAR; i++) {
        *(base + offset + (i*Y_OFFSET_CHAR)) 
        ^= bitmap[i] >> x_pixel_start;
        base++; /* Move to the next address to print into */

        *(base + offset + (i*Y_OFFSET_CHAR)) 
        ^= bitmap[i] << (BITS_IN_CHAR - x_pixel_start);
        --base; /* Move to prior address for the next offset of 'y' */
        }
   }
   return;
}


/**
 * clear_region8
 * 
 * Purpose: Clears a region entirely in an 8x8 pixel display.
 * Input: base - Pointer to the base address of the display.
 *        x - X-coordinate of the top-left corner of the region.
 *        y - Y-coordinate of the top-left corner of the region.
 * Output: None.
 * Assumptions: Assumes valid display dimensions and pointer to display memory, 
 *              coordinates, and height.
 */
void clear_region8(UINT8 * base,
                    int x, int y)
{
   int offset = (x >> X_OFFSET_CHAR) + (y * Y_OFFSET_CHAR),
   x_pixel_start = (x & (BITS_IN_CHAR-1)),
   i;

   if (x_pixel_start == 0) { /* If x-coordinate is divisible by 8 */
        for(i = 0; i < BITS_IN_CHAR; i++)
            *(base + offset + (i*Y_OFFSET_CHAR)) = CLEAR_CHAR;
   } 
   else /* If x-coordinate is offset */
   {
    for(i = 0; i < BITS_IN_CHAR; i++) {
        *(base + offset + (i*Y_OFFSET_CHAR)) 
        = CLEAR_CHAR >> x_pixel_start;
        base++; /* Move to the next address to print into */

        *(base + offset + (i*Y_OFFSET_CHAR)) 
        = CLEAR_CHAR << (BITS_IN_CHAR - x_pixel_start);
        --base; /* Move to prior address for the next offset of 'y' */
        }
   }
   return;
}


/**
 * plot_bitmap16
 * 
 * Purpose: Plots an 16-bit bitmap on a display.
 * Input: base - Pointer to the base address of the display.
 *        x - X-coordinate of the top-left corner of the bitmap.
 *        y - Y-coordinate of the top-left corner of the bitmap.
 *        bitmap - Pointer to the bitmap data.
 * Output: None.
 * Assumptions: Assumes valid display dimensions and pointer to display memory, 
 *              bitmap, coordinates, and height.
 */
void plot_bitmap16(UINT16 * base,
                    int x, int y,
                    const UINT16 *bitmap)
{
   int offset = (x >> X_OFFSET_WORD) + (y * Y_OFFSET_WORD),
   x_pixel_start = (x & (BITS_IN_WORD-1)),
   i;

   if (x_pixel_start == 0) { /* If x-coordinate is divisible by 16 */
        for(i = 0; i < BITS_IN_WORD; i++)
            *(base + offset + (i*Y_OFFSET_WORD)) |= bitmap[i];
   } 
   else /* If x-coordinate is offset */
   {
    for(i = 0; i < BITS_IN_WORD; i++) {
        *(base + offset + (i*Y_OFFSET_WORD)) 
        |= bitmap[i] >> x_pixel_start;
        base++; /* Move to the next address to print into */

        *(base + offset + (i*Y_OFFSET_WORD)) 
        |= bitmap[i] << (BITS_IN_WORD - x_pixel_start);
        --base; /* Move to prior address for the next offset of 'y' */
        }
   }
   return;
}


/**
 * clear_bitmap16
 * 
 * Purpose: Clears an 16-bit bitmap on a display.
 * Input: base - Pointer to the base address of the display.
 *        x - X-coordinate of the top-left corner of the bitmap.
 *        y - Y-coordinate of the top-left corner of the bitmap.
 *        bitmap - Pointer to the bitmap data.
 * Output: None.
 * Assumptions: Assumes valid display dimensions and pointer to display memory, 
 *              bitmap, coordinates, and height.
 */
void clear_bitmap16(UINT16 * base,
                    int x, int y,
                    const UINT16 *bitmap)
{
   int offset = (x >> X_OFFSET_WORD) + (y * Y_OFFSET_WORD),
   x_pixel_start = (x & (BITS_IN_WORD-1)),
   i;

   if (x_pixel_start == 0) { /* If x-coordinate is divisible by 16 */
        for(i = 0; i < BITS_IN_WORD; i++)
            *(base + offset + (i*Y_OFFSET_WORD)) ^= bitmap[i];
   } 
   else /* If x-coordinate is offset */
   {
    for(i = 0; i < BITS_IN_WORD; i++) {
        *(base + offset + (i*Y_OFFSET_WORD))
        ^= bitmap[i] >> x_pixel_start;
        base++; /* Move to the next address to print into */

        *(base + offset + (i*Y_OFFSET_WORD))
        ^= bitmap[i] << (BITS_IN_WORD - x_pixel_start);
        --base; /* Move to prior address for the next offset of 'y' */
        }
   }
   return;
}


/**
 * clear_region16
 * 
 * Purpose: Clears a region entirely in an 16x16 pixel display.
 * Input: base - Pointer to the base address of the display.
 *        x - X-coordinate of the top-left corner of the region.
 *        y - Y-coordinate of the top-left corner of the region.
 * Output: None.
 * Assumptions: Assumes valid display dimensions and pointer to display memory, 
 *              coordinates, and height.
 */
void clear_region16(UINT16 * base,
                    int x, int y)
{
   int offset = (x >> X_OFFSET_WORD) + (y * Y_OFFSET_WORD),
   x_pixel_start = (x & (BITS_IN_WORD-1)),
   i;

   if (x_pixel_start == 0) { /* If x-coordinate is divisible by 16 */
        for(i = 0; i < BITS_IN_WORD; i++)
            *(base + offset + (i*Y_OFFSET_WORD)) = CLEAR_WORD;
   } 
   else /* If x-coordinate is offset */
   {
    for(i = 0; i < BITS_IN_WORD; i++) {
        *(base + offset + (i*Y_OFFSET_WORD)) 
        = CLEAR_WORD >> x_pixel_start;
        base++; /* Move to the next address to print into */

        *(base + offset + (i*Y_OFFSET_WORD)) 
        = CLEAR_WORD << (BITS_IN_WORD - x_pixel_start);
        --base; /* Move to prior address for the next offset of 'y' */
        }
   }
   return;
}


/**
 * plot_vline
 * 
 * Purpose: Draws a vertical line on the display.
 * Input: base - Pointer to the base address of the display.
 *        x - X-coordinate of the starting point of the line.
 *        y1 - Y-coordinate of the starting point of the line.
 *        y2 - Y-coordinate of the ending point of the line.
 * Output: None.
 * Assumptions: Assumes valid display dimensions and pointer to display memory.
 */
void plot_vline(UINT8 *base, int x, int y1, int y2) {
    
    UINT8 x_bit_location;
    UINT8 *screen_byte_loc;

    if(y1 > y2) {
        int temp = y1;
        y1 = y2;
        y2 = temp;
    }
    x_bit_location = PXL_CHR_PTRN_RS >> (x&7);
    screen_byte_loc = (base + y1*Y_OFFSET_CHAR + (x >> 3));

    for ( ; y1 <= y2; y1++) {
        *screen_byte_loc |= x_bit_location;
        screen_byte_loc = screen_byte_loc + (Y_OFFSET_CHAR);
    }
    return;
}


/**
 * plot_hline
 * 
 * Purpose: Draws a horizontal line on the display.
 * Input: base - Pointer to the base address of the display.
 *        x1 - X-coordinate of the starting point of the line.
 *        x2 - X-coordinate of the ending point of the line.
 *        y - Y-coordinate of the line.
 * Output: None.
 * Assumptions: Assumes valid display dimensions and pointer to display memory.
 */
void plot_hline(UINT8 *base, int x1, int x2, int y) {
    UINT8 pattern1, pattern2, start, end;
    UINT16 offset;

    if(x1 > x2) {
        int temp = x1;
        x1 = x2;
        x2 = temp;
    }
    start = x1 >> X_OFFSET_CHAR;
    end = x2 >> X_OFFSET_CHAR;
    pattern1 = FILL_CHAR >> (x1 & (BITS_IN_CHAR - 1));
    pattern2 = FILL_CHAR << ((BITS_IN_CHAR-1) - (x2 & (BITS_IN_CHAR - 1)));
    offset = y * Y_OFFSET_CHAR;

    if(start == end)
        *(base + start + offset) |= (pattern1 & pattern2);
    else {
        *(base + start + offset) |= pattern1;
        start += 1;
        for( ; start < end; start++)
            *(base + start + offset) |= FILL_CHAR;
        *(base + end + offset) |= pattern2;
    }
    return;
}


/**
 * plot_square
 * Purpose: Draws a square outline at the coordinates on the display.
 * Input: base - Pointer to the base address of the display.
 *        x - X-coordinate of the top-left corner of the square.
 *        y - Y-coordinate of the top-left corner of the square.
 *        size - Size of the square in pixels.
 * Output: None.
 * Assumptions: Assumes valid display dimensions and pointer to display memory.
 */
void plot_square(UINT8 *base, int x, int y, int size) {
    int x2 = (x+size),
    y2 = (y+size);
    plot_hline(base, x, x2, y);
    plot_hline(base, x, x2, y2);
    plot_vline(base, x, y, y2);
    plot_vline(base, x2, y, y2);
}

/**
 * plot_rectangle
 * Purpose: Draws a rectangle outline at the coordinates on the display.
 * Input: base - Pointer to the base address of the display.
 *        x - X-coordinate of the top-left corner of the rectangle.
 *        y - Y-coordinate of the top-left corner of the rectangle.
 *        width - Width of the rectangle in pixels.
 *        height - Height of the rectangle in pixels.
 * Output: None.
 * Assumptions: Assumes valid display dimensions and pointer to display memory.
 */
void plot_rectangle(UINT8 *base, int x, int y, int width, int height) {
    int x2 = (x+width),
    y2 = (y+height);
    plot_hline(base, x, x2, y);
    plot_hline(base, x, x2, y2);
    plot_vline(base, x, y, y2);
    plot_vline(base, x2, y, y2);
}