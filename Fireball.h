//
// Created by Cyborg on 4/29/23.
//

#ifndef DUNGEON_QUEST_FIREBALL_H
#define DUNGEON_QUEST_FIREBALL_H
#include <SFML/Graphics.hpp>
#include "Level.h"

class Fireball {
public:
    Fireball(std::string path);

    void setTexture(std::string path);

    sf::Sprite* getSprite();

    void move(Level currentLevel);

    int getCurrentTile();

    void shoot(int direction, int currentTile, sf::Vector2f cords);

    void setCurrentTile(int currentTile);

private:
    enum direction{up = 1, down, left, right};
    direction currentDirection;
    sf::Texture texture;
    sf::Sprite sprite;
    int currentTile;
};


#endif //DUNGEON_QUEST_FIREBALL_H
