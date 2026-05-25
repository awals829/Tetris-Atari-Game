/*
 * File: input.h
 * Author: Marusia Luciuk, Andrew Walsh 
 * Team Members: Marusia Luciuk, Andrew Walsh 
 * 
 * This file will contain eventual wrapper functionality from the 
 * status of the IKBD system. Currently utilizes the Cconis() and
 * Cnecin() functionalities as temp runners. The goal will be to utilize
 * the IKBD status registers and their byte information the access
 * ripped Ascii codes places in arrays. The make codes will contain
 * the index of the array, and the return value will be the arrays
 * respective ascii value. Unshifted and shifted values could eventually
 * be handled.
 * 
 * ex. ascii[01] = 0x001B for the 'esc' key
 *     ascii[1E] = 0x0061 for the 'a' key
 * 
 * The input buffer for user inputers will be represented by a circular 
 * queue (array) sized to be 256-bytes. A header and tail position will
 * be used to queue (tail) and dequeue (head) from the input buffer.
 * This queue can query the ascii array table for respective values.
 * 
 */
#ifndef INPUT_H
#define INPUT_H

extern 

/** 
 * @name    isKeyPressed
 * @brief   Checks to determine if a key has been pressed by the user.
*/
int isKeyPressed();

/** 
 * @name    getKey 
 * @brief   Initializes all game objects to default values.
*/
char getKey();

#endif