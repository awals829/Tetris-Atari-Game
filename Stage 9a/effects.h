/********************************************************************************
 * File: effects.h
 * Authors: Marusia Luciuk & Andrew Walsh
 * 
 * Purpose: Provides the declarations for sound effect functions utilizing the
 *          YM2149 sound chip for Atari ST. This header defines functions for
 *          playing specific action sounds, responses, melodies, and basslines
 *          in response to game events or actions.
 * 
 * Input: None explicitly; the function internally sets specific registers on the YM2149 
 *        to play the sound.
 * Output: Sound output through the Atari ST's audio hardware. Does not return a value.
 * 
 * Limitations: Dependent on the initialization state of the YM2149 chip. The sound played 
 *              is predefined and not customizable through parameters. The volume and duration
 *              are hardcoded within the function.
 ********************************************************************************/
#ifndef EFFECTS_H
#define EFFECTS_H
#include "psg.h"

void play_response_sound();
void play_action_sound();
void play_melody_loop();
void play_bassline_sequence();

#endif