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

unsigned long *timer = (long *)0x462, timeNow, timeThen, timeDifference;

extern void clear_screen(UINT8 *);

#define QUIT 0x1B          /* ESC */
#define LEFT 0x61          /* a-key */
#define RIGHT 0x64         /* d-key */
#define DOWN 0x73          /* s-key */
#define ROTATE_CWISE 0x78  /* x-key */
#define ROTATE_CCWISE 0x7A /* z-key */

UINT8 bufferAlloc[32256];

int main() {
    int i;
    char input;
    void *base = (void *)getVideoBase(); /* Sets up the frame buffer base address ($0x003f8000) */
    UINT8 *buffer = bufferAlloc; /* Uses the allocated 32256 bytes of memory as the next frame buffer */
    UINT8 *currentScreen = base; /* Sets up the current screen frame buffer to the base address */
    Game_Model model;

    srand((unsigned int) buffer); /* Generate a random seed value based on the memory location value chosen */
    alignMemory(&buffer); /* Ensures the buffer is a 256-byte aligned address for the video buffer */

    initializeAllEvent(&model);
    spawnTetrominoEvent(&model);
    updateModelEvent(&model);
    renderAllObjects(&model, currentScreen);

    timeThen = get_time();

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

        timeNow = get_time();

        /********* Synchronous Events Happen Here **********/

        /* If the clock has ticked (Occurs every 1/70th of a second) */
        if(time_difference() > 0) {
            /* Swap the current screen buffer starting position */
            if(currentScreen == base)
                currentScreen = buffer;
            else
                currentScreen = base;
            
            updateModelEvent(&model);
            clear_screen(currentScreen);
            renderAllObjects(&model, currentScreen);
            setVideoBase((UINT16 *)currentScreen);

            /* Sync-event has occured, reset the old time to the current time */
            timeThen = get_time();
        }
    }
    
    Setscreen(-1, base, -1); /* Return to the main frame buffer after the game has run */
    printf("*** GAME OVER ***\n");
    return 0;
}
    

unsigned long get_time() {
    unsigned long time, old_ssp;
    old_ssp = Super(0);
    time = *timer;
    Super(old_ssp);
    return time;
}


long time_difference() {
    return (timeNow - timeThen);
}


void alignMemory(UINT8 **memory) {
    if(((UINT8)(*memory) & 0xFF) !=0) {
        *memory += (UINT8)(256 - ((UINT8)(*memory) & 0xFF));
    }
}