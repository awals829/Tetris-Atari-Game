#ifndef TYPES_H
#define TYPES_H


#define SCREEN_WIDTH_MAX 639
#define SCREEN_HEIGHT_MAX 399
#define SCREEN_WIDTH_MIN 0
#define SCREEN_HEIGHT_MIN 0


#define FONT_BITMAP_HEIGHT 8
#define BITMAP_HEIGHT 16


/* 
    Offset Values For 'y' Coordinate Value 
*/
#define Y_OFFSET_CHAR 80
#define Y_OFFSET_WORD 40
#define Y_OFFSET_LONG 20

/*
    Use to find the section horizontally to start printing via 'x' coordinate 
    Ex. x = 32; x >> HORIZONTAL_OFFSET_WORD = 2
*/
#define X_OFFSET_CHAR 3
#define X_OFFSET_WORD 4
#define X_OFFSET_LONG 5


#define BITS_IN_CHAR 8
#define BITS_IN_WORD 16
#define BITS_IN_LONG 32


/* Patterns for printing pixels via shifting */
#define PXL_CHR_PTRN_RS 0x80
#define PXL_WRD_PTRN_RS 0x8000
#define PXL_LW_PTRN_RS 0x8000000


#define PXL_CHR_PTRN_LS 0x01
#define PXL_WRD_PTRN_LS 0x0001
#define PXL_LW_PTRN_LS 0x0000001


#define FILL_CHAR 0xFF /* Fill Black 8 Bits*/
#define FILL_WORD 0xFFFF /* Fill Black 16 Bits*/
#define FILL_LONG 0xFFFFFFFF /* Fill Black 32 Bits*/


#define CLEAR_CHAR 0x00 /* Fill White 8 Bits*/
#define CLEAR_WORD 0x0000/* Fill White 16 Bits*/
#define CLEAR_LONG 0x00000000 /* Fill White 32 Bits*/


typedef unsigned char UINT8;
typedef unsigned int  UINT16;
typedef unsigned long UINT32;


#endif
