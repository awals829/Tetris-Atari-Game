#include "test.h"

int main() { 
    
    UINT32 old_ssp = Super(0);
    /*
    play_action_sound();
    printf("Playing ACTION SOUND...\n\n");
    play_response_sound();
    printf("Playing RESPONSE SOUND...\n\n");
    */
   
    play_melody_loop();
    printf("Playing melody loop...\n\n");
    
    play_bassline_sequence();
    printf("Playing bass loop...\n\n");
    
    /*
    UINT32 time_now, time_then, time_elapsed;
    UINT32 time_elapsed_bass = 0, time_elapsed_melody = 0;
    bool test_sound = TRUE;
    bool music_started = FALSE;
    bool stop_music_flag = FALSE;

    const UINT32 sound_test_duration = 70 * 10; 
    const UINT32 music_test_duration = 70 * 25; 

    UINT32 old_ssp = Super(0);

    play_test_tone();
    play_test_tone2();
    

    time_then = get_time();

    while (!stop_music_flag) {
        time_now = get_time();
        time_elapsed = time_now - time_then;

        if (test_sound && time_elapsed < sound_test_duration) {
            if (time_elapsed == 0) {
                printf("Playing ACTION SOUND...\n\n");
                play_action_sound();
                printf("Playing RESPONSE SOUND...\n\n");
                play_response_sound();
            }
        } else if (!music_started) { 
            stop_sound();
            printf("Playing Game Music...\n\n");
            start_music();
            music_started = TRUE;
            time_then = time_now; 
            test_sound = FALSE; 
        } else if (music_started) {
            if (time_elapsed > 0 && time_elapsed < music_test_duration) {
                update_music(time_elapsed_bass);
                update_music(time_elapsed_melody);
            } else if (time_elapsed >= music_test_duration) {
                stop_music_flag = TRUE;
                stop_sound();
                printf("Music test completed.\n");
            }
        }
    }
    */
    Super(old_ssp);
    return 0; 
    
}

void play_test_tone(){
    set_volume(CH_A, 0x15);
    set_tone(CH_A, 0x1DD);
    enable_channel(CH_A, TONE_ON, NOISE_OFF);
}

void play_test_tone2() {
    write_psg(7, 0xFE); 
    write_psg(8, 0x10); 
    write_psg(0, 0xFF); 
    write_psg(1, 0x00); 
}

UINT32 get_time() {
    UINT32 time_now;
    UINT32 *timer = (UINT32 *)0x462; 

    time_now = *timer;

    return time_now;
}

