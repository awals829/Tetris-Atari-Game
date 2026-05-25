#include "music.h"

extern const Note Music[];
/*total amt of notes*/
#define MUSIC_SIZE 77 

int cur_A = 0;
int cur_B = 0;

UINT32 time_A = 0;
UINT32 time_B = 0;

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


