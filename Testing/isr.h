/*
 * File: isr.h
 * Author: Marusia Luciuk, Andrew Walsh 
 * Team Members: Marusia Luciuk, Andrew Walsh 
 * 
 * Various constants and function prototypes for exception vector handling.
 */
#ifndef ISR_H
#define ISR_H

#include <osbind.h>

/* Vertical Blank vector # */
#define VBL_VECTOR 28 /* Vertical blank vector (See MC68000 Reference Card Exception Vector Assignment Table **Leftmost column**) */

/* Vector function pointer to aid in "holding" vector table functions */
typedef void (*Vector)(); /* Function pointer (Used to create types to point to vector table functions) */

/**
 * @name    installVector
 * @param   num - The vector table memory location to replace.
 * @param   vector - A function to install to the vector table location. 
 * 
 * @brief   Assigns a new function to the chosen vector location in the exception vector table.
*/
Vector installVector(int num, Vector vector); /* Installs the chosen function into the vector table number */

#endif