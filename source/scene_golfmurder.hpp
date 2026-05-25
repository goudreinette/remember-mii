#pragma once

#include "grrlib.h"


#include "scene.hpp"
#include "music.hpp"


// Images
#include "golfmurder_1_golfintro_jpg.h"
#include "golfmurder_1_5_text_julius_jpg.h"
#include "golfmurder_2_anger_jpg.h"
#include "golfmurder_3_whack_jpg.h"
#include "golfmurder_4_bloodyclub_jpg.h"


Scene scene_golfmurder() {
    music::play_serguhh_loop();

    int slide_i = 0;
    float slide_opacity = 0;

    int num_frames = 5;
    const uint8_t (*frames[5])[] = {
        &golfmurder_1_golfintro_jpg,
        &golfmurder_1_5_text_julius_jpg,
        &golfmurder_2_anger_jpg,
        &golfmurder_3_whack_jpg,
        &golfmurder_4_bloodyclub_jpg
    };

    
    GRRLIB_texImg* frame = GRRLIB_LoadTexture(*frames[slide_i]);

    bool transition_down = false;


    while (true) {
        controller mote = update_wiimote();


        if (transition_down) {
            slide_opacity = lrp(slide_opacity, 0, slide_speed);
            if (slide_opacity < 30) {
                transition_down = false;
                slide_i = slide_i + 1;
                // GRRLIB_FreeTexture(frame);

                // Dialogue and choice logic comes here
                // -----
                
                if (slide_i == num_frames) {
                    return Scene::CleaningMachine;
                }

                frame = GRRLIB_LoadTexture(*frames[slide_i]);
            }
        } else {
            slide_opacity = lrp(slide_opacity, 255, slide_speed);
        }

        if (mote.a_pressed) {
            transition_down = true;
        }

        music::check_loop();

        GRRLIB_DrawImg(60, -20, frame, 0, 1, 1, RGBA(255,255,255, slide_opacity));  // Draw a jpeg
        cursor::draw(mote.x, mote.y);

        // GRRLIB_DrawImg(60, 0, bg, 0, 1., 1., RGBA(255,255,255,255));  // Draw a jpeg
        GRRLIB_Render();
    }
}