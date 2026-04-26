#pragma once

#include "grrlib.h"


// Font
#include "BMfont4_png.h"
#include "cursor_png.h"

#include "scene.hpp"




namespace textbox {
    GRRLIB_texImg* font_texture;

    void load_font_texture() {
        font_texture = GRRLIB_LoadTexture(BMfont4_png);
        GRRLIB_InitTileSet(font_texture, 16, 16, 32);
    }
}


namespace continue_button {
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
