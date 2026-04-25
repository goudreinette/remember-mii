#pragma once

#include <wiiuse/wpad.h>

#include <grrlib.h>
// #include "chill_mp3.h"
#include <mp3player.h>

// #include "clickshort_mp3.h"

ir_t ir1;  // infrared
int rumbleTimer = 0;



struct controller {
    int x, y;
    bool a_pressed;
    bool b_pressed;
    bool a_held;
    bool b_held;
};


controller update_wiimote() {
    // Rumble
    // printf("rumbleTimer: %i", rumbleTimer);
    // SYS_Report("rumbleTimer: %i\r", rumbleTimer);
    // SYS_Report("timer: %i\r", currentTime());
    if (rumbleTimer > 0) {
      WPAD_Rumble(0, 1);
      rumbleTimer--;
    } else {
      WPAD_Rumble(0, 0);
    }


    // Read input
    WPAD_ScanPads();

    controller mote;

    u32 buttonsDown = WPAD_ButtonsDown(0);
    u32 buttonsHeld = WPAD_ButtonsHeld(0);
    WPAD_IR(WPAD_CHAN_0, &ir1);

    mote.x = ir1.sx - 190;
    mote.y = ir1.sy - 210;

    mote.a_pressed = buttonsDown & WPAD_BUTTON_A;
    mote.b_pressed = buttonsDown & WPAD_BUTTON_B;
    mote.a_held = buttonsHeld & WPAD_BUTTON_A;
    mote.b_held = buttonsHeld & WPAD_BUTTON_B;

    // if (mote.a_pressed) {
	//     MP3Player_PlayBuffer(clickshort_mp3, clickshort_mp3_size, NULL);

    // }

    return mote;
}

