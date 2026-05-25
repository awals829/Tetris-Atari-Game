#include <stdlib.h>
#include <stdio.h>
#include <osbind.h>
#include "tetris.h"
#include "model.h"
#include "raster.h"
#include "render.h"
#include "font.h"
#include "assets.h"
#include "events.h"
#include "input.h"
#include "isr.h"
#include "psg.h"
#include "music.h"
#include "effects.h"

unsigned long *timer = (long *)0x462, timeNow, timeThen, timeDifference; /* No longer used time variables replaced with VBL ISR */

extern void clear_screen(UINT8 *);  /* Marks clear_qk.s function */
extern void vblisr();               /* Vertical blank isr assembly function in isr_asm.s */  

void do_vbl();

int renderRequest = 1;              /* VBL ISR render request flag after interrupt has occured */

Game_Model model; /* Made global for isr's */

#define QUIT 0x1B          /* ESC */
#define LEFT 0x61          /* a-key */
#define RIGHT 0x64         /* d-key */
#define DOWN 0x73          /* s-key */
#define ROTATE_CWISE 0x78  /* x-key */
#define ROTATE_CCWISE 0x7A /* z-key */

UINT8 bufferAlloc[32256];  /* Allocation of screen memory for buffer */

int main() {
    char input; /* User Input Character storage */
    void *base = (void *)getVideoBase(); /* Sets up the frame buffer base address ($0x003f8000) */
    UINT8 *buffer = bufferAlloc; /* Uses the allocated 32256 bytes of memory as the next frame buffer */
    UINT8 *currentScreen = base; /* Sets up the current screen frame buffer to the base address */

    Vector orig_vector = installVector(VBL_VECTOR, vblisr); /* Install new VBL ISR to exception vector table */

    srand((unsigned int) buffer); /* Generate a random seed value based on the memory location value chosen */
    alignMemory(&buffer); /* Ensures the buffer is a 256-byte aligned address for the video buffer */

    clear_screen((UINT8 *)currentScreen);
    plotSplashScreen(base, splash_screen_bitmap); /* Display the Main Menu splash screen */
    Cnecin();

    initializeAllEvent(&model);
    spawnTetrominoEvent(&model);
    updateModelEvent(&model);
    clear_screen((UINT8 *)currentScreen);
    renderAllObjects(&model, currentScreen);

    while(model.isGameOver == FALSE) {

        /********* Asyncronous Event Requests Happen Here *********/

        /* If the user has input in the buffer */
        if(isKeyPressed()) {

            /* Get the users specified input */
            input = getKey();

            if(input == QUIT) {
                model.isGameOver = TRUE;
            }
            else if(input == LEFT) {
                model.horizontalShift = -1;
            }
            else if(input == RIGHT) {
                model.horizontalShift = 1;
            }
            else if(input == DOWN) {
                model.verticalShift = 1;
            }
            else if(input == ROTATE_CWISE) {
                model.rotate = 1;
            }
            else if(input == ROTATE_CCWISE) {
                model.rotate = -1;
            }
        }

        /********* Synchronous Events Happen Here **********/

        if(renderRequest == 1) {
            /* Swap the current screen buffer starting position */
            if(currentScreen == base)
                currentScreen = buffer;
            else
                currentScreen = base;
        
            clear_screen(currentScreen);
            renderAllObjects(&model, currentScreen);
            setVideoBase((UINT16 *)currentScreen);

            renderRequest = 0;
        }
    }
    
    installVector(VBL_VECTOR, orig_vector); /* Reinstall the old VBL isr into it's vector to restore original system */
    clear_screen(base);
    Setscreen(-1, base, -1); /* Return to the main frame buffer after the game has run */
    plotSplashScreen(base, game_over_splash_bitmap);  /* Display the Game Over splash screen */
    return 0;
}


/**
 * get_time
 * 
 * Purpose: Gets the current running time from the timer register address.
 * Output: None.
 * Assumptions: Assumes a valid pointer to a timer address at 0x462.
 */
unsigned long get_time() {
    unsigned long time, old_ssp;
    old_ssp = Super(0);
    time = *timer;
    Super(old_ssp);
    return time;
}

/**
 * time_difference
 * 
 * Purpose: Checks the 'timeNow' global variable against a 
 *          prior 'timeThen' global variable.
 * Output: None.
 * Assumptions: Assumes two global variables timeNow and timeThen.
 */
long time_difference() {
    return (timeNow - timeThen);
}

/**
 * time_difference
 * 
 * Purpose: Checks the 'timeNow' global variable against a 
 *          prior 'timeThen' global variable.
 * Output: None.
 * Assumptions: Assumes two global variables timeNow and timeThen.
 */
void alignMemory(UINT8 **memory) {
    if(((UINT8)(*memory) & 0xFF) !=0) {
        *memory += (UINT8)(256 - ((UINT8)(*memory) & 0xFF));
    }
}

/**
 * do_vbl
 * 
 * Purpose: Updates the model and updates the music after a vertical blank has occured.
 *          Sets the render request to 1 for rendering the next game state.
 * Output: None.
 * Assumptions: Assumes that this function has been installed at the required vector #28 location
 *              for the vertical blank isr to call.
 */
void do_vbl() {
    if(renderRequest == 0) {
        /* Update the Music Call */
        update_music(1);
        /* Update the Model Call */
        updateModelEvent(&model);
        renderRequest = 1;
    }
}
