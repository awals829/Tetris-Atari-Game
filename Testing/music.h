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