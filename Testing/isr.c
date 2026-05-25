/*
 * File: isr.c
 * Author: Marusia Luciuk, Andrew Walsh 
 * Team Members: Marusia Luciuk, Andrew Walsh 
 * 
 * Functional definition for the installing of an ISR into the exception vector table.
 */
#include "isr.h"


/**
 * installVector
 * 
 * Purpose: Installs a new function in the vector exception table at the given vector
 *          table number.
 * Input: num - Vector table number.
 *        vector - Function to install to vector table location.
 * Output: Vector function pointer to the replaced function.
 * Assumptions: Assumes a valid vector number location and a valid vector function parameter.
 */
Vector installVector(int num, Vector vector) {
    Vector orig; /* Storage for the original function in the vector exception table */
    Vector *vectp = (Vector *) ((long) num << 2); /* Multiply num by 4 to get the vector address to replace */
    long old_ssp = Super(0); /* Enter Super Mode, store old ssp */

    orig = *vectp;      /* Store old vector table isr */
    *vectp = vector;    /* Replace old vector table isr with new custom isr */

    Super(old_ssp);     /* Exit Super Mode, restore old ssp */
    return orig;
}
