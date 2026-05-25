/********************************************************************************
 * File: effects.c
 * Authors: Marusia Luciuk & Andrew Walsh
 * Purpose: Provides functions to play specific sound effects using the YM2149
 *          sound chip on Atari ST. Includes actions sounds, responses, melodies,
 *          and basslines for game events.
 * 
 * Functions:
 *      - play_action_sound: Plays a predefined sound effect for in-game actions.
 *      - play_response_sound: Plays a sound effect in response to specific game
 *        events, like clearing a line.
 *      - play_melody_loop: Sequentially plays a set of notes as part of the game's
 *        background music on channel A.
 *      - play_bassline_sequence: Plays a bassline complement to the melody loop
 *        on channel B, enhancing the background music.
 * 
 * Note:
 *      - These functions directly manipulate the YM2149 sound chip, setting
 *        frequencies, volumes, and envelope shapes to produce the desired
 *        sound effects. 
 *      - Timing and sequencing for melody and bassline loops are managed
 *        externally, requiring periodic calls to update the music playback.
 ********************************************************************************/
#include "effects.h"

/********************************************************************************
 * Name: play_action_sound
 * Purpose: Plays a sound effect designated for general actions taken in the game,
 *          such as selecting a menu option or rotating a game piece.
 * Input: None.
 * Output: A specific sound effect is produced through the YM2149 sound chip.
 * Limitations: The sound effect is hardcoded and cannot be customized without
 *              modifying the function's implementation.
 ********************************************************************************/
void play_action_sound() {
    set_tone(CH_C, G6); 
    set_volume(CH_C, 0x1A);    
    enable_channel(CH_C, TONE_ON, NOISE_OFF); 
    set_envelope(0x3FF, 0x0C);
}

/********************************************************************************
 * Name: play_response_sound
 * Purpose: Plays a sound effect in response to specific game events, like
 *          clearing a line in a puzzle game.
 * Input: None.
 * Output: A multi-channel sound effect combining tones and noise is produced,
 *         indicating a significant game event.
 * Limitations: The sound effect is predefined and tailored for line-clearing
 *              events. Modifying it for other events requires changes to the
 *              function code.
 ********************************************************************************/
void play_response_sound() {
    set_tone(CH_A, G4);
    set_tone(CH_B, B4);  
    set_tone(CH_C, D5);  
    set_noise(0x0F);
    set_volume(CH_A, 0x1A);
    set_volume(CH_B, 0x1A);
    set_volume(CH_C, 0x1A);
    set_envelope (0xF00, 0x09);
    enable_channel(CH_A, TONE_ON, NOISE_ON);
    enable_channel(CH_B, TONE_ON, NOISE_ON);
    enable_channel(CH_C, TONE_OFF, NOISE_ON);
}

/********************************************************************************
 * Name: play_melody_loop
 * Purpose: Initiates the playback of a melody loop, contributing to the game's
 *          background music on channel A.
 * Input: None.
 * Output: A sequence of musical notes is played, forming part of the background
 *         music. The loop is continuous and requires external control to stop.
 * Limitations: obviously this sounds like shit and barely works 
 ********************************************************************************/
void play_melody_loop(){
    set_tone(CH_A, D6);
    set_volume(CH_A, 0x1A);
    enable_channel(CH_A, TONE_ON, NOISE_ON);
    set_envelope(0x3FF, 0x0C); 
    
    set_tone(CH_A, REST);
    set_envelope(0x0FF, 0x0C);
   
    set_tone(CH_A, G5);
    set_envelope(0x1FF, 0x0C); 

    set_tone(CH_A, REST);
    set_envelope(0x0FF, 0x0C);


    set_tone(CH_A, F6);
    set_envelope(0x1FF, 0x0C); 

    set_tone(CH_A, REST);
    set_envelope(0x0FF, 0x0C);

    set_tone(CH_A, D6);
    set_envelope(0x3FF, 0x0C); 

    set_tone(CH_A, REST);
    set_envelope(0x0FF, 0x0C);

    set_tone(CH_A, As5_Bb5);
    set_envelope(0x1FF, 0x0C); 

    set_tone(CH_A, REST);
    set_envelope(0x0FF, 0x0C);

    set_tone(CH_A, G6);
    set_envelope(0x1FF, 0x0C); 

    set_tone(CH_A, REST);
    set_envelope(0x0FF, 0x0C);


    set_tone(CH_A, F6);
    set_envelope(0x1FF, 0x0C); 

    set_tone(CH_A, REST);
    set_envelope(0x0FF, 0x0C);


    set_tone(CH_A, As6_Bb6);
    set_envelope(0x1FF, 0x0C); 

    set_tone(CH_A, REST);
    set_envelope(0x0FF, 0x0C);

   
    set_tone(CH_A, C6);
    set_envelope(0x1FF, 0x0C);

    set_tone(CH_A, REST);
    set_envelope(0x0FF, 0x0C);

    set_tone(CH_A, F5);
    set_envelope(0x1FF, 0x0C); 

    set_tone(CH_A, REST);
    set_envelope(0x0FF, 0x0C);

    set_tone(CH_A, D6);
    set_envelope(0x3FF, 0x0C); 

    set_tone(CH_A, REST);
    set_envelope(0x0FF, 0x0C);

    set_tone(CH_A, F6);
    set_envelope(0x1FF, 0x0C); 

    set_tone(CH_A, REST);
    set_envelope(0x0FF, 0x0C);

    set_tone(CH_A, Ds6_Eb6);
    set_envelope(0x1FF, 0x0C); 

    set_tone(CH_A, REST);
    set_envelope(0x0FF, 0x0C);
}

/********************************************************************************
 * Name: play_bassline_sequence
 * Purpose: Initiates the playback of a bassline sequence, complementing the
 *          melody loop for richer background music on channel B.
 * Input: None.
 * Output: A sequence of bass notes is played, enhancing the background music.
 *         The sequence is continuous and requires external control to stop.
 * Limitations: again, sounds like SHIT - barely worth calling 
 ********************************************************************************/
void play_bassline_sequence() {
    set_tone(CH_B, Gs5_Ab5);
    set_volume(CH_B, 0x1A);
    enable_channel(CH_B, TONE_ON, NOISE_OFF);
    set_envelope(0x0FF, 0x0C);

    set_tone(CH_B, REST);
    set_envelope(0x001, 0x0C);

    set_tone(CH_B, Gs5_Ab5);
    set_envelope(0x0FF, 0x0C);

    set_tone(CH_B, REST);
    set_envelope(0x001, 0x0C);;

    set_tone(CH_B, Gs5_Ab5);
    set_envelope(0x0FF, 0x0C);

    set_tone(CH_B, REST);
    set_envelope(0x001, 0x0C);

    set_tone(CH_B, Gs5_Ab5);
    set_envelope(0x0FF, 0x0C);

    set_tone(CH_B, REST);
    set_envelope(0x001, 0x0C);;

    set_tone(CH_B, D4);
    set_envelope(0x0FF, 0x0C);

    set_tone(CH_B, REST);
    set_envelope(0x001, 0x0C);

    set_tone(CH_B, D4);
    set_envelope(0x0FF, 0x0C);

    set_tone(CH_B, REST);
    set_envelope(0x001, 0x0C);

    set_tone(CH_B, C5);
    set_envelope(0x0FF, 0x0C);

    set_tone(CH_B, REST);
    set_envelope(0x001, 0x0C);

    set_tone(CH_B, C5);
    set_envelope(0x0FF, 0x0C);

    set_tone(CH_B, REST);
    set_envelope(0x001, 0x0C);

    set_tone(CH_B, Gs5_Ab5);
    set_envelope(0x0FF, 0x0C);

    set_tone(CH_B, REST);
    set_envelope(0x001, 0x0C);

    set_tone(CH_B, Gs5_Ab5);
    set_envelope(0x0FF, 0x0C);

    set_tone(CH_B, REST);
    set_envelope(0x001, 0x0C);

    set_tone(CH_B, Gs5_Ab5);
    set_envelope(0x0FF, 0x0C);

    set_tone(CH_B, REST);
    set_envelope(0x001, 0x0C);

    set_tone(CH_B, Gs5_Ab5);
    set_envelope(0x0FF, 0x0C);

    set_tone(CH_B, REST);
    set_envelope(0x001, 0x0C);

    set_tone(CH_B, F4);
    set_envelope(0x0FF, 0x0C);

    set_tone(CH_B, REST);
    set_envelope(0x001, 0x0C);

    set_tone(CH_B, F4);
    set_envelope(0x0FF, 0x0C);

    set_tone(CH_B, REST);
    set_envelope(0x001, 0x0C);

    set_tone(CH_B, D5);
    set_envelope(0x0FF, 0x0C);

    set_tone(CH_B, REST);
    set_envelope(0x001, 0x0C);

    set_tone(CH_B, D5);
    set_envelope(0x0FF, 0x0C);

    set_tone(CH_B, REST);
    set_envelope(0x001, 0x0C);

    set_tone(CH_B, C5);
    set_envelope(0x0FF, 0x0C);

    set_tone(CH_B, REST);
    set_envelope(0x001, 0x0C);

    set_tone(CH_B, C5);
    set_envelope(0x0FF, 0x0C);

    set_tone(CH_B, REST);
    set_envelope(0x001, 0x0C);

    set_tone(CH_B, F5);
    set_envelope(0x0FF, 0x0C);

    set_tone(CH_B, REST);
    set_envelope(0x001, 0x0C);

    set_tone(CH_B, F5);
    set_envelope(0x0FF, 0x0C);

    set_tone(CH_B, REST);
    set_envelope(0x001, 0x0C);

    set_tone(CH_B, G5);
    set_envelope(0x0FF, 0x0C);

    set_tone(CH_B, REST);
    set_envelope(0x001, 0x0C);

    set_tone(CH_B, G5);
    set_envelope(0x0FF, 0x0C);

    set_tone(CH_B, REST);
    set_envelope(0x001, 0x0C);

    set_tone(CH_B, C4);
    set_envelope(0x0FF, 0x0C);

    set_tone(CH_B, REST);
    set_envelope(0x001, 0x0C);

    set_tone(CH_B, C4);
    set_envelope(0x0FF, 0x0C);

    set_tone(CH_B, REST);
    set_envelope(0x001, 0x0C);

    set_tone(CH_B, Gs5_Ab5);
    set_envelope(0x0FF, 0x0C);

    set_tone(CH_B, REST);
    set_envelope(0x001, 0x0C);

    set_tone(CH_B, Gs5_Ab5);
    set_envelope(0x0FF, 0x0C);

    set_tone(CH_B, REST);
    set_envelope(0x001, 0x0C);

    set_tone(CH_B, Gs5_Ab5);
    set_envelope(0x0FF, 0x0C);

    set_tone(CH_B, REST);
    set_envelope(0x001, 0x0C);

    set_tone(CH_B, Gs5_Ab5);
    set_envelope(0x0FF, 0x0C);

    set_tone(CH_B, REST);
    set_envelope(0x001, 0x0C);

    set_tone(CH_B, C5);
    set_envelope(0x0FF, 0x0C);

    set_tone(CH_B, REST);
    set_envelope(0x001, 0x0C);

    set_tone(CH_B, C5);
    set_envelope(0x0FF, 0x0C);

    set_tone(CH_B, REST);
    set_envelope(0x001, 0x0C);

    set_tone(CH_B, As5_Bb5);
    set_envelope(0x0FF, 0x0C);

    set_tone(CH_B, REST);
    set_envelope(0x001, 0x0C);

    set_tone(CH_B, As5_Bb5);
    set_envelope(0x0FF, 0x0C);
}
