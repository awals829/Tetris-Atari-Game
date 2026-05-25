/********************************************************************************
 * Name: PSG.C
 * Purpose: Provides interface to the YM2149 sound chip on Atari ST, allowing 
 *          manipulation of sound channels, volume, noise, and musical tones.
 * Input: Various inputs depending on the function, including register numbers,
 *        channel IDs, volume levels, musical note frequencies, and envelope
 *        shapes.
 * Output: Direct manipulation of the sound chip to produce desired audio 
 *         effects. No return values for void functions; read_psg returns the 
 *         current value of a specified register.
 * Limitations: Functions are hardware-specific to the Atari ST and its YM2149
 *              sound chip. Assumes valid input ranges for registers, channels,
 *              and sound parameters.
 ********************************************************************************/

#include "psg.h"
#include <stdio.h>

/********************************************************************************
 * Name: write_psg
 * Purpose: Writes a value to a specified PSG register. The range of "valid" 
 *          values varies and should be checked via the YM2149 manual.
 * Input: reg - The register number to write to (UINT8, range 0-15)
 *        val - The value to write to the register (UINT8, register-specific range)
 * Output: None directly, but modifies the PSG register's value.
 * Limitations: Acceptable range of values for reg is 0 - 15. The specific range
 *              of valid values varies by register and should be referenced in 
 *              the YM2149 manual.
 ********************************************************************************/
void write_psg(UINT8 reg, UINT8 val){
    volatile UINT8 *PSG_reg_select = PSG_REG_SELECT_ADDRESS;
    volatile UINT8 *PSG_reg_write  = PSG_REG_WRITE_ADDRESS;
    
    if(reg >= 0 && reg <=15) { 
        *PSG_reg_select = reg;
        *PSG_reg_write = val; 
    }
}

/********************************************************************************
 * Name: read_psg
 * Purpose: Reads the current value from a specified PSG register.
 * Input: reg - the register number to read from (UINT8, range 0-15)
 * Output: The current value (UINT8) of the specified register.
 * Limitations: Acceptable range of values for reg is 0 - 15.
 ********************************************************************************/
UINT8 read_psg(UINT8 reg){
    volatile UINT8 *PSG_reg_select = PSG_REG_SELECT_ADDRESS;
    UINT8 PSG_value;

    if (reg >= 0 && reg <= 15) {
        *PSG_reg_select = reg;
        PSG_value = *PSG_reg_select;        
    }

    return PSG_value;
}

/********************************************************************************
 * Name: set_tone
 * Purpose: Changes the fine and coarse frequency tuning of a specified channel's tone.
 * Input: channel - Specifies the channel to change (UINT8; 0 for Channel A, 1 for Channel B,
 *                   2 for Channel C)
 *        tuning - Frequency tuning value, MS byte for coarse and LS byte for fine tuning (UINT16)
 * Output: Modifies the tone frequency of the specified channel.
 * Limitations: Channel must be between 0-2. The tuning value must be within 0-0xFFF.
 ********************************************************************************/
void set_tone(UINT8 channel, UINT16 tuning) {
    if (channel <= 2 && tuning <= 0xFFF) {
        write_psg(channel << 1, tuning & 0xFF); 
        write_psg((channel << 1) + 1, tuning >> 8); 
    }
}

/********************************************************************************
 * Name: set_volume
 * Purpose: Changes the volume for a specified channel.
 * Input: channel - Specifies the channel (UINT8; 0 for Channel A, 1 for Channel B,
 *                  2 for Channel C)
 *        volume - New volume setting (UINT8; range 0x00 to 0x1F)
 * Output: Modifies the volume of the specified channel.
 * Limitations: Volume values range from 0x00 to 0x1F.
 ********************************************************************************/
void set_volume(UINT8 channel, UINT8 volume) {
    if (channel <= 2 && volume <= 0x1F) {
        write_psg(8 + channel, volume);
    }
}

/********************************************************************************
 * Name: enable_channel
 * Purpose: Enables or disables tone and noise for a specified channel.
 * Input: channel - Specifies the channel (UINT8; 0 for Channel A, 1 for Channel B,
 *                  2 for Channel C)
 *        tone_on - Turn the tone on (1) or off (0) (UINT8)
 *        noise_on - Turn the noise on (1) or off (0) (UINT8)
 * Output: Modifies tone and noise settings for the specified channel.
 * Limitations: Channel must be between 0-2. tone_on and noise_on must be 0 or 1.
 ********************************************************************************/
void enable_channel(UINT8 channel, UINT8 tone_on, UINT8 noise_on) {
    if (channel <= 2) {
        UINT8 mixer_setting = read_psg(MIXER);
        mixer_setting = (tone_on ? mixer_setting & ~(1 << channel) : mixer_setting | (1 << channel));
        mixer_setting = (noise_on ? mixer_setting & ~(1 << (channel + 3)) : mixer_setting | (1 << (channel + 3)));
        
        write_psg(MIXER, mixer_setting);
    }
}

/********************************************************************************
 * Name: set_noise
 * Purpose: Sets the noise frequency for all channels.
 * Input: tuning - Noise frequency tuning value (UINT8; range 0x00 to 0x1F)
 * Output: Modifies the noise frequency for all channels.
 * Limitations: Noise frequency range is 0x00 to 0x1F.
 ********************************************************************************/
void set_noise(UINT8 tuning) {
    write_psg(NOISE, tuning);
}

/********************************************************************************
 * Name: set_envelope
 * Purpose: Sets the envelope shape and frequency for volume modulation.
 * Input: envelope - Frequency tuning value, MS byte for coarse and LS byte for fine tuning (UINT16)
 *        shape - Envelope shape (UINT8), defined in the YM2149 manual
 * Output: Modifies the envelope shape and frequency for volume modulation.
 * Limitations: Specific limitations depend on the YM2149's capabilities and should be referenced
 *              in its manual.
 ********************************************************************************/
void set_envelope(UINT16 envelope, UINT8 shape) {
    write_psg(ENV_FREQ_FINE, envelope & 0xFF);
    write_psg(ENV_FREQ_COARSE, envelope >> 8);
    write_psg(ENV_SHAPE, shape);
}

/********************************************************************************
 * Name: stop_sound
 * Purpose: Stops all sound output by resetting tones, noise, and volume to their default states.
 * Input: None
 * Output: Resets the sound generator to a silent state.
 * Limitations: Only clears the registers that can be changed via the other functions in this module.
 ********************************************************************************/
void stop_sound() {
    set_tone(CH_A, 0);
    set_tone(CH_B, 0);
    set_tone(CH_C, 0);

    write_psg(NOISE, 0);
    write_psg(MIXER, 0xFF);

    write_psg(A_LEVEL, 0);
    write_psg(B_LEVEL, 0);
    write_psg(C_LEVEL, 0);
    set_envelope(0, 0);
}

/**** Note arrays for playing music ****/
/* reference: JonDent - Explorations in Electronic Music, Sci Fi, Art & Travel (but mostly electronic music)
             https://djjondent.blogspot.com/ */

/* Vanished - Crystal Castles
    (transcribed manually from Crystal Castles - Vanished Piano Tutorial 
     by ThePianoKid https://www.youtube.com/watch?v=fWajDUOY-tE) */
/*BASSLINE BASED ON Eb MAJOR DIATONIC CHORDS*/

const Note Music[] = {
    /* Melody on Channel A */
    {D6, QUARTER_NOTE, CH_A}, 
    {G5, EIGHTH_NOTE, CH_A}, {F6, EIGHTH_NOTE, CH_A},
    {D6, QUARTER_NOTE, CH_A},
    {As5_Bb5, EIGHTH_NOTE, CH_A}, {G6, EIGHTH_NOTE, CH_A},
    {F6, EIGHTH_NOTE, CH_A}, {As6_Bb6, EIGHTH_NOTE, CH_A},
    {C6, EIGHTH_NOTE, CH_A}, {F5, EIGHTH_NOTE, CH_A},
    {D6, QUARTER_NOTE, CH_A},
    {F6, EIGHTH_NOTE, CH_A}, {Ds6_Eb6, EIGHTH_NOTE, CH_A},
    /* Bassline on Channel B */
    {Gs5_Ab5, THIRTY2ND_NOTE, CH_B}, {REST, THIRTY2ND_NOTE, CH_B}, 
    {Gs5_Ab5, THIRTY2ND_NOTE, CH_B}, {REST, THIRTY2ND_NOTE, CH_B}, 
    {Gs5_Ab5, THIRTY2ND_NOTE, CH_B}, {REST, THIRTY2ND_NOTE, CH_B}, 
    {Gs5_Ab5, THIRTY2ND_NOTE, CH_B}, {REST, THIRTY2ND_NOTE, CH_B},
    {D4, THIRTY2ND_NOTE, CH_B}, {REST, THIRTY2ND_NOTE, CH_B}, 
    {D4, THIRTY2ND_NOTE, CH_B}, {REST, THIRTY2ND_NOTE, CH_B},
    {C5, THIRTY2ND_NOTE, CH_B}, {REST, THIRTY2ND_NOTE, CH_B}, 
    {C5, THIRTY2ND_NOTE, CH_B}, {REST, THIRTY2ND_NOTE, CH_B},
    {Gs5_Ab5, THIRTY2ND_NOTE, CH_B}, {REST, THIRTY2ND_NOTE, CH_B}, 
    {Gs5_Ab5, THIRTY2ND_NOTE, CH_B}, {REST, THIRTY2ND_NOTE, CH_B}, 
    {Gs5_Ab5, THIRTY2ND_NOTE, CH_B}, {REST, THIRTY2ND_NOTE, CH_B}, 
    {Gs5_Ab5, THIRTY2ND_NOTE, CH_B}, {REST, THIRTY2ND_NOTE, CH_B},
    {F4, THIRTY2ND_NOTE, CH_B}, {REST, THIRTY2ND_NOTE, CH_B}, 
    {F4, THIRTY2ND_NOTE, CH_B}, {REST, THIRTY2ND_NOTE, CH_B},
    {D5, THIRTY2ND_NOTE, CH_B}, {REST, THIRTY2ND_NOTE, CH_B}, 
    {D5, THIRTY2ND_NOTE, CH_B}, {REST, THIRTY2ND_NOTE, CH_B},
    {C5, THIRTY2ND_NOTE, CH_B}, {REST, THIRTY2ND_NOTE, CH_B}, 
    {C5, THIRTY2ND_NOTE, CH_B}, {REST, THIRTY2ND_NOTE, CH_B},
    {F5, THIRTY2ND_NOTE, CH_B}, {REST, THIRTY2ND_NOTE, CH_B}, 
    {F5, THIRTY2ND_NOTE, CH_B}, {REST, THIRTY2ND_NOTE, CH_B},
    {G5, THIRTY2ND_NOTE, CH_B}, {REST, THIRTY2ND_NOTE, CH_B}, 
    {G5, THIRTY2ND_NOTE, CH_B}, {REST, THIRTY2ND_NOTE, CH_B},
    {C4, THIRTY2ND_NOTE, CH_B}, {REST, THIRTY2ND_NOTE, CH_B}, 
    {C4, THIRTY2ND_NOTE, CH_B}, {REST, THIRTY2ND_NOTE, CH_B},
    {Gs5_Ab5, THIRTY2ND_NOTE, CH_B}, {REST, THIRTY2ND_NOTE, CH_B}, 
    {Gs5_Ab5, THIRTY2ND_NOTE, CH_B}, {REST, THIRTY2ND_NOTE, CH_B}, 
    {Gs5_Ab5, THIRTY2ND_NOTE, CH_B}, {REST, THIRTY2ND_NOTE, CH_B}, 
    {Gs5_Ab5, THIRTY2ND_NOTE, CH_B}, {REST, THIRTY2ND_NOTE, CH_B},
    {C5, THIRTY2ND_NOTE, CH_B}, {REST, THIRTY2ND_NOTE, CH_B}, 
    {C5, THIRTY2ND_NOTE, CH_B}, {REST, THIRTY2ND_NOTE, CH_B}, 
    {As5_Bb5, THIRTY2ND_NOTE, CH_B}, {REST, THIRTY2ND_NOTE, CH_B},
    {As5_Bb5, THIRTY2ND_NOTE, CH_B}, {REST, THIRTY2ND_NOTE, CH_B}
};

/* Genesis - Grimes 
    (transcribed manually from Grimes - Genesis - Piano Tutorial [EASY] 
     by musichelpdude https://www.youtube.com/watch?v=DvOCVlkkTQM)

const Note active_melody[] = {
    {Cs5_Db5, EIGHTH_NOTE}, {Fs5_Gb5, SIXTEENTH_NOTE},
    {Cs5_Db5, EIGHTH_NOTE}, {Fs5_Gb5, SIXTEENTH_NOTE},
    {Cs5_Db5, SIXTEENTH_NOTE}, {Fs5_Gb5, SIXTEENTH_NOTE},
    {Fs5_Gb5, EIGHTH_NOTE}, {As5_Bb5, SIXTEENTH_NOTE},
    {Fs5_Gb5, EIGHTH_NOTE}, {As5_Bb5, SIXTEENTH_NOTE},
    {Fs5_Gb5, SIXTEENTH_NOTE}, {As5_Bb5, SIXTEENTH_NOTE},
    {Cs6_Db6, EIGHTH_NOTE}, {Cs6_Db6, SIXTEENTH_NOTE},
    {As5_Bb5, EIGHTH_NOTE}, {Cs6_Db6, SIXTEENTH_NOTE},
    {As5_Bb5, SIXTEENTH_NOTE}, {Cs6_Db6, SIXTEENTH_NOTE}
};
*/


