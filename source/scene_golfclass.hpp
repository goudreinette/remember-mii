#pragma once

#include "grrlib.h"


#include "scene.hpp"
#include "music.hpp"
#include "utils.hpp"


// Images
#include "golf_classes_1_jpg.h"
#include "golf_classes_2_jpg.h"
#include "golf_classes_3_jpg.h"
#include "golf_classes_4_jpg.h"
#include "golf_classes_5_jpg.h"
#include "golf_classes_6_jpg.h"



Scene scene_golfclass() {
    music::play_spannendloop();


    int num_frames = 6;
    const uint8_t (*frames[6])[] = {
        &golf_classes_1_jpg,
        &golf_classes_2_jpg,
        &golf_classes_3_jpg,
        &golf_classes_4_jpg,
        &golf_classes_5_jpg,
        &golf_classes_6_jpg
    };

    // GRRLIB_texImg* bg = GRRLIB_LoadTexture(golf_classes_1_jpg);

    int slide_i = 0;
    float slide_opacity = 0;
    float timer;

    bool is_intro = true;
    bool transition_down = false;
    
    GRRLIB_texImg* frame = GRRLIB_LoadTexture(*frames[slide_i]);


    while (true) {
        controller mote = update_wiimote();

        if (!transition_down) {
            slide_opacity = lrp(slide_opacity, 255, .03);
        }

        if (transition_down) {
            slide_opacity = lrp(slide_opacity, 0, .03);
            if (slide_opacity < 30) {
                transition_down = false;
                slide_i++;

                GRRLIB_FreeTexture(frame);
                
                if (slide_i >= num_frames) {
                    return Scene::Bowling;
                }

                frame = GRRLIB_LoadTexture(*frames[slide_i]);
            }
        }

        
        
        if (mote.a_pressed) {
            transition_down = true;
        }

        

        music::check_loop();

        GRRLIB_DrawImg(0, 0, frame, 0, 1, 1, RGBA(255,255,255, slide_opacity));  // Draw a jpeg

        cursor::draw(mote.x, mote.y);
        music::check_loop();

        GRRLIB_Render();
    }
}