#include "effects.h"

/*
* Purpose: Plays a sound for any action taken during menu navigation
*          or gameplay (e.g. selecting an option, rotating tetronimo, etc.)
*
*
*/
void play_action_sound() {
    set_tone(CH_C, G6); 
    set_volume(CH_C, 0x1A);    
    enable_channel(CH_C, TONE_ON, NOISE_OFF); 
    set_envelope(0x3FF, 0x0C);
}

/*
* Purpose: Plays when a line is cleared in the game
*
*
*/
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
