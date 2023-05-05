// Created by Cyborg on 4/28/23.
#include "Level.h"
#include <iostream>
Level::Level() {
    this->currentLevel = 1;
    //level 1 array
    const int level[] = {
            // #78 is a black tile
            78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78,
            78,  0,  1,  2,  3,  4,  1,  2,  3,  4,  1,  2,  3,  4,  5, 78,
            78, 10, 11, 12, 13, 12, 12, 13, 12, 13, 13, 12, 13, 14, 15, 78,
            78, 20, 21,  6,  7,  8,  9,  7,  8,  9, 17, 16,  9, 24, 25, 78,
            78, 30, 21, 16, 17, 27, 28, 29, 18, 17,  7,  6,  7, 24, 35, 78,
            78, 10, 21, 26, 27,  7,  6, 18, 19,  9, 26, 28, 18, 24, 25, 78,
            78, 20, 31, 32, 33, 33, 32, 33, 32, 33, 32, 32, 33, 34, 35, 78,
            78, 40, 41, 42, 43, 41, 42, 43, 44, 41, 42, 43, 44, 41, 45, 78,
            78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78,
    };
    this->levelDesign.load("./Assets/Dungeon_Tileset.png", sf::Vector2u(16, 16), level, 16, 9);
    bool tileisWalkableLevel1[] = {
        false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false,
        false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false,
        false, false,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, false, false,
        false, false,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, false, false,
        false, false,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, false, false,
        false, false,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, false, false,
        false, false,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, false, false,
        false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false,
        false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false,
    };
    for (int i = 0; i < 144; i++){
        tileIsWalkable[i] = tileisWalkableLevel1[i];
    }
}
TileMap* Level::getTilemap() {
    return &levelDesign;
}
void Level::nextLevel() {
    this->currentLevel += 1;
    if (currentLevel == 2) {
        level2();
        return;
    }
    if (currentLevel == 3){
        level3();
        return;
    }
}
bool Level::isTileXWalkable(int indexX) {
    if (indexX < 0 || indexX > 144){
        return false;
    }
    return tileIsWalkable[indexX];
}
void Level::level2() {
    const int level[] = {
            // #78 is a black tile
            0, 1, 2, 3, 4, 5, 78, 78, 78, 78, 0, 1, 2, 3, 4, 5,
            10, 11, 12, 13, 14, 2, 1, 2, 3, 4, 1, 11, 12, 13, 14, 15,
            20, 31, 6, 7, 8, 12, 12, 13, 12, 13, 13, 6, 7, 9, 34, 25,
            40, 55, 21, 6, 7, 8, 9, 7, 8, 9, 17, 16, 9, 24, 54, 45,
            78, 10, 21, 16, 17, 27, 28, 29, 18, 17, 7, 6, 7, 24, 35, 78,
            0, 1, 21, 26, 27, 27, 6, 18, 19, 9, 26, 28, 18, 24, 4, 5,
            20, 11, 17, 18, 19, 33, 32, 33, 32, 33, 32, 8, 7, 6, 14, 25,
            30, 31, 32, 33, 34, 50, 42, 43, 44, 41, 55, 31, 32, 33, 34, 15,
            40, 41, 42, 43, 44, 45, 78, 78, 78, 78, 40, 41, 42, 43, 44, 45,
    };
    this->levelDesign.load("./Assets/Dungeon_Tileset.png", sf::Vector2u(16, 16), level, 16, 9);
    bool tileisWalkableLevel2[] = {
            false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false,
            false, true, true, true, true, false, false, false, false, false, false, true, true, true, true, false,
            false, true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, true, false,
            false, false,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, false, false,
            false, false,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, false, false,
            false, false,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, false, false,
            false, true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, true, false,
            false, true, true, true, true, false, false, false, false, false, false, true, true, true, true, false,
            false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false,
    };
    for (int i = 0; i < 144; i++){
        tileIsWalkable[i] = tileisWalkableLevel2[i];
    }
}
void Level::level3() {
    const int level[] = {
            // #78 is a black tile
             0,  1,  2,  3,  4,  1,  2,  3,  4,  1,  2,  3,  4,  1,  2,  5,
            10, 11, 12, 13, 12, 12, 13, 12, 13, 12, 13, 12, 13, 12, 14, 15,
            20, 21,  6,  7,  8, 26, 27, 27,  6, 18, 17,  6,  7,  9, 24, 25,
            10, 21, 26, 50, 41,  55,  9,  7,  8,  9, 50, 42, 55, 19, 24, 35,
            20, 21,  9,  1,  2, 3, 28, 29, 18, 17,  3,  1,  2,  9, 24, 15,
            10, 21, 23, 26, 27, 27, 6, 18, 19, 9, 26, 28, 18, 6, 24, 25,
            20, 21, 22, 18, 19, 33, 32, 23, 22, 33, 32, 8, 7, 6, 24, 35,
            30, 31, 32, 33, 34, 50, 53, 31, 34, 54, 55, 31, 32, 33, 34, 15,
            40, 41, 42, 43, 44, 45, 40, 41, 42, 45, 40, 41, 42, 43, 44, 45,
    };
    this->levelDesign.load("./Assets/Dungeon_Tileset.png", sf::Vector2u(16, 16), level, 16, 9);
    bool tileisWalkableLevel3[] = {
            false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false,
            false,  true,  true,  true,  true, true, true, true, true, true, true, true, true, true, true, false,
            false, true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, true, false,
            false, true,  true, false, false, false,  true,  true,  true,  true, false, false, false,  true, true, false,
            false, true,  true, false, false, false,  true,  true,  true,  true, false, false, false,  true, true, false,
            false, true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, true, false,
            false,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, true, false,
            false,  true,  true,  true, true, false, false,  true,  true, false, false, true, true, true, true, false,
            false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false,
    };
    for (int i = 0; i < 144; i++){
        tileIsWalkable[i] = tileisWalkableLevel3[i];
    }


}



