#pragma once


#include "grrlib.h"

#include "remember_mii_jpg.h"
#include "continue_png.h"
// #include "Continue_Button_Wii_png.h"

#include "scene.hpp"
#include "input.hpp"
#include "utils.hpp"


#include "letter_writing_scene_jpg.h"
#include "the_letter_itself_jpg.h"


Scene scene_lettertomunincipality() {    
    MP3Player_PlayBuffer(serguhh_loop_mp3, serguhh_loop_mp3_size, NULL);
    

    GRRLIB_texImg* writing_img = GRRLIB_LoadTexture(letter_writing_scene_jpg);;
    GRRLIB_texImg* letter_img =  GRRLIB_LoadTexture(the_letter_itself_jpg);;
    GRRLIB_texImg* continue_img = GRRLIB_LoadTexturePNG(continue_png);

    int width = rmode->viWidth;
    int height = rmode->viHeight;

    float i = 0;

    bool showing_letter = false;

    while (true) {
        i++;

        controller mote = update_wiimote();

        // Draw letter
        if (showing_letter) {
            GRRLIB_DrawImg(0, 0, letter_img, 0, .9, .9, WHITE);  // Draw a jpeg
        } else {
            GRRLIB_DrawImg(0, 0, writing_img, 0, .9, .9, WHITE);  // Draw a jpeg
        }

        // Draw cursor!
        GRRLIB_Circle(mote.x, mote.y, 10, BLUE, true);

        // Draw continue button
        if (showing_letter) {
            
        } else {
            float alpha = map(sin(i / 30.0), -1.0, 1.0, 200.0, 255.0);
            // float scale = map(sin(i / 10.0), -1.0, 1.0, .9, 1.);
            float scale = .9;
            GRRLIB_DrawImg(100, 325, continue_img, 0, scale, scale, RGBA(255,255,255,alpha));

            // if (i % 120 < 60) {

            // } else {
            //     GRRLIB_DrawImg(100, 325, continue_img, 0, .9, .9, RGBA(255,255,255,120));  // Draw a jpeg
            // }

            rect letter = {
                .x = 300,
                .y = 250,
                .width = 150,
                .height = 150
            };
 
            bool hovering_letter = GRRLIB_PtInRect(letter.x, letter.y, letter.width, letter.height, mote.x, mote.y);

            if (hovering_letter) {
                GRRLIB_Rectangle(letter.x, letter.y, letter.width, letter.height, RED, true);
                if (mote.a_pressed) {
                    showing_letter = true;
                }
            } else {
                GRRLIB_Rectangle(letter.x, letter.y, letter.width, letter.height, RED, false);
            }
        }
     
        // if (mote.a_pressed) {
        //     GRRLIB_FreeTexture(writing_img);
        //     GRRLIB_FreeTexture(letter_img);
        //     return Scene::LetterToMunincipality;
        // }
        

        GRRLIB_Render();
    }

    return Scene::Title;   
}

