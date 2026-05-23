#pragma once

#include "grrlib.h"


#include "scene.hpp"
#include "music.hpp"


// Images
#include "golf_classes_1_jpg.h"
#include "golf_classes_2_jpg.h"
#include "golf_classes_3_jpg.h"
#include "golf_classes_4_jpg.h"
#include "golf_classes_5_jpg.h"
#include "golf_classes_6_jpg.h"



Scene scene_golfclass() {
    GRRLIB_texImg* bg = GRRLIB_LoadTexture(golf_classes_1_jpg);

    int slide_i = 1;

    bool show_text_julius = false;
    bool show_whack = false;
    
    
    while (true) {
        controller mote = update_wiimote();

        
        if (mote.a_pressed) {
            slide_i++;

            if (slide_i == 1) {
                bg = GRRLIB_LoadTexture(golf_classes_1_jpg);
            }

            if (slide_i == 2) {
                bg = GRRLIB_LoadTexture(golf_classes_2_jpg);
            }

            if (slide_i == 3) {
                bg = GRRLIB_LoadTexture(golf_classes_3_jpg);
            }

            if (slide_i == 4) {
                bg = GRRLIB_LoadTexture(golf_classes_4_jpg);
            }

            if (slide_i == 5) {
                bg = GRRLIB_LoadTexture(golf_classes_5_jpg);
            }

            if (slide_i == 6) {
                bg = GRRLIB_LoadTexture(golf_classes_6_jpg);
            }
        }

        GRRLIB_DrawImg(60, 0, bg, 0, 1., 1., RGBA(255,255,255,255));  // Draw a jpeg
        GRRLIB_Render();
    }
}