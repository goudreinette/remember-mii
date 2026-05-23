#pragma once

#include "vector"
#include "grrlib.h"

#include "remember_mii_jpg.h"
#include "continue_jpg.h"

// #include "Continue_Button_Wii_png.h"


// Images
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
#include "intro_20_jpg.h"
#include "intro_21_jpg.h"
#include "intro_22_jpg.h"
#include "intro_23_jpg.h"
#include "intro_24_jpg.h"
#include "intro_25_jpg.h"
#include "intro_26_jpg.h"
#include "intro_27_jpg.h"
#include "intro_28_jpg.h"
#include "intro_29_jpg.h"
#include "intro_30_jpg.h"
#include "intro_31_jpg.h"
#include "intro_32_jpg.h"
#include "intro_33_jpg.h"
#include "intro_34_jpg.h"
#include "intro_35_jpg.h"
#include "intro_36_jpg.h"
#include "intro_37_jpg.h"
#include "intro_38_jpg.h"
#include "intro_39_jpg.h"


#include "scene.hpp"
#include "input.hpp"
#include "music.hpp"
#include "utils.hpp"



Scene scene_intro() {
    // music::play_serguhh_loop();
    
    int width = rmode->viWidth;
    int height = rmode->viHeight;

    GRRLIB_texImg* frame;

    int num_frames = 39;
    const uint8_t (*frames[39])[] = {
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
        &intro_19_jpg,
        &intro_20_jpg,
        &intro_21_jpg,
        &intro_22_jpg,
        &intro_23_jpg,
        &intro_24_jpg,
        &intro_25_jpg,
        &intro_26_jpg,
        &intro_27_jpg,
        &intro_28_jpg,
        &intro_29_jpg,
        &intro_30_jpg,
        &intro_31_jpg,
        &intro_32_jpg,
        &intro_33_jpg,
        &intro_34_jpg,
        &intro_35_jpg,
        &intro_36_jpg,
        &intro_37_jpg,
        &intro_38_jpg,
        &intro_39_jpg
    };


    int i = 0;
    int slide_i = 0;
    float slide_opacity = 0;

    bool fading_out = false;


    while (true) {
        i++;

        controller mote = update_wiimote();

        // Animate frames
        if (i % 24 == 0 && slide_i < num_frames) {
            slide_i++;
            frame = GRRLIB_LoadTexture(*frames[slide_i]);
        }

        // Draw frame
        GRRLIB_DrawImg(0, 0, frame, 0, 2, 2, RGBA(255,255,255,slide_opacity));

        // Fadeout
        if (slide_i == num_frames && i > 20 * 50) {
            fading_out = true;
        }

        // Clean up
        if (fading_out) {
            slide_opacity = lrp(slide_opacity, 0, .01);

            if (slide_opacity < .1) {
                for (int i = 0; i < 19; i++) {
                    // GRRLIB_FreeTexture(frames[i]);
                }
                
                return Scene::LetterToMunincipality;
            }
        } else {
            slide_opacity = lrp(slide_opacity, 255, .01); // Fade-in or stay 
        }
        

        GRRLIB_Render();
    }
}