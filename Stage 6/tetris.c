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

extern void clear_screen(unsigned char*);

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
    UINT8 *buffer = bufferAlloc;
    UINT8 *base = Physbase();
    UINT8 *currentScreen = base;
    Game_Model model;

    /* Generate a random seed value based on the memory location value chosen */
    srand((unsigned int) buffer);
    alignMemory(&buffer);

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
            Setscreen(-1, currentScreen, -1);
            Vsync();

            /* Sync-event has occured, reset the old time to the current time */
            timeThen = get_time();
        }
    }

    printf("*** GAME OVER ***\n");
    Setscreen(-1, base, -1); /* Return to the main frame buffer after the game has run */
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