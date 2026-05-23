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
    enum class Soundtrack {
        SerguhhLoop, SerguhhsMind, SpannendLoop
    };

    Soundtrack current_soundtrack;


    void play_serguhh_loop() {
        current_soundtrack = Soundtrack::SerguhhLoop;
        MP3Player_PlayBuffer(serguhh_loop_mp3, serguhh_loop_mp3_size, NULL);
    }

    void play_serguhhs_mind() {
        current_soundtrack = Soundtrack::SerguhhsMind;
        MP3Player_PlayBuffer(serguhhhs_mind_mp3, serguhhhs_mind_mp3_size, NULL);
    }

    void play_spannendloop() {
        current_soundtrack = Soundtrack::SpannendLoop;
        MP3Player_PlayBuffer(SERGUHH_spannedloop_mp3, SERGUHH_spannedloop_mp3_size, NULL);
    }
}