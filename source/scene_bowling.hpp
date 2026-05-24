#pragma once

#include "grrlib.h"

#include "colors.hpp"
#include "scene.hpp"
#include "input.hpp"
#include "math.hpp"
#include "utils.hpp"
#include "music.hpp"
#include "interface.hpp"


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

    // Backgrounds
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

    int slide_i = 0;
    float slide_opacity = 0;
    float t = 0;

    bool is_intro = true;
    bool transition_down = false;
    
    GRRLIB_texImg* frame = GRRLIB_LoadTexture(*frames[slide_i]);


    while (true) {
        t++;

        controller mote = update_wiimote();


        if (transition_down) {
            slide_opacity = lrp(slide_opacity, 0, slide_speed);
            if (slide_opacity < 30) {
                transition_down = false;
                slide_i++;
                GRRLIB_FreeTexture(frame);

                // Dialogue and choice logic comes here
                // -----
                
                if (slide_i > num_frames) {
                    return Scene::GolfMurder;
                }

                frame = GRRLIB_LoadTexture(*frames[slide_i]);
            }
        } else {
            slide_opacity = lrp(slide_opacity, 255, slide_speed);
        }


        if (mote.a_pressed) {
            transition_down = true;
        }

        

        GRRLIB_DrawImg(0, 0, frame, 0, 1, 1, RGBA(255,255,255, slide_opacity));  // Draw background

        bool continue_hover = continue_button::draw(150, 425, t, slide_opacity, mote.x, mote.y);

        cursor::draw(mote.x, mote.y);
        music::check_loop();

        GRRLIB_Render();
    }
}