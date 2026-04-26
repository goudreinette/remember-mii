#include <asndlib.h>
#include <grrlib.h>
#include <math.h>
#include <mp3player.h>
#include <ogc/lwp_watchdog.h>  // Needed for gettime and ticks_to_millisecs
#include <stdio.h>
#include <stdlib.h>
#include <wiiuse/wpad.h>
#include <format>
#include <iostream>
#include <string>
#include <vector>


// Includes
#include "colors.hpp"
#include "math.hpp"
#include "random.hpp"
#include "interface.hpp"

// Font
#include "BMfont2_png.h"
#include "BMfont4_png.h"

// Images
#include "remember_mii_jpg.h"

// Sounds
// -

// Scenes
#include "scene.hpp"
#include "scene_title.hpp"
#include "scene_lostkeycard.hpp"
#include "scene_lettertomunincipality.hpp"
#include "scene_ending.hpp"
#include "scene_buyingacar.hpp"
#include "scene_breakingupwithfriend.hpp"
#include "scene_cleaningmachine.hpp"
#include "scene_golfaggression.hpp"
#include "scene_intro.hpp"
#include "scene_golfclass.hpp"
#include "scene_biking.hpp"


// Random
using Random = effolkronium::random_static;

// Size of the sketch (fix for processing code)
int width;
int height;


int main() {
  // Initialize GRRLIB and WiiMote
  GRRLIB_Init();
  WPAD_Init();
  WPAD_SetDataFormat(WPAD_CHAN_0, WPAD_FMT_BTNS_ACC_IR);

  // Set width and height
  width = rmode->viWidth;
  height = rmode->viHeight;

  // Load font
  textbox::load_font_texture();

  // Initialize MP3 player and load sounds
  ASND_Init();
  MP3Player_Init();

  WPAD_SetVRes(0, width, height);

  Scene current_scene = Scene::Title;
  Scene next_scene;
  cursor::load();
  
  while (true) {
    if (current_scene == Scene::Title) {
		next_scene = scene_title();
	} else if (current_scene == Scene::Intro) {
		next_scene = scene_intro();
	} else if (current_scene == Scene::BuyingACar) {
		next_scene = scene_buyingacar();
	} else if (current_scene == Scene::BreakingUpWithAFriend) {
		next_scene = scene_breakingupwithafriend();
	} else if (current_scene == Scene::LetterToMunincipality) {
		next_scene = scene_lettertomunincipality();
	} else if (current_scene == Scene::LostKeyCard) {
		next_scene = scene_lostkeycard();
	} else if (current_scene == Scene::SceneCleaningMachine) {
		next_scene = scene_cleaningmachine();
	} else if (current_scene == Scene::SceneGolfClass) {
		next_scene = scene_golfclass();
	} else if (current_scene == Scene::SceneGolfAggression) {
		next_scene = scene_golfaggression();
	} else if (current_scene == Scene::SceneBiking) {
		next_scene = scene_biking();
	} else if (current_scene == Scene::Ending) {
		next_scene = scene_ending();
	}

	current_scene = next_scene;
  }

	// GRRLIB_FreeTexture(fontTexture);
	GRRLIB_Exit();  // Be a good boy, clear the memory allocated by GRRLIB
	return 0;
}