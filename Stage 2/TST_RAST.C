#include <stdio.h>
#include <osbind.h>
#include "raster.h"
#include "font.h"

/* Mark's Clear Screen */
extern void clear_screen(unsigned char*);

/* Used For Testing Bitmap Printing Functions*/
UINT16 funky_test_block_bitmap[BITMAP_HEIGHT] =
{
	0xFFFF,
	0x8001,
	0xBFFD,
	0xA005,
	0xAFF5,
	0xA815,
	0xABD5,
	0xAA55,
	0xAA55,
	0xABD5,
	0xA815,
	0xAFF5,
	0xA005,
	0xBFFD,
	0x8001,
	0xFFFF,
};


/* String To Test Font Printing. */
UINT8 string[] = "Score";
char score[6];


/* Assorted Variables For Loops etc. */
int x, y, i, num;


int main()
{
	void *base = Physbase();
	int x, y, i; /* Needed For Looping Tests */

	/* 
	Remove Blinking Cursor And Clears Screen To See Tests
	Pulled From Class Demo's.
	*/
	printf("\033E\033f\n");
	fflush(stdout);




	/*	
		=====================================
		plot_pixel8_RShift Test #1 (Plotting)
		=====================================

		This test should create an 'X' shape in the middle of the
		screen. This should also test that plots placed are not
		removed.
	*/
	

	for(i = 0, x = 319, y = 200; i < 8; i++, x++, y++)
		plot_pixel8_RShift((UINT8 *) base, x, y);

	for(i = 0, x = 326, y = 200; i < 8; i++, x--, y++)
		plot_pixel8_RShift((UINT8 *) base, x, y);


	/* 
	Using Cnecin() as an interrupt in-between the tests.
	Pulled From Class Demo's.
	*/
	Cnecin();
	clear_screen((UINT8 *) base);




	/*	
		===================================================
		plot_pixel8_RShift Test #2 (Clipping / No Overflow)
		===================================================

		This test will try to plot pixels to coordinates outside
		of the bounds of the screen at the each of the edges of the screen.
		Therefore, no wrapping will occur if a diagonal line is made.

		Each line will consist of 8 pixels in a diagonal stepped motion
		near their respective edges of the screen. Each line will start
		3 pixels diagonally offset from each edge. Therefore, each edge 
		should only have 3 visible Pixels and no overflow of 5 pixels 
		should appear on any opposing side.
	*/

	for(i = 0, x = 2, y = 199; i < 8; i++, x--, y--)
		plot_pixel8_RShift((UINT8 *) base, x, y);

	for(i = 0, x = 636, y = 199; i < 8; i++, x++, y++)
		plot_pixel8_RShift((UINT8 *) base, x, y);
	
	Cnecin();
	clear_screen((UINT8 *) base);




	/*
		=============================================================
		plot_bitmap8 Test #1 (Printing Fonts Via String Byte Aligned)
		=============================================================

		This test will try to plot a 8x8 pixel bitmap from the font
		library to any byte aligned x-coordinate and y-coordinate location.
	*/

	x = 352;
	y = 192;
	for(i = 0; string[i] != '\0'; i++, x += 8)
		plot_bitmap8((UINT8 *) base, x, y, GLYPH_START(string[i]));

	Cnecin();
	clear_screen((UINT8 *) base);




	/*
		============================================================
		plot_bitmap8 Test #1 (Printing Fonts Via String Byte Offset)
		============================================================

		This test will try to plot a 8x8 pixel bitmap from the font
		library to any byte offeset x-coordinate and y-coordinate location.
	*/

	x = 354;
	y = 200;
	for(i = 0; string[i] != '\0'; i++, x += 8)
		plot_bitmap8((UINT8 *) base, x, y, GLYPH_START(string[i]));

	Cnecin();
	clear_screen((UINT8 *) base);




	/*
		====================================================
		plot_bitmap8 Test #3 (Printing Fonts Via Char Input)
		====================================================

		This test will try to plot a 8x8 pixel bitmap from the font
		library to any selected x-coordinate and y-coordinate location.
	*/

	plot_bitmap8((UINT8 *) base, 352, 208, GLYPH_START('A'));
	plot_bitmap8((UINT8 *) base, 360, 208, GLYPH_START('B'));
	plot_bitmap8((UINT8 *) base, 368, 208, GLYPH_START('1'));
	plot_bitmap8((UINT8 *) base, 376, 208, GLYPH_START('2'));

	Cnecin();
	clear_screen((UINT8 *) base);




	/*	
		================================================
		plot_bitmap16 Test #1 (Word Aligned Coordinates)
		================================================

		This test will try to plot a 16x16 pixel bitmap
		to any selected x-coordinate that is word aligned.
	*/

	plot_bitmap16((UINT16 *) base, 16, 0, funky_test_block_bitmap);
	plot_bitmap16((UINT16 *) base, 16, 16, funky_test_block_bitmap);
	plot_bitmap16((UINT16 *) base, 32, 16, funky_test_block_bitmap);
	plot_bitmap16((UINT16 *) base, 16, 32, funky_test_block_bitmap);
	plot_bitmap16((UINT16 *) base, 0, 16, funky_test_block_bitmap);

	Cnecin();
	clear_screen((UINT8 *) base);




	/*	
		=================================================
		plot_bitmap16 Test #2 (Word Offset X-Coordinates)
		=================================================

		This test will try to plot a 16x16 pixel bitmap
		to a variety of x-coordinates.
	*/

	plot_bitmap16((UINT16 *) base, 64, 0, funky_test_block_bitmap);
	plot_bitmap16((UINT16 *) base, 72, 0, funky_test_block_bitmap);
	plot_bitmap16((UINT16 *) base, 82, 0, funky_test_block_bitmap);
	plot_bitmap16((UINT16 *) base, 94, 0, funky_test_block_bitmap);
	plot_bitmap16((UINT16 *) base, 108, 0, funky_test_block_bitmap);

	Cnecin();
	clear_screen((UINT8 *) base);




	/*	
		=================================================
		plot_bitmap16 Test #3 (Offset Y-Coordinates)
		=================================================

		This test will try to plot a 16x16 pixel bitmap
		to a variety of selected y-coordinates.
	*/

	plot_bitmap16((UINT16 *) base, 0, 64, funky_test_block_bitmap);
	plot_bitmap16((UINT16 *) base, 0, 72, funky_test_block_bitmap);
	plot_bitmap16((UINT16 *) base, 0, 82, funky_test_block_bitmap);
	plot_bitmap16((UINT16 *) base, 0, 94, funky_test_block_bitmap);
	plot_bitmap16((UINT16 *) base, 0, 108, funky_test_block_bitmap);
	
	Cnecin();
	clear_screen((UINT8 *) base);




	/*	
		=============================================
		plot_hline Test #1 (Byte Aligned Coordinates)
		=============================================

		This test will try to plot a horizontal line
		to any selected coordinate that is byte aligned.
	*/

	plot_hline((UINT8 *) base, 320, 344, 184);
	plot_hline((UINT8 *) base, 328, 344, 184);
	plot_hline((UINT8 *) base, 336, 344, 184);

	Cnecin();
	clear_screen((UINT8 *) base);




	/*	
		============================================
		plot_hline Test #2 (Byte Offset Coordinates)
		============================================

		This test will try to plot a horizontal line
		to any selected coordinate that is not byte aligned.
	*/

	plot_hline((UINT8 *) base, 329, 363, 186);
	plot_hline((UINT8 *) base, 321, 363, 188);
	plot_hline((UINT8 *) base, 314, 363, 190);

	Cnecin();
	clear_screen((UINT8 *) base);




	/*	
		This test could be included if we check coordinate validity.
		We can do this by removing function definition commented
		out code.

		=============================
		plot_hline Test #3 (Clipping)
		=============================

		This test will try to plot a horizontal line in a way
		that should clip and not allow overflow.
	

	plot_hline((UINT8 *) base, 630, 700, 186);
	plot_hline((UINT8 *) base, 650, 700, 188);

	Cnecin();
	clear_screen((UINT8 *) base);
	*/




	/*	
		=============================================
		plot_vline Test #1 (Byte Aligned Coordinates)
		=============================================

		This test will try to plot a vertical line
		to any selected coordinate that is byte aligned.
	*/

	plot_vline((UINT8 *) base, 280, 182, 200);
	plot_vline((UINT8 *) base, 288, 184, 200);
	plot_vline((UINT8 *) base, 296, 186, 200);
	
	Cnecin();
	clear_screen((UINT8 *) base);




	/*	
		============================================
		plot_vline Test #2 (Byte Offset Coordinates)
		============================================

		This test will try to plot a vertical line
		to any selected coordinate that is not byte aligned.
	*/

	plot_vline((UINT8 *) base, 311, 190, 225);
	plot_vline((UINT8 *) base, 319, 194, 225);
	plot_vline((UINT8 *) base, 327, 198, 225);

	Cnecin();
	clear_screen((UINT8 *) base);




	/*	
		===================================
		plot_square Test #1 (Various Plots)
		===================================

		This test should allow varying sizes of squares
		to print anywhere on screen.
	*/

	plot_square((UINT8 *) base, 0, 202, 8);
	plot_square((UINT8 *) base, 0, 202, 16);
	plot_square((UINT8 *) base, 0, 202, 32);
	plot_square((UINT8 *) base, 0, 202, 64);

	Cnecin();
	clear_screen((UINT8 *) base);




	/*	
		==================================
		plot_square Test #2 (Offset Plots)
		==================================

		This test should allow varying sizes of squares
		to print anywhere offset screen.
	*/

	plot_square((UINT8 *) base, 0, 302, 5);
	plot_square((UINT8 *) base, 0, 302, 10);
	plot_square((UINT8 *) base, 0, 302, 15);
	plot_square((UINT8 *) base, 0, 302, 20);

	Cnecin();
	clear_screen((UINT8 *) base);




	/*	
		======================================
		plot_rectangle Test #1 (Various Plots)
		======================================

		This test should allow varying sizes of squares
		to print anywhere on screen.
	*/

	plot_rectangle((UINT8 *) base, 72, 202, 8, 16);
	plot_rectangle((UINT8 *) base, 72, 202, 16, 32);
	plot_rectangle((UINT8 *) base, 72, 202, 32, 63);
	plot_rectangle((UINT8 *) base, 72, 202, 64, 128);

	Cnecin();
	clear_screen((UINT8 *) base);




	/*	
		=====================================
		plot_rectangle Test #2 (Offset Plots)
		=====================================

		This test should allow varying sizes of squares
		to print anywhere on screen.
	*/

	plot_rectangle((UINT8 *) base, 77, 315, 25, 45);
	plot_rectangle((UINT8 *) base, 77, 315, 35, 55);
	plot_rectangle((UINT8 *) base, 77, 315, 45, 65);
	plot_rectangle((UINT8 *) base, 77, 315, 55, 75);

	Cnecin();
	clear_screen((UINT8 *) base);




	/*	
		============================================
		clear_bitmap8 Test #1 (Remove Bitmap8 Plots)
		============================================

		Clears a bitmap8 using the same bitmap and
		coordinates as the original bitmap8. Should
		not remove the pixel plots placed inside the
		bottom loop of the '8' bitmap.
	*/

	plot_pixel8_RShift((UINT8 *) base, 323, 205);
	plot_pixel8_RShift((UINT8 *) base, 322, 205);
	plot_bitmap8((UINT8 *) base, 320, 200, GLYPH_START('8'));

	Cnecin();
	clear_bitmap8((UINT8 *) base, 320, 200, GLYPH_START('8'));

	Cnecin();




	/*	
		============================================
		clear_region8 Test #1 (Remove Bitmap8 Plots)
		============================================

		Clears a region of space sized 8x8 pixels, this 
		should remove the pixel plots placed inside the
		bottom loop of the '8' bitmap. Uses plotted pixels
		not removed from the prior test.
	*/
	plot_bitmap8((UINT8 *) base, 320, 200, GLYPH_START('8'));

	Cnecin();
	clear_region8((UINT8 *) base, 320, 200);

	Cnecin();
	clear_screen((UINT8 *) base);




	/*	
		==============================================
		clear_bitmap16 Test #1 (Remove Bitmap16 Plots)
		==============================================

		Clears a bitmap16 using the same bitmap and
		coordinates as the original bitmap16. Should
		not remove the pixel plots placed inside the
		top left area of the square.
	*/

	plot_pixel8_RShift((UINT8 *) base, 321, 201);
	plot_pixel8_RShift((UINT8 *) base, 322, 201);
	plot_pixel8_RShift((UINT8 *) base, 323, 201);
	plot_pixel8_RShift((UINT8 *) base, 324, 201);
	plot_pixel8_RShift((UINT8 *) base, 325, 201);

	plot_bitmap16((UINT16 *) base, 320, 200, funky_test_block_bitmap);

	Cnecin();
	clear_bitmap16((UINT16 *) base, 320, 200, funky_test_block_bitmap);

	Cnecin();




	/*	
		==============================================
		clear_region16 Test #1 (Remove Bitmap16 Plots)
		==============================================

		Clears a region of space sized 16x16 pixels, this 
		should remove the pixel plots placed inside the
		top left area of the square. Uses plotted pixels not
		removed from the prior test.
	*/
	plot_bitmap16((UINT16 *) base, 320, 200, funky_test_block_bitmap);

	Cnecin();
	clear_region16((UINT16 *) base, 320, 200);

	Cnecin();
	clear_screen((UINT8 *) base);
	
	return 0;
}
