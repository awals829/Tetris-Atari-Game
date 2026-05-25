/********************************************************************************
 * File: MUSIC_H
 * Purpose: Provides the interface for controlling music playback on the Atari ST
 *          using the YM2149 sound chip. Includes functions to start music
 *          playback and update the music based on a timer.
 * Input: For update_music, the elapsed time since the last update in system
 *        ticks or a unit that allows a 1/70 Hz update rate.
 * Output: Manipulates the YM2149 sound chip to produce a sequence of musical
 *         notes on predefined channels, creating a continuous music playback.
 * Limitations: This interface assumes that the music playback system is
 *              initialized correctly elsewhere. start_music should be called
 *              once before update_music is called in a continuous loop with
 *              consistent timing for smooth playback.
 ********************************************************************************/
#ifndef MUSIC_H
#define MUSIC_H

#include <stdio.h>
#include "effects.h"

/*
* only call start_music once
* call update_music based on a 1/70 Hz time increment.
*/
void start_music();
void update_music(UINT32 timeElapsed);

#endif