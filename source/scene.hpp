#pragma once



enum class Scene {
    Title, 
    Intro, 
    BuyingACar,
    BreakingUpWithAFriend,
    LetterToMunincipality,
    LostKeyCard,
    SceneGolfClass,
    SceneGolfAggression,
    SceneNintendogs,
    SceneCleaningMachine,
    SceneBiking,
    SceneMarioKart,
    Ending
};  


struct rect {
    int x, y, width, height;
};