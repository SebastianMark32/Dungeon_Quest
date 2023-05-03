// Created by Cyborg on 4/29/23.

#ifndef DUNGEON_QUEST_FIREBALL_H
#define DUNGEON_QUEST_FIREBALL_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Sound.h"

class Fireball {
public:
    Fireball(std::string path);

    void setTexture(std::string path);

    sf::Sprite* getSprite();

    void move();

    int getCurrentTile();

    void shoot(int direction, int currentTile, sf::Vector2f cords);

    void setCurrentTile(int currentTile);


private:
    enum direction{up = 1, down = 2, left = 3, right = 4};
    direction currentDirection;
    sf::Texture texture;
    sf::Sprite sprite;
    int currentTile;

};
#endif //DUNGEON_QUEST_FIREBALL_H
