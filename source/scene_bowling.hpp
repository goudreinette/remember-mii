#pragma once

#include "grrlib.h"

#include "colors.hpp"
#include "scene.hpp"
#include "input.hpp"
#include "math.hpp"
#include "utils.hpp"
#include "music.hpp"
#include "interface.hpp"



#include "clean1_jpg.h"
#include "clean2_jpg.h"
#include "clean3_jpg.h"
#include "clean4_jpg.h"
#include "continue_jpg.h"

#include "bowling_1_jpg.h"
#include "bowling_2_jpg.h"
#include "bowling_3_jpg.h"
#include "bowling_4_jpg.h"
#include "bowling_5_jpg.h"
#include "bowling_6_jpg.h"
#include "bowling_7_jpg.h"
#include "bowling_8_jpg.h"
#include "bowling_9_jpg.h"
#include "bowling_10_jpg.h"
#include "bowling_11_jpg.h"
#include "bowling_21_jpg.h"



Scene scene_bowling() {
    music::play_spannendloop();

    
    int num_frames = 12;
    const uint8_t (*frames[12])[] = {
        &bowling_1_jpg,
        &bowling_2_jpg,
        &bowling_3_jpg,
        &bowling_4_jpg,
        &bowling_5_jpg,
        &bowling_6_jpg,
        &bowling_7_jpg,
        &bowling_8_jpg,
        &bowling_9_jpg,
        &bowling_10_jpg,
        &bowling_11_jpg,
        &bowling_21_jpg
    };

    // GRRLIB_texImg* bg = GRRLIB_LoadTexture(golf_classes_1_jpg);

    int slide_i = 0;
    float slide_opacity = 0;
    float timer;

    bool is_intro = true;
    bool transition_down = false;
    
    GRRLIB_texImg* frame;


    while (true) {
        controller mote = update_wiimote();

     if (!transition_down) {
            slide_opacity = lrp(slide_opacity, 255, .01);
        }

        if (transition_down) {
            slide_opacity = lrp(slide_opacity, 0, .01);
            if (slide_opacity < 30) {
                transition_down = false;
                slide_i++;

                
                if (slide_i > num_frames) {
                    return Scene::GolfMurder;
                }

                frame = GRRLIB_LoadTexture(*frames[slide_i]);
            }
        }

        

        if (mote.a_pressed) {
            transition_down = true;
        }

        


        GRRLIB_DrawImg(0, 0, frame, 0, 1, 1, RGBA(255,255,255, slide_opacity));  // Draw a jpeg

        cursor::draw(mote.x, mote.y);
        music::check_loop();

        GRRLIB_Render();
    }
}