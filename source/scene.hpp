#pragma once


const float slide_speed = 0.03;


enum class Scene {
    Title, 
    Intro, 
    BuyingACar,
    BreakingUpWithAFriend,
    LetterToMunincipality,
    Hotel,
    GolfClass,
    GolfMurder,
    Bowling,
    Nintendogs,
    CleaningMachine,
    Biking,
    MarioKart,
    Ending
};  


struct rect {
    int x, y, width, height;
};