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
// #include "Continue_Button_Wii_png.h"

#include "scene.hpp"
#include "input.hpp"
#include "math.hpp"


Scene scene_cleaningmachine() {
    MP3Player_PlayBuffer(serguhh_loop_mp3, serguhh_loop_mp3_size, NULL);
    
    GRRLIB_texImg* clean[4] = {
        GRRLIB_LoadTexture(clean1_jpg),
        GRRLIB_LoadTexture(clean2_jpg),
        GRRLIB_LoadTexture(clean3_jpg),
        GRRLIB_LoadTexture(clean4_jpg)
    };
    
    GRRLIB_texImg* continue_img = GRRLIB_LoadTexture(continue_jpg);

    int width = rmode->viWidth;
    int height = rmode->viHeight;

    int slide_i = 0;


    float slide_opacity = 0;
    float timer;

    bool is_intro = true;


    while (true) {
        if (is_intro) {
            slide_opacity = lrp(slide_opacity, 255, .01);
        }

        controller mote = update_wiimote();
        

        if (mote.a_pressed) {
            slide_i++;

            if (slide_i == 4) {
                return Scene::LetterToMunincipality;
            }
        }

        GRRLIB_DrawImg(0, 0, clean[slide_i], 0, .9, .9, RGBA(255,255,255, slide_opacity));  // Draw a jpeg
        GRRLIB_Render();
    }
}