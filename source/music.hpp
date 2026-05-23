#pragma once 

#include <grrlib.h>

#include <asndlib.h>
#include <math.h>
#include <mp3player.h>


// Soundtracks
#include "serguhh_loop_mp3.h"
#include "SERGUHH_spannedloop_mp3.h"
#include "serguhhhs_mind_mp3.h"




namespace music {
    void play_serguhh_loop() {
        MP3Player_PlayBuffer(serguhh_loop_mp3, serguhh_loop_mp3_size, NULL);
    }

    void play_serguhhs_mind() {

    }

    void play_spannendloop() {
    }
}