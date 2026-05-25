#ifndef TETRIS_h
#define TETRIS_h

#include "model.h"


/**
 * @name    get_time
 * 
 * @brief   Retrieves the current time from the timer register.
 * 
 * @details This function accesses a timer register at a specific memory address (0x462),
 *          retrieves its value, and returns it as the current time.
 * 
 * @return  Returns the current time value from the timer register.
 */
unsigned long get_time();  /* Tested: Yes */


/**
 * @name    time_difference
 * 
 * @brief   Computes the difference between two time points.
 * 
 * @details This function calculates the difference between a 'timeNow' global variable
 *          and a 'timeThen' global variable, indicating the elapsed time.
 * 
 * @return  Returns the time difference between 'timeNow' and 'timeThen'.
 */
long time_difference();  /* Tested: Yes */


/**
 * @name    alignMemory
 * @param   memory Pointer to a memory address that needs alignment.
 * 
 * @brief   Aligns the memory pointer to the nearest 256-byte boundary.
 * 
 * @details Checks the current address pointed to by 'memory' and adjusts it to align
 *          to the next 256-byte boundary if it is not already aligned.
 * 
 * @return  None.
 */
void alignMemory(unsigned char **memory);  /* Tested: Yes */


/**
 * @name    do_vbl
 * 
 * @brief   Handles tasks after a vertical blank interrupt.
 * 
 * @details Updates game model and music after a vertical blank has occurred. It sets a flag
 *          to indicate that the next game state should be rendered.
 * 
 * @note    This function should be installed at vector #28 to be called by the vertical blank ISR.
 * 
 * @return  None.
 */
void do_vbl();  /* Tested: Yes */

#endif