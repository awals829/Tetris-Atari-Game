/*
 * File: input.h
 * Author: Marusia Luciuk, Andrew Walsh 
 * Team Members: Marusia Luciuk, Andrew Walsh 
 * 
 * This file will contain the definitions of the input.h file.
 */
#include <osbind.h>
#include "input.h"

/* Partial example of ripped scancode ascii values */
/*
unsigned int ascii[256] = {
    0x0000, 0x001B, 0x0031, 0x0032, 0x0033, 0x0034, 0x00036, ...
} (nothing), esc,   1,      2,      3,      4,      5,       ... 
*/

/* To replace using IKBD status registers and information */
int isKeyPressed() {
    return (Cconis());
}

/* To replace using IKBD status registers and information */
char getKey() {
    return (char)Cnecin();
}
