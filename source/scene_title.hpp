#pragma once

#include "grrlib.h"

#include "remember_mii_jpg.h"
#include "continue_jpg.h"
#include "serguhhhs_mind_mp3.h"
#include "serguhh_loop_mp3.h"
// #include "Continue_Button_Wii_png.h"

#include "scene.hpp"
#include "input.hpp"


Scene scene_title() {
    MP3Player_PlayBuffer(serguhh_loop_mp3, serguhh_loop_mp3_size, NULL);
    
    GRRLIB_texImg* remembermii_img = GRRLIB_LoadTexture(remember_mii_jpg);
    GRRLIB_texImg* continue_img = GRRLIB_LoadTexture(continue_jpg);

    int width = rmode->viWidth;
    int height = rmode->viHeight;

    int i = 0;

    while (true) {
        i++;

        controller mote = update_wiimote();

        GRRLIB_DrawImg(-50, 0, remembermii_img, 0, .9, .9, WHITE);  // Draw a jpeg

        // Draw cursor!
        GRRLIB_Circle(mote.x, mote.y, 10, BLUE, true);

        // Draw continue button
        // if (i % 120 < 60) {
        //     GRRLIB_DrawImg(400, 300, continue_img, 0, .9, .9, WHITE);  // Draw a jpeg
        // } else {
        //     GRRLIB_DrawImg(400, 300, continue_img, 0, .9, .9, BLACK);  // Draw a jpeg
        // }

        float alpha = map(sin(i / 30.0), -1.0, 1.0, 200.0, 255.0);
        // float scale = map(sin(i / 10.0), -1.0, 1.0, .9, 1.);
        float scale = 1.;
        GRRLIB_DrawImg(102, 377, continue_img, 0, scale, scale, RGBA(255,255,255,alpha));
        

        if (mote.a_pressed) {
            GRRLIB_FreeTexture(remembermii_img);
            GRRLIB_FreeTexture(continue_img);
            return Scene::LetterToMunincipality;
        }
        

        GRRLIB_Render();
    }
}