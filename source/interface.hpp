#pragma once

#include "grrlib.h"

// Font
#include "BMfont4_png.h"
#include "cursor_png.h"

// Graphics
#include "continue_png.h"
#include "continue_hover_png.h"


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


namespace continue_button {
    GRRLIB_texImg* continue_img = GRRLIB_LoadTexture(continue_png);
    GRRLIB_texImg* continue_hover_img = GRRLIB_LoadTexture(continue_hover_png);

    bool draw(float x, float y, float t, float max_opacity, float cursor_x, float cursor_y) {
        float alpha = std::min(map(sin(t / 30.0), -1.0, 1.0, 200.0, max_opacity), max_opacity);
        // float scale = map(sin(i / 10.0), -1.0, 1.0, .9, 1.);
        float scale = map(sin(t / 30.0), -1.0, 1.0, 1.0, 1.1);
        float w = 200;
        float h = 68;
        float offset_x = 200 * scale / 2;
        float offset_y = 68 * scale / 2;
        
        
        if (cursor_x > (x - w / 1.5) && cursor_y > (y - h / 1.5) && cursor_x < x + w / 1.5 && cursor_y < y + h / 1.5) {
            // Hover
            GRRLIB_DrawImg(x - offset_x, y - offset_y, continue_hover_img, 0, scale, scale, RGBA(255,255,255,255));
            return true;
        } else {
            // Not hover
            GRRLIB_DrawImg(x - offset_x, y - offset_y, continue_img, 0, scale, scale, RGBA(255,255,255, alpha));
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
