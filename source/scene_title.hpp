#pragma once

#include "grrlib.h"

#include "remember_mii_jpg.h"
#include "continue_jpg.h"

#include "scene.hpp"
#include "input.hpp"


GRRLIB_texImg* remembermii_img;
GRRLIB_texImg* continue_img;



Scene scene_title() {
    // MP3Player_PlayBuffer(chill_mp3, chill_mp3_size, NULL);
    
    remembermii_img = GRRLIB_LoadTexture(remember_mii_jpg);
    continue_img = GRRLIB_LoadTexture(continue_jpg);

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

        // } else {
        // }
        

        GRRLIB_Render();
    }
}