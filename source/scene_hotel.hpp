#pragma once

#include "grrlib.h"
#include "colors.hpp"
#include "interface.hpp"
#include "scene.hpp"


#include "hotelbackground_jpg.h"
#include "hotel_finalscene_jpg.h"
#include "hotelbackground_with_characters_jpg.h"
#include "hotel_serguhhh_png.h"
#include "hotel_serguhhh_aggro_png.h"
#include "hotel_serguhhh_fight_png.h"
#include "hotel_alisha_png.h"
#include "hotel_alisha_fight_png.h"

#include "hotel_button_fight_png.h"
#include "hotel_button_fight_hover_png.h"
#include "hotel_button_flight_png.h"
#include "hotel_button_flight_hover_png.h"

#include "hotel_balloon_1_png.h"
#include "hotel_textballoon_serguhhh_1_png.h"
#include "hotel_textballoon_serguhhh_2_png.h"
#include "hotel_textballoon_serguhhh_3_png.h"
#include "hotel_textballoon_serguhhh_4_png.h"
#include "hotel_textballoon_serguhhh_5_png.h"

#include "hotel_textballoon_alisha1_png.h"
#include "hotel_textballoon_alisha2_png.h"
#include "hotel_textballoon_alisha3_png.h"
#include "hotel_textballoon_alisha4_png.h"
#include "hotel_textballoon_alisha5_png.h"



enum class Character {
    Serguhhh, Alisha
};


// struct TextBalloon {
//     Character speaker;
//     GRRLIB_texImg* texture;
// };



Scene scene_hotel() {
    music::play_serguhh_loop();


    GRRLIB_texImg* background = GRRLIB_LoadTexture(hotelbackground_jpg);
    // GRRLIB_texImg* flight = GRRLIB_LoadTexture(hotel);
    
    // GRRLIB_texImg* background_with_characters = GRRLIB_LoadTexture(hotelbackground_with_characters_jpg);

    // Serguhh? (separate)
    GRRLIB_texImg* serguhhh = GRRLIB_LoadTexture(hotel_serguhhh_png);

    // Alisha? (separate) 
    GRRLIB_texImg* alisha = GRRLIB_LoadTexture(hotel_alisha_png);

    // Background: Fighting

    // Text balloon 1
    GRRLIB_texImg* text_balloon = GRRLIB_LoadTexture(hotel_balloon_1_png);

    // TextBalloon text_balloons[] = {
    //     TextBalloon(Character::Serguhhh, hotel_textballoon_serguhhh_1_png)
    // };

    // Text balloon 2

    // Choice 1

    // Choice 2


    // Characters
    float characters_opacity = 0;
    float serguhhh_opacity = 0;
    float serguhhh_y = 300;
    float alisha_opacity = 0;
    float alisha_y = 300;

    // Continue button
    float continue_opacity = 0;

    // Fight and flight buttons
    bool show_fight_flight = false;
    float fight_flight_opacity = 0.0;

    ChoiceButton fight_button = ChoiceButton(GRRLIB_LoadTexture(hotel_button_fight_png), GRRLIB_LoadTexture(hotel_button_fight_hover_png), 200, 50);
    ChoiceButton flight_button = ChoiceButton(GRRLIB_LoadTexture(hotel_button_flight_png), GRRLIB_LoadTexture(hotel_button_flight_hover_png), 200, 50);



    // Animation timer
    int t = 0;
    int after_choice_delay = 0;
    int after_continue_delay = 0;

    // Text balloons
    Character currently_speaking = Character::Serguhhh;
    bool transition_down = false;
    float text_balloon_opacity = 0.0;
    float text_balloon_y = -25;
    float text_balloon_x = -50;
    int dialogue_step = 0;

    float slide_opacity = 255.0;
    
    bool bg_transition_down = false;


    while (SYS_MainLoop()) {
        t++;
        
        controller mote = update_wiimote();

        // Transition in
        float transition_in_speed = 0.05;
        if (!flight_button.chosen) {
            serguhhh_opacity = lrp(serguhhh_opacity, 255, transition_in_speed);
            serguhhh_y = lrp(serguhhh_y, 0, transition_in_speed);
        }

        // Wait before alisha jumps in
        if (t > 12 && !flight_button.chosen) {
            alisha_opacity = lrp(alisha_opacity, 255, transition_in_speed);
            alisha_y = lrp(alisha_y, 0, transition_in_speed);
        }

        if (flight_button.chosen ) {
            alisha_opacity = serguhhh_opacity = text_balloon_opacity =  lrp(alisha_opacity, 0, slide_speed);
            alisha_y = serguhhh_y = lrp(alisha_y, 50, transition_in_speed);
            text_balloon_y = lrp(text_balloon_y, -50, .1);
        }

        // Wait before text balloon
        if ((t > 120 && t < 200) && !flight_button.chosen) {
            text_balloon_y = lrp(text_balloon_y, -50, .1);
            text_balloon_opacity = lrp(text_balloon_opacity, 255, transition_in_speed);
        }
        if (t > 140) {
            if (show_fight_flight || ((fight_button.chosen || flight_button.chosen) && after_choice_delay < 180)) {
                continue_opacity = lrp(continue_opacity, 0, transition_in_speed);
            } else {
                continue_opacity = lrp(continue_opacity, 255, transition_in_speed);
            }
        }



        // Draw background and characters 
        // Background  
        GRRLIB_DrawImg(0, 0, background, 0, 1, 1, RGBA(255,255,255, slide_opacity)); 
        // GRRLIB_DrawImg(0, 0, background_with_characters, 0, 1, 1, RGBA(255,255,255, characters_opacity));  

        // Characters
        GRRLIB_DrawImg(0, 50 + serguhhh_y, serguhhh, 0, 1, 1, RGBA(255,255,255, serguhhh_opacity)); 
        GRRLIB_DrawImg(250, 50 + alisha_y, alisha, 0, 1, 1, RGBA(255,255,255, alisha_opacity));  // Draw a jpeg

        

        // Continue button. Clicking stars fadeout, after which next step in the dialogue.
        bool continue_hover = continue_button::draw(550, 425, t, continue_opacity, show_fight_flight ? 2000 : mote.x, mote.y);
        if (continue_hover && mote.a_pressed) {
            transition_down = true;
            after_continue_delay = 0;
        }

        // Dialogue logic
        if (t > 200) {
            if (fight_button.chosen || transition_down) {
                text_balloon_opacity = lrp(text_balloon_opacity, 0.0, .1);
                text_balloon_y = lrp(text_balloon_y, -25, .1);
            } else {
                text_balloon_opacity = lrp(text_balloon_opacity, 255, .1);
                text_balloon_y = lrp(text_balloon_y, -50, .1);
            }

            if (transition_down) {
                after_continue_delay++;

                if (flight_button.chosen) {
                    slide_opacity = lerp(slide_opacity, 0, slide_speed);
                }

                if (after_continue_delay > 60) {
                    transition_down = false;

                    if (flight_button.chosen || fight_button.chosen) {
                        return Scene::Ending;
                    }
                    
                    dialogue_step++;

                    GRRLIB_FreeTexture(text_balloon);


                    // Next step in the dialogue
                    if (dialogue_step == 1) { // "ID?"
                        text_balloon = GRRLIB_LoadTexture(hotel_textballoon_alisha1_png);
                        currently_speaking = Character::Alisha;
                    }
                    if (dialogue_step == 2) { // "Also in the water."
                        text_balloon = GRRLIB_LoadTexture(hotel_textballoon_serguhhh_2_png);
                        currently_speaking = Character::Serguhhh;
                    }
                    if (dialogue_step == 3) { // "Name?"
                        text_balloon = GRRLIB_LoadTexture(hotel_textballoon_alisha2_png);
                        currently_speaking = Character::Alisha;
                    }
                    if (dialogue_step == 4) { // "Serguuhhhh."
                        text_balloon = GRRLIB_LoadTexture(hotel_textballoon_serguhhh_3_png);
                        currently_speaking = Character::Serguhhh;
                    }
                    if (dialogue_step == 5) { // ...
                        text_balloon = GRRLIB_LoadTexture(hotel_textballoon_alisha3_png);
                        currently_speaking = Character::Alisha;
                    }
                    if (dialogue_step == 6) { // "The profile that checked in hasn't been active since 2006."
                        text_balloon = GRRLIB_LoadTexture(hotel_textballoon_alisha4_png);
                        currently_speaking = Character::Alisha;
                    }
                    if (dialogue_step == 7) { // "Yeah. Long story. I've been jumping systems for a while. I'm very good at it now."
                        text_balloon = GRRLIB_LoadTexture(hotel_textballoon_serguhhh_4_png);
                        currently_speaking = Character::Serguhhh;
                    }
                    if (dialogue_step == 8) { // "How good?"
                        text_balloon = GRRLIB_LoadTexture(hotel_textballoon_alisha5_png);
                        currently_speaking = Character::Alisha;
                    }
                    if (dialogue_step == 9) { // ...
                        text_balloon = GRRLIB_LoadTexture(hotel_textballoon_serguhhh_5_png);
                        currently_speaking = Character::Serguhhh;
                        serguhhh = GRRLIB_LoadTexture(hotel_serguhhh_aggro_png);
                        show_fight_flight = true;
                    }
                    if (dialogue_step == 10) { // [FIGHT] [FLIGHT]
                    }

                    
                    if (dialogue_step == 12) { // 
                        // return Scene::Hotel;
                    }
                } 
            } else {
                // slide_opacity = lerp(slide_opacity, 255, slide_speed);
            }
        }
        



        // Text balloons
        int text_balloon_x = currently_speaking == Character::Alisha ? 175 : -50;
        GRRLIB_DrawImg(text_balloon_x, text_balloon_y, text_balloon, 0, 1, 1, RGBA(255,255,255, text_balloon_opacity)); 

        // Fight or flight
        if (show_fight_flight) {
            fight_button.hover_active = true;
            flight_button.hover_active = true;
            fight_flight_opacity = lrp(fight_flight_opacity, 255, .3);
        } else {
            fight_button.hover_active = false;
            flight_button.hover_active = false;
            fight_flight_opacity = lrp(fight_flight_opacity, 0, .3);
        }

        bool fight_hover = fight_button.draw(500, 360, t, fight_flight_opacity, mote.x, mote.y);
        bool flight_hover = flight_button.draw(500, 410, t + 30, fight_flight_opacity, mote.x, mote.y);

        // Fight chosen!
        if (fight_hover && mote.a_pressed) {
            serguhhh = GRRLIB_LoadTexture(hotel_serguhhh_fight_png);
            alisha = GRRLIB_LoadTexture(hotel_alisha_fight_png);
            // fight_button.choose();
            fight_button.chosen = true;
            show_fight_flight = false;
            // return Scene::Title;
        }
        

        // Flight chosen!
        if (flight_hover && mote.a_pressed) {
            flight_button.chosen = true;
            show_fight_flight = false;
            // transition_down = true;
            bg_transition_down = true;
            // return Scene::Title;
        }

        if (fight_button.chosen || flight_button.chosen) {
            after_choice_delay++;
        }

        if (flight_button.chosen) {
            if (bg_transition_down) {
                slide_opacity = lrp(slide_opacity, 0, slide_speed);
                if (slide_opacity < 10) {
                    bg_transition_down = false;
                    // GRRLIB_FreeTexture(background);
                    // Choices
                    background =  GRRLIB_LoadTexture(hotel_finalscene_jpg);
                }
            } else {
                slide_opacity = lrp(slide_opacity, 255, slide_speed);
            }
        }
        
        

        // GRRLIB_DrawImg(400, 340, fight_button, 0, 1, 1, RGBA(255,255,255,fight_flight_opacity));
        // GRRLIB_DrawImg(400, 390, flight_button, 0, 1, 1, RGBA(255,255,255,fight_flight_opacity));


        cursor::draw(mote.x, mote.y);
        music::check_loop();

        GRRLIB_Render();
    }
}