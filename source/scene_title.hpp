#pragma once

#include "grrlib.h"

#include "remember_mii_jpg.h"
// #include "continue_jpg.h"
#include "continue_png.h"
#include "serguhhhs_mind_mp3.h"
#include "serguhh_loop_mp3.h"
#include "cursor_png.h"
// #include "Continue_Button_Wii_png.h"

#include "scene.hpp"
#include "input.hpp"
#include "utils.hpp"


Scene scene_title() {
    MP3Player_PlayBuffer(serguhh_loop_mp3, serguhh_loop_mp3_size, NULL);
    
    GRRLIB_texImg* remembermii_img = GRRLIB_LoadTexture(remember_mii_jpg);
    GRRLIB_texImg* continue_img = GRRLIB_LoadTexture(continue_png);

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
        float alpha = map(sin(i / 30.0), -1.0, 1.0, 75.0, slide_opacity);
        // float scale = map(sin(i / 10.0), -1.0, 1.0, .9, 1.);
        float scale = 1.;
        GRRLIB_DrawImg(375, 377, continue_img, 0, scale, scale, RGBA(255,255,255, alpha));
        
        // Draw cursor!
        cursor::draw(mote.x, mote.y);

        if (mote.a_pressed) {
            outro = true;
        }

        if (outro) {
            outro_i++;
            slide_opacity = lrp(slide_opacity, 0, .01);

            if (outro_i == 200) {
                GRRLIB_FreeTexture(remembermii_img);
                GRRLIB_FreeTexture(continue_img);
                return Scene::Intro;
            }
        }

        GRRLIB_Render();
    }
}