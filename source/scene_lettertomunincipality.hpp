#pragma once


#include "grrlib.h"

#include "scene.hpp"
#include "input.hpp"
#include "utils.hpp"


#include "letter_writing_scene_jpg.h"
#include "the_letter_itself_jpg.h"


Scene scene_lettertomunincipality() {    
    GRRLIB_texImg* writing_img = GRRLIB_LoadTexture(letter_writing_scene_jpg);;
    GRRLIB_texImg* letter_img =  GRRLIB_LoadTexture(the_letter_itself_jpg);;


    float t = 0;

    bool showing_letter = false;
    float slide_opacity = 0;
    float letter_opacity = 0;
    float letter_y = 100;
    bool viewed_letter = false;

    bool outro = false;
    int outro_i = 0;

    while (SYS_MainLoop()) {
        t++;

        if (outro) {
            slide_opacity = lrp(slide_opacity, 0, slide_speed);
        } else {
            slide_opacity = lrp(slide_opacity, 255, slide_speed);
        }

        controller mote = update_wiimote();

        // Draw letter
        if (showing_letter) {
            letter_opacity = lrp(letter_opacity, 255, .1);
            letter_y = lrp(letter_y, 0, .1);
        } else {
            letter_opacity = lrp(letter_opacity, 0, .1);
            letter_y = lrp(letter_y, 100, .1);
        }

        // Writing
        GRRLIB_DrawImg(0, 0, writing_img, 0, 1., 1., RGBA(255,255,255, slide_opacity)); 

        // Letter
        GRRLIB_DrawImg(0, letter_y, letter_img, 0, 1., 1., RGBA(255,255,255, letter_opacity)); 



        // Draw continue button
        if (showing_letter) {

        } else {
            // float alpha = map(sin(t / 30.0), -1.0, 1.0, 200.0, 255.0);
            // float scale = map(sin(t / 10.0), -1.0, 1.0, .9, 1.);
            // float scale = 1.;
            // GRRLIB_DrawImg(102, 377, continue_img, 0, scale, scale, RGBA(255,255,255,alpha));

            // if (t % 120 < 60) {

            // } else {
            //     GRRLIB_DrawImg(100, 325, continue_img, 0, .9, .9, RGBA(255,255,255,120));  // Draw a jpeg
            // }

            rect letter = {
                .x = 350,
                .y = 300,
                .width = 150,
                .height = 150
            };
 
            bool hovering_letter = GRRLIB_PtInRect(letter.x, letter.y, letter.width, letter.height, mote.x, mote.y);


            // Go to letter
            if (hovering_letter) {
                GRRLIB_Rectangle(letter.x, letter.y, letter.width, letter.height, RGBA(255,255,255,50), true);
                if (mote.a_pressed) {
                    showing_letter = true;
                }
            } else {
                GRRLIB_Rectangle(letter.x, letter.y, letter.width, letter.height, RGBA(255,255,255,50), false);
            }
        }

        
        // Continue button. Clicking stars fadeout, after which next step in the dialogue.
        float continue_x = showing_letter ? 520 : 213;
        float continue_y_offset = showing_letter ? letter_y : 0;
        bool continue_hover = continue_button::draw(continue_x, 406 + continue_y_offset, t, slide_opacity, mote.x, mote.y);
        if (showing_letter && continue_hover && mote.a_pressed && letter_opacity > 240) {
            showing_letter = false;
            viewed_letter = true;
        } else {
            if (continue_hover && mote.a_pressed) {
                if (viewed_letter) {
                    // Next scene
                    // 
                    GRRLIB_Render();
                    outro = true;
                    continue_button::choose();
                    
                } else {
                    // Show and hide the letter
                    if (showing_letter) {
                        showing_letter = false;
                        viewed_letter = true;
                    } else {
                        showing_letter = true;
                    }
                }
            }
        }
        
        if (outro) {
            outro_i++;
        }

        if (outro_i > 120) {
            GRRLIB_FreeTexture(writing_img);
            GRRLIB_FreeTexture(letter_img);
            continue_button::reset_chosen();
            return Scene::GolfClass;
        }
     
        cursor::draw(mote.x, mote.y);
        music::check_loop();

        GRRLIB_Render();
    }

    return Scene::Title;   
}

