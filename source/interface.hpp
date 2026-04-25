
#pragma once

#include "scene.hpp"

#include "cursor_png.h"
#include "grrlib.h"

bool draw_continue_button(rect) {

}



namespace cursor {
    GRRLIB_texImg* cursor_img;


    void load() {
        cursor_img = GRRLIB_LoadTexture(cursor_png);
    }

    void draw(int x, int y) {
        GRRLIB_DrawImg(x, y, cursor_img, 0, 1, 1, RGBA(255,255,255, 255));  // Draw a jpeg
    }
}
