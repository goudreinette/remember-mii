#pragma once

#include "grrlib.h"

#include "remember_mii_jpg.h"
#include "continue_jpg.h"
// #include "Continue_Button_Wii_png.h"

#include "scene.hpp"
#include "input.hpp"


Scene scene_title() {
    // MP3Player_PlayBuffer(chill_mp3, chill_mp3_size, NULL);
    
    GRRLIB_texImg* remembermii_img = GRRLIB_LoadTexture(remember_mii_jpg);
    GRRLIB_texImg* continue_img = GRRLIB_LoadTexture(continue_jpg);

    int width = rmode->viWidth;
    int height = rmode->viHeight;

    int i = 0;

    while (true) {
        i++;

        controller mote = update_wiimote();

        

        if (mote.a_pressed) {
            GRRLIB_FreeTexture(remembermii_img);
            GRRLIB_FreeTexture(continue_img);
            return Scene::LetterToMunincipality;
        }
        

        GRRLIB_Render();
    }
}