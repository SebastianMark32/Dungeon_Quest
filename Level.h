// Created by Nate on 4/28/23.
#ifndef DUNGEON_QUEST_LEVEL_H
#define DUNGEON_QUEST_LEVEL_H
#include "TileMap.h"
#include <SFML/Graphics.hpp>


class Level {
public:
    Level(std::string tileMapPath);

    TileMap* getTilemap();

    void nextLevel();

    bool isTileXWalkable(int indexX);

    void setTileMapPath(std::string timeMapPath);

    int getCurrentLevel();


private:
    void level2();
    void level3();
    TileMap levelDesign;
    std::string tileMapPath;
    int currentLevel;
    bool tileIsWalkable[144];


};
#endif //DUNGEON_QUEST_LEVEL_H
