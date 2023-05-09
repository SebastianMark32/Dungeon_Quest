#ifndef DUNGEON_QUEST_ENEMY_H
#define DUNGEON_QUEST_ENEMY_H

#include <string>
#include <SFML/Graphics.hpp>
#include "Level.h"
#include "Animation.h"
#include "Sound.h"

class Enemy{

public:

    /**
     * declaring parameter for the constructor
     * using this in the Enemy.cpp file
     ***/
    Enemy(std::string path);

    Enemy(std::string path, sf::IntRect textRec);

    void setPosition(float x, float y);

    void setScale(float x, float y);

    sf::Sprite * getSprite();

    void randomEnemyMove(int number, Level* currentLevel);

    int getCurrentTile();

    void setCurrentTile(int currentTile);

    int getDamage(int damage);

    void respawn(int number);

private:
    sf::Sprite sprite;
    sf::Texture texture;
    int currentTile;
};
#endif //DUNGEON_QUEST_ENEMY_H
