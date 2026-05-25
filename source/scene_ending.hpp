#pragma once

#include "scene.hpp"

#include "grrlib.h"

#include "remember_mii_jpg.h"
#include "serguhhhs_mind_mp3.h"
#include "serguhh_loop_mp3.h"
#include "cursor_png.h"
// #include "Continue_Button_Wii_png.h"

#include "scene.hpp"
#include "music.hpp"
#include "input.hpp"
#include "utils.hpp"

#include "credits_jpg.h"


Scene scene_ending() {
    // music::play_serguhh_loop();
    
    GRRLIB_texImg* remembermii_img = GRRLIB_LoadTexture(credits_jpg);

    int width = rmode->viWidth;
    int height = rmode->viHeight;

    int i = 0;
    float slide_opacity = 0;
    bool outro = false;
    int outro_i = 0;

    while (true) {
        i++;

        controller mote = update_wiimote();

        if (!outro) {
            slide_opacity = lrp(slide_opacity, 255, .01);
        }

        GRRLIB_DrawImg(-50, 0, remembermii_img, 0, 1, 1, RGBA(255,255,255, slide_opacity));  // Draw a jpeg


        // Continue button and cursor
        bool hovering_continue = continue_button::draw(500, 50, i, slide_opacity, mote.x, mote.y);
        
        // Draw cursor!
        cursor::draw(mote.x, mote.y);

        if (mote.a_pressed && hovering_continue) {
            outro = true;
            continue_button::chosen = true;
        }

        if (outro) {
            outro_i++;
            slide_opacity = lrp(slide_opacity, 0, .01);

            if (outro_i == 200) {
                GRRLIB_FreeTexture(remembermii_img);
                continue_button::chosen = false;
                return Scene::Title;
            }
        }

        music::check_loop();

        GRRLIB_Render();
    }
}