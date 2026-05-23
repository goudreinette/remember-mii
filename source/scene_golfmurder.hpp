#pragma once

#include "grrlib.h"


#include "scene.hpp"
#include "music.hpp"
#include "music.hpp"


// Images
#include "golfmurder_1_golfintro_jpg.h"
#include "golfmurder_1_5_text_julius_png.h"
#include "golfmurder_2_anger_jpg.h"
#include "golfmurder_3_whack_jpg.h"
#include "golfmurder_4_bloodyclub_jpg.h"


Scene scene_golfmurder() {
    
    GRRLIB_texImg* bg = GRRLIB_LoadTexture(golfmurder_1_golfintro_jpg);

    int slide_i = 0;

    bool show_text_julius = false;
    bool show_whack = false;
    
    
    while (true) {
        controller mote = update_wiimote();

        
        if (mote.a_pressed) {
            slide_i++;

            if (slide_i == 1) {
                bg = GRRLIB_LoadTexture(golfmurder_1_5_text_julius_png);
            }

            if (slide_i == 2) {
                bg = GRRLIB_LoadTexture(golfmurder_2_anger_jpg);
            }

            if (slide_i == 3) {
                bg = GRRLIB_LoadTexture(golfmurder_3_whack_jpg);
            }

            if (slide_i == 4) {
                bg = GRRLIB_LoadTexture(golfmurder_4_bloodyclub_jpg);
            }
        }

        GRRLIB_DrawImg(60, 0, bg, 0, 1., 1., RGBA(255,255,255,255));  // Draw a jpeg
        GRRLIB_Render();
    }
}