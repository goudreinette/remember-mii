#pragma once

#include "grrlib.h"

#include "scene.hpp"
#include "input.hpp"


Scene scene_title() {


    while (true) {
        controller mote = update_wiimote();
        
        // Draw cursor!
        GRRLIB_Circle(mote.x, mote.y, 25, WHITE, true);


        GRRLIB_Render();
    }
}