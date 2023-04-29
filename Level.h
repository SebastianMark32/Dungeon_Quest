//
// Created by Cyborg on 4/28/23.
//

#ifndef DUNGEON_QUEST_LEVEL_H
#define DUNGEON_QUEST_LEVEL_H
#include "TileMap.h"
#include <SFML/Graphics.hpp>

class Level {
public:
    Level();
    TileMap* getTilemap();
    void nextLevel();

private:
    TileMap levelDesign;
    int currentLevel;

};


#endif //DUNGEON_QUEST_LEVEL_H
