#pragma once

#include "scene.hpp"


Scene scene_lostkeycard() {
    while (true) {
        controller mote = update_wiimote();

        if (mote.a_pressed) {
            return Scene::Ending;
        }
    }
}