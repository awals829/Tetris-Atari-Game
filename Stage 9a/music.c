/********************************************************************************
 * Name: music.c
 * Authors: Marusia Luciuk & Andrew Walsh
 * 
 * Purpose: Implements functions to initialize and update music playback on the
 *          Atari ST using the YM2149 sound chip. It enables playing a sequence
 *          of notes and rhythms for channels A and B simultaneously.
 * 
 * Input: Time elapsed since last update (for update_music function).
 * Output: Direct manipulation of sound chip registers to produce music.
 * 
 * Details:
 *      - start_music() must be called before update_music() in a loop to
 *        continuously play back the defined sequence of music.
 *      - update_music() must be called repeatedly, typically in a timed loop,
 *        with the timeElapsed parameter indicating the time passed since the
 *        last call.
 *      - The Music array and MUSIC_SIZE define the sequence and length of the
 *        music to be played. The array is external and must be defined
 *        elsewhere in the project.
 * 
 * Limitations:
 *      - This implementation supports only two channels (A and B) for playback.
 *      - The timing resolution is dependent on the frequency of update_music()
 *        calls and may not be precise enough for all musical needs.
 * 
 ********************************************************************************/

#include "music.h"

extern const Note Music[];
/*total amt of notes*/
#define MUSIC_SIZE 77 

int cur_A = 0;
int cur_B = 0;

UINT32 time_A = 0;
UINT32 time_B = 0;

/********************************************************************************
 * Name: start_music
 * Purpose: Initializes music playback, setting up the first notes for channels
 *          A and B from the global Music array.
 * Input: None.
 * Output: Configures the YM2149 sound chip to start playing the first notes
 *         on channels A and B, setting appropriate volumes.
 * Limitations: Relies on the global Music array and MUSIC_SIZE for sequence
 *              and duration. Only initializes playback, does not maintain it.
 ********************************************************************************/
void start_music() {
    int i;
    cur_A = cur_B = 0;
    time_A = time_B = 0;

    for (i = 0; i < MUSIC_SIZE; ++i) {
        if (Music[i].channel == CH_A && cur_A == 0) {
            set_tone(CH_A, Music[i].note);
            set_volume(CH_A, 0x10); 
            time_A = Music[i].duration;
            cur_A = i + 1;
        } else if (Music[i].channel == CH_B && cur_B == 0) {
            set_tone(CH_B, Music[i].note);
            set_volume(CH_B, 0x10); 
            time_B = Music[i].duration;
            cur_B = i + 1;
        }

        if (cur_A != 0 && cur_B != 0) break; 
    }
}

/********************************************************************************
 * Name: update_music
 * Purpose: Continues music playback by checking elapsed time against note
 *          durations, updating current notes for channels A and B as needed.
 * Input: timeElapsed - Time elapsed since the last update, used to determine
 *                      when to switch to the next note in the sequence.
 * Output: Adjusts the YM2149 sound chip to play the next notes on channels A
 *         and B when the current notes' durations have elapsed.
 * Limitations: Must be called repeatedly in a loop with accurate timing to
 *              ensure continuous playback. Assumes Music array is correctly
 *              populated and MUSIC_SIZE is accurate.
 ********************************************************************************/
void update_music(UINT32 timeElapsed) {
        time_A -= timeElapsed;
    if (time_A <= 0 && cur_A < MUSIC_SIZE) {
        while (Music[cur_A].channel != CH_A && cur_A < MUSIC_SIZE) cur_A++;
        if (cur_A < MUSIC_SIZE) {
            set_tone(CH_A, Music[cur_A].note);
            time_A = Music[cur_A].duration;
            cur_A++;
        }
    }

    time_B -= timeElapsed;
    if (time_B <= 0 && cur_B < MUSIC_SIZE) {
        while (Music[cur_B].channel != CH_B && cur_B < MUSIC_SIZE) cur_B++;
        if (cur_B < MUSIC_SIZE) {
            set_tone(CH_B, Music[cur_B].note);
            time_B = Music[cur_B].duration;
            cur_B++;
        }
    }
    }


