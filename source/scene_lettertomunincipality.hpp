#pragma once


#include "grrlib.h"

// #include "remember_mii_jpg.h"
// #include "continue_jpg.h"
// #include "Continue_Button_Wii_png.h"

#include "scene.hpp"
#include "input.hpp"



// #include "letter_writing_scene_jpg.h"
// #include "the_letter_itself_jpg.h"


Scene scene_lettertomunincipality() {    
    
    // GRRLIB_texImg* writing_img = GRRLIB_LoadTexture(letter_writing_scene_jpg);;
    // GRRLIB_texImg* letter_img =  GRRLIB_LoadTexture(the_letter_itself_jpg);;
    // // GRRLIB_texImg* continue_img;

    // int width = rmode->viWidth;
    // int height = rmode->viHeight;

    // int i = 0;

    // while (true) {
    //     i++;

    //     controller mote = update_wiimote();

    //     GRRLIB_DrawImg(0, 0, writing_img, 0, .9, .9, WHITE);  // Draw a jpeg

    //     // Draw cursor!
    //     GRRLIB_Circle(mote.x, mote.y, 10, BLUE, true);
        

    //     // Draw continue button
    //     // if (i % 120 < 60) {
    //     //     GRRLIB_DrawImg(400, 300, continue_img, 0, .9, .9, WHITE);  // Draw a jpeg
    //     // } else {
    //     //     GRRLIB_DrawImg(400, 300, continue_img, 0, .9, .9, BLACK);  // Draw a jpeg
    //     // }

    //     if (mote.a_pressed) {
    //         GRRLIB_FreeTexture(writing_img);
    //         GRRLIB_FreeTexture(letter_img);
    //         return Scene::LetterToMunincipality;
    //     }
        

    //     GRRLIB_Render();
    // }

    return Scene::Title;   
}

