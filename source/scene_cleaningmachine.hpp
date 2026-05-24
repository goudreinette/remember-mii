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

    GRRLIB_texImg* clean[4] = {
        GRRLIB_LoadTexture(clean1_jpg),
        GRRLIB_LoadTexture(clean2_jpg),
        GRRLIB_LoadTexture(clean3_jpg),
        GRRLIB_LoadTexture(clean4_jpg)
    };
    
    GRRLIB_texImg* continue_img = GRRLIB_LoadTexture(continue_jpg);


    int slide_i = 0;
    float slide_opacity = 0;
    float timer;

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
                
                slide_i++;
                
                if (slide_i == 5) {
                    return Scene::Hotel;
                }
            }
        }

        controller mote = update_wiimote();
        

        if (mote.a_pressed) {
            transition_down = true;
        }

        

        music::check_loop();

        GRRLIB_DrawImg(0, 0, clean[slide_i], 0, 1, 1, RGBA(255,255,255, slide_opacity));  // Draw a jpeg
        GRRLIB_Render();
    }
}