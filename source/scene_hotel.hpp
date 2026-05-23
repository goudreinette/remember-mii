#pragma once

#include "grrlib.h"
#include "colors.hpp"

#include "scene.hpp"

#include "hotelbackground_jpg.h"
#include "hotelbackground_with_characters_jpg.h"
#include "hotel_serguhhh_png.h"
#include "hotel_alisha_png.h"
#include "hotel_balloon_1_png.h"



Scene scene_hotel() {
    GRRLIB_texImg* background = GRRLIB_LoadTexture(hotelbackground_jpg);
    GRRLIB_texImg* background_with_characters = GRRLIB_LoadTexture(hotelbackground_with_characters_jpg);

    // Serguhh? (separate)
    GRRLIB_texImg* serguhhh = GRRLIB_LoadTexture(hotel_serguhhh_png);

    // Alisha? (separate) 
    GRRLIB_texImg* alisha = GRRLIB_LoadTexture(hotel_alisha_png);
    

    // Background: Fighting

    // Text balloon 1
    GRRLIB_texImg* text_balloon = GRRLIB_LoadTexture(hotel_balloon_1_png);

    
    // Text balloon 2

    // Choice 1

    // Choice 2



    music::play_serguhh_loop();

    float text_balloon_opacity = 0;

    float characters_opacity = 0;
    float serguhhh_opacity = 0;
    float serguhhh_y = 300;
    float alisha_opacity = 0;
    float alisha_y = 300;

    float continue_opacity = 0;
    
    
    int i = 0;

    
    while (true) {
        i++;
        
        controller mote = update_wiimote();

        // Transition in
        float transition_in_speed = 0.05;
        serguhhh_opacity = lerp(serguhhh_opacity, 255, transition_in_speed);
        serguhhh_y = lerp(serguhhh_y, 0, transition_in_speed);

        // Wait before alisha jumps in
        if (i > 12) {
            alisha_opacity = lerp(alisha_opacity, 255, transition_in_speed);
            alisha_y = lerp(alisha_y, 0, transition_in_speed);
        }

        // Wait before text balloon
        if (i > 120) {
            text_balloon_opacity = lerp(text_balloon_opacity, 255, transition_in_speed);
        }
        if (i > 140) {
            continue_opacity = lerp(continue_opacity, 255, transition_in_speed);
        }
        



        
        // Background  
        GRRLIB_DrawImg(0, 0, background, 0, 1, 1, RGBA(255,255,255, 255)); 
        // GRRLIB_DrawImg(0, 0, background_with_characters, 0, 1, 1, RGBA(255,255,255, characters_opacity));  

        // Characters
        GRRLIB_DrawImg(0, 50 + serguhhh_y, serguhhh, 0, 1, 1, RGBA(255,255,255, serguhhh_opacity)); 
        GRRLIB_DrawImg(250, 50 + alisha_y, alisha, 0, 1, 1, RGBA(255,255,255, alisha_opacity));  // Draw a jpeg

        // Text balloons
        GRRLIB_DrawImg(-50, -50, text_balloon, 0, 1, 1, RGBA(255,255,255, text_balloon_opacity)); 

        // Choices


        bool continue_hover = continue_button::draw(550, 400, i, continue_opacity, mote.x, mote.y);
        if (mote.a_pressed) {
            // return Scene::Ending;
        }

        cursor::draw(mote.x, mote.y);

        GRRLIB_Render();
    }
}