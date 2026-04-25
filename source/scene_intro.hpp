#pragma once

#include "grrlib.h"

#include "remember_mii_jpg.h"
#include "continue_jpg.h"
#include "serguhh_loop_mp3.h"
// #include "Continue_Button_Wii_png.h"

#include "serguhh_loop_mp3.h"


#include "intro_1_jpg.h"
#include "intro_2_jpg.h"
#include "intro_3_jpg.h"
#include "intro_4_jpg.h"
#include "intro_5_jpg.h"
#include "intro_6_jpg.h"
#include "intro_7_jpg.h"
#include "intro_8_jpg.h"
#include "intro_9_jpg.h"
#include "intro_10_jpg.h"
#include "intro_11_jpg.h"
#include "intro_12_jpg.h"
#include "intro_13_jpg.h"
#include "intro_14_jpg.h"
#include "intro_15_jpg.h"
#include "intro_16_jpg.h"
#include "intro_17_jpg.h"
#include "intro_18_jpg.h"
#include "intro_19_jpg.h"

#include "vector"

#include "scene.hpp"
#include "input.hpp"


Scene scene_intro() {
    MP3Player_PlayBuffer(serguhh_loop_mp3, serguhh_loop_mp3_size, NULL);
    
    int width = rmode->viWidth;
    int height = rmode->viHeight;

    GRRLIB_texImg* frame;

    
    const uint8_t (*frames[19])[] = {
        &intro_1_jpg,
        &intro_2_jpg,
        &intro_3_jpg,
        &intro_4_jpg,
        &intro_5_jpg,
        &intro_6_jpg,
        &intro_7_jpg,
        &intro_8_jpg,
        &intro_9_jpg,
        &intro_10_jpg,
        &intro_11_jpg,
        &intro_12_jpg,
        &intro_13_jpg,
        &intro_14_jpg,
        &intro_15_jpg,
        &intro_16_jpg,
        &intro_17_jpg,
        &intro_18_jpg,
        &intro_19_jpg
    };


    int i = 0;
    int slide_i = 0;
    float slide_opacity = 0;


    while (true) {
        i++;
        slide_opacity = lrp(slide_opacity, 255, .01);


        controller mote = update_wiimote();

        if (i % 50 == 0 && slide_i < 18) {
            slide_i++;
            frame = GRRLIB_LoadTexture(*frames[slide_i]);
        }

        GRRLIB_DrawImg(0, 0, frame, 0, 2, 2, RGBA(255,255,255,slide_opacity));

        if (slide_i == 18 && i > 20 * 50) {
            return Scene::LetterToMunincipality;
        }
        

        GRRLIB_Render();
    }
}