#pragma once

#include "grrlib.h"


#include "colors.hpp"

#include "clean1_jpg.h"
#include "clean2_jpg.h"
#include "clean3_jpg.h"
#include "clean4_jpg.h"
#include "continue_jpg.h"


// #include "continue_jpg.h"
#include "serguhh_loop_mp3.h"
#include "SERGUHH_spannedloop_mp3.h"
// #include "Continue_Button_Wii_png.h"

#include "scene.hpp"
#include "input.hpp"
#include "music.hpp"
#include "math.hpp"
#include "utils.hpp"


Scene scene_cleaningmachine() {
    music::play_spannendloop();

    int num_frames = 4;
    const uint8_t (*frames[4])[] = {
        &clean1_jpg,
        &clean2_jpg,
        &clean3_jpg,
        &clean4_jpg,
    };


    int slide_i = 0;
    float slide_opacity = 0;
    float timer;

    GRRLIB_texImg* frame = GRRLIB_LoadTexture(*frames[slide_i]);

    bool is_intro = true;
    bool transition_down = false;


    while (true) {

        if (!transition_down) {
            slide_opacity = lrp(slide_opacity, 255, slide_speed);
        }

        if (transition_down) {
            slide_opacity = lrp(slide_opacity, 0, slide_speed);
            if (slide_opacity < 30) {
                transition_down = false;
                
                GRRLIB_FreeTexture(frame);
                slide_i++;
                

                
                if (slide_i == num_frames) {
                    return Scene::Hotel;
                } else {
                    frame = GRRLIB_LoadTexture(*frames[slide_i]);
                }
            }
        }

        controller mote = update_wiimote();
        

        if (mote.a_pressed) {
            transition_down = true;
        }

        

        music::check_loop();

        GRRLIB_DrawImg(0, 0, frame, 0, 1, 1, RGBA(255,255,255, slide_opacity));  // Draw a jpeg
        GRRLIB_Render();
    }
}