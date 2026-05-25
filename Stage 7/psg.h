/********************************************************************************
 * Name: PSG_H
 * Authors: Marusia Luciuk & Andrew Walsh
 * Purpose: Provides definitions and function prototypes for controlling the
 *          Programmable Sound Generator (PSG) YM2149F used in the Atari ST 
 *          computers. It includes control over three sound channels (A, B, C),
 *          noise generation, volume control, and envelope shaping for advanced
 *          sound effects and music playback. 
 * 
 * Definitions:
 *      - Register addresses for selecting and writing to PSG registers.
 *      - Constants for channel identifiers (CH_A, CH_B, CH_C).
 *      - YM2149 register values for fine and coarse pitch tuning, noise control,
 *        mixer operation, volume levels, and envelope shaping.
 *      - Constants for musical note frequencies (C4 to B7) calculated for a
 *        clock frequency of 2 MHz.
 *      - Tempo constants for musical note durations.
 *      - Note structure for organizing music playback.
 * 
 * Functions:
 *      - write_psg: Write a value to a specific PSG register.
 *      - read_psg: Read the current value from a specific PSG register.
 *      - enable_channel: Enable/disable tones and noise for a specific channel.
 *      - set_tone: Set the pitch (frequency) of a channel.
 *      - set_volume: Set the volume level of a channel.
 *      - stop_sound: Stops all sound output by resetting all relevant registers.
 *      - set_noise: Set the frequency of the noise generator.
 *      - set_envelope: Configure the shape and frequency of the volume envelope.
 * 
 * Note:
 *      - This header assumes the use of the "type.h" header for UINT8, UINT16
 *        definitions, and "<osbind.h>" for Atari ST specific functions.
 *      - The tempo constants assume a base tempo of 120 beats per minute.
 *      - "melody[]" and "bassline[]" arrays must be defined elsewhere to use
 *        for music playback.
 * 
 ********************************************************************************/

#ifndef PSG_H
#define PSG_H
#include "type.h"
#include <osbind.h>

#define PSG_REG_SELECT_ADDRESS 0xFF8800
#define PSG_REG_WRITE_ADDRESS 0xFF8802

#define CH_A 0
#define CH_B 1
#define CH_C 2

/* YM2149 REG VALUES */
#define CH_A_FINE 0
#define CH_A_COARSE 1
#define CH_B_FINE 2
#define CH_B_COARSE 3
#define CH_C_FINE 4
#define CH_C_COARSE 5
#define NOISE 6
#define MIXER 7
#define A_LEVEL 8
#define B_LEVEL 9
#define C_LEVEL 10
#define ENV_FREQ_FINE 11
#define ENV_FREQ_COARSE 12
#define ENV_SHAPE 13

/* RANDOM STUFF */
#define TONE_ON 1
#define TONE_OFF 0
#define NOISE_ON 1
#define NOISE_OFF 0

#define REST 0

typedef unsigned char bool;
#define TRUE 1
#define FALSE 0

/* PSG REG VALUES FOR 2 OCTAVE CHROMATIC SCALE (from C4 to C7)
    register value from frequency = clock frequency / (16 * note frequency) 
    where clock frequency = 2 MHz */

#define C4       0x1DD
#define Cs4_Db4  0x1C2
#define D4       0x1A9
#define Ds4_Eb4  0x191
#define E4       0x17B
#define F4       0x165
#define Fs4_Gb4  0x151
#define G4       0x13E
#define Gs4_Ab4  0x12C
#define A4       0x11C
#define As4_Bb4  0x10D
#define B4       0x0FF

#define C5       0x0F0
#define Cs5_Db5  0x0E1
#define D5       0x0D4
#define Ds5_Eb5  0x0C8
#define E5       0x0BD
#define F5       0x0B3
#define Fs5_Gb5  0x0A9
#define G5       0x09F
#define Gs5_Ab5  0x096
#define A5       0x08E
#define As5_Bb5  0x087
#define B5       0x07F

#define C6       0x078
#define Cs6_Db6  0x071
#define D6       0x06A
#define Ds6_Eb6  0x064
#define E6       0x05E
#define F6       0x059
#define Fs6_Gb6  0x054
#define G6       0x04F
#define Gs6_Ab6  0x04B
#define A6       0x047
#define As6_Bb6  0x043
#define B6       0x040

#define C7       0x03C
#define Cs7_Db7  0x038
#define D7       0x035
#define Ds7_Eb7  0x032
#define E7       0x02F
#define F7       0x02D
#define Fs7_Gb7  0x02A
#define G7       0x028
#define Gs7_Ab7  0x025
#define A7       0x023
#define As7_Bb7  0x021
#define B7       0x020

/* TEMPO CONSTANTS */
#define THIRTY2ND_NOTE 16
#define SIXTEENTH_NOTE 32
#define EIGHTH_NOTE  64
#define QUARTER_NOTE 128
#define HALF_NOTE    256
#define WHOLE_NOTE   512

typedef struct {
    UINT16 note;
    UINT8 duration;
    UINT8 channel;
}Note;

void write_psg(UINT8 reg, UINT8 val);
UINT8 read_psg(UINT8 reg);
void enable_channel(UINT8 channel, UINT8 tone_on, UINT8 noise_on);
void set_tone(UINT8 channel, UINT16 tuning);
void set_volume(UINT8 channel, UINT8 volume);
void stop_sound();
void set_noise(UINT8 tuning);
void set_envelope(UINT16 envelope, UINT8 shape);


extern const Note melody[];
extern const UINT16 bassline[];

#endif