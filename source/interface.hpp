#pragma once

#include "grrlib.h"

// Font
#include "BMfont4_png.h"
#include "cursor_png.h"

// Graphics
#include "continue_png.h"
#include "continue_hover_png.h"
#include "loading_jpg.h"


// Includes
#include "scene.hpp"
#include "math.hpp"
#include "utils.hpp"
#include <algorithm>    // std::min


namespace textbox {
    GRRLIB_texImg* font_texture;

    void load_font_texture() {
        font_texture = GRRLIB_LoadTexture(BMfont4_png);
        GRRLIB_InitTileSet(font_texture, 16, 16, 32);
    }
}



struct ChoiceButton {
    GRRLIB_texImg* texture;
    GRRLIB_texImg* hover_texture;

    float hover_alpha = 0;
    float w;
    float h;

    bool hover_active = true;

    bool chosen = false;
    float chosen_alpha = 255;
    float chosen_scale = 1.;
    
    ChoiceButton(GRRLIB_texImg* tex, GRRLIB_texImg* hover_tex, float width, float height) {
        texture = tex;
        hover_texture = hover_tex;
        w = width;
        h = height;
    }

    void choose() {
        chosen = true;
    }


    // Returns if the button is being hovered
    bool draw(float x, float y, float t, float max_opacity, float cursor_x, float cursor_y) {
        float alpha, scale, offset_x, offset_y;

        if (chosen) { // Button has been clicked
            SYS_Report("CHOSEN!"); // Log to check if

            chosen_alpha = lrp(chosen_alpha, 0, .05);
            alpha = chosen_alpha;
            // float scale = map(sin(i / 10.0), -1.0, 1.0, .9, 1.);
            chosen_scale = lrp(chosen_scale, 2., .05); // 1.;//map(sin(t / 30.0), -1.0, 1.0, 1.0, 1.1);
            scale = chosen_scale;
            // float w = 200;
            // float h  = 68;
            
        } else {
            alpha = std::min(map(sin(t / 30.0), -1.0, 1.0, 200.0, max_opacity), max_opacity);
            // float scale = map(sin(i / 10.0), -1.0, 1.0, .9, 1.);
            scale = 1.;//map(sin(t / 30.0), -1.0, 1.0, 1.0, 1.1);        
        }
        
        offset_x = w * scale / 2;
        offset_y = h * scale / 2;
        float final_x = x - offset_x;
        float final_y = y - offset_y;

        
        // Base
        GRRLIB_DrawImg(final_x, final_y, texture, 0, scale, scale, RGBA(255,255,255, alpha));
        // Hover
        GRRLIB_DrawImg(final_x, final_y, hover_texture, 0, scale, scale, RGBA(255,255,255, chosen ? chosen_alpha : hover_alpha));
        
        
        
        bool hover = cursor_x > (x - w / 2) && cursor_y > (y - h / 2) && cursor_x < x + w / 2 && cursor_y < y + h / 2;

        if (!chosen) {
            chosen_scale = scale;
        }

        if (hover && hover_active) {
            // Hover
            hover_alpha = 255;
            // chosen = true;
            return true;
        } else {
            // Not hover
            hover_alpha = lrp(hover_alpha, 0.0, .1);
            return false;
        }
    }
};


namespace loading {
    GRRLIB_texImg* loading = GRRLIB_LoadTexture(loading_jpg);

    void draw() {
        GRRLIB_FillScreen(RGBA(0,0,0,255));
        GRRLIB_DrawImg(0,0,loading, 0, 1, 1, RGBA(255,255,255, 255));
    }

    void hide() {

    }
}



namespace continue_button {
    GRRLIB_texImg* continue_img = GRRLIB_LoadTexture(continue_png);
    GRRLIB_texImg* continue_hover_img = GRRLIB_LoadTexture(continue_hover_png);
    float hover_alpha = 0;
    
    bool hover_active = true;
    bool chosen = false;
    float chosen_alpha = 255;
    float chosen_scale = 1.;
    
    void choose() {
        chosen = true;
    }

    void reset_chosen() {
        chosen = false;
        chosen_alpha = 255;
        chosen_scale = 1.;
    }

    bool draw(float x, float y, float t, float max_opacity, float cursor_x, float cursor_y) {
        float alpha = std::min(map(sin(t / 30.0), -1.0, 1.0, 200.0, max_opacity), max_opacity);
        // float scale = map(sin(i / 10.0), -1.0, 1.0, .9, 1.);
        float scale = map(sin(t / 30.0), -1.0, 1.0, 1.0, 1.1);
        float w = 200;
        float h = 68;
        float offset_x = 200 * scale / 2;
        float offset_y = 68 * scale / 2;

        if (chosen) { // Button has been clicked
            SYS_Report("CHOSEN!"); // Log to check if

            chosen_alpha = lrp(chosen_alpha, 0, .05);
            alpha = chosen_alpha;
            // float scale = map(sin(i / 10.0), -1.0, 1.0, .9, 1.);
            chosen_scale = lrp(chosen_scale, 2., .05); // 1.;//map(sin(t / 30.0), -1.0, 1.0, 1.0, 1.1);
            scale = chosen_scale;
            // float w = 200;
            // float h  = 68;
            
        } else {
            alpha = std::min(map(sin(t / 30.0), -1.0, 1.0, 200.0, max_opacity), max_opacity);
            // float scale = map(sin(i / 10.0), -1.0, 1.0, .9, 1.);
            scale = map(sin(t / 30.0), -1.0, 1.0, 1.0, 1.1);        
        }

        offset_x = w * scale / 2;
        offset_y = h * scale / 2;
        float final_x = x - offset_x;
        float final_y = y - offset_y;

        
        // Base
        GRRLIB_DrawImg(final_x, final_y, continue_img, 0, scale, scale, RGBA(255,255,255, alpha));
        // Hover
        GRRLIB_DrawImg(final_x, final_y, continue_hover_img, 0, scale, scale, RGBA(255,255,255, chosen ? chosen_alpha : hover_alpha));
        
        
        
        bool hover = cursor_x > (x - w / 2) && cursor_y > (y - h / 2) && cursor_x < x + w / 2 && cursor_y < y + h / 2;

        if (!chosen) {
            chosen_scale = scale;
        }

        if (hover && hover_active) {
            // Hover
            hover_alpha = 255;
            // chosen = true;
            return true;
        } else {
            // Not hover
            hover_alpha = lrp(hover_alpha, 0.0, .1);
            return false;
        }
    }


    void set_position() {

    }
    
    void draw() {

    }

    void hovering(int x, int y) {

    }
}


namespace cursor {
    GRRLIB_texImg* cursor_img;

    void load() {
        cursor_img = GRRLIB_LoadTexture(cursor_png);
    }

    void draw(int x, int y) { // TODO add tilt?
        GRRLIB_DrawImg(x, y, cursor_img, 0, 1, 1, RGBA(255,255,255, 255));  // Draw a jpeg
    }
}
