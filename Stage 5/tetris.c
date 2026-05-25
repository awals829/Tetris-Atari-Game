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

unsigned long *timer = (long *)0x462, timeNow, timeThen, timeDifference;

#define QUIT 0x1B /* ESC */
#define LEFT 0x61 /* a key */
#define RIGHT 0x64 /* d key */
#define DOWN 0x73 /* s key */
#define ROTATE_CWISE 0x78 /* x key */
#define ROTATE_CCWISE 0x7A /* z key */

UINT8 bufferAlloc[32256];

int main() {

    UINT8 *buffer = bufferAlloc;
    UINT8 *base = Physbase();
    UINT8 *currentScreen = base;
    Game_Model model;
    char input;

    alignMemory(&buffer);

    initializeAllEvent(&model, get_time());
    spawnTetrominoEvent(&model);
    renderAllObjects(&model, base);

    timeThen = get_time();

    while(model.isGameOver == FALSE) {

        /********* Asyncronous Event Requests Happen Here *********/
        /* If sync event, do something... */
        if(Cconis()) {

            input = (char)Cnecin();

            if(input == QUIT) {
                printf("Char input as hex code is: %X\n", input);
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
        if(time_difference() > 0) {
            updateModel(&model, get_time());

            if(currentScreen == base)
                currentScreen = buffer;
            else
                currentScreen = base;
            
            renderAllObjects(&model, currentScreen);
            Setscreen(-1, currentScreen, -1);
            Vsync();


            /* Testing a steadily increasing difficulty curve */
            if(time_difference() >= 70) {
                if(model.p.gravity > 4) {
                    model.p.gravity -= 1;
                }
                timeThen = get_time();
            }
        }
    }
    printf("*** GAME OVER ***\n");
    Setscreen(-1, base, -1);
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



