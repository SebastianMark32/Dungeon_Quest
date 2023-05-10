#ifndef DUNGEON_QUEST_ENEMY_H
#define DUNGEON_QUEST_ENEMY_H

#include <string>
#include <SFML/Graphics.hpp>
#include "Level.h"
#include "Sound.h"

class Enemy{

public:

    /**
     * declaring parameter for the constructor
     * using this in the Enemy.cpp file
     ***/
    Enemy(std::string path);

    Enemy(std::string path, sf::IntRect textRec);

    bool isAlive();

    void set_Alive(bool alive);

    void setPosition(float x, float y);

    void setScale(float x, float y);

    sf::Sprite * getSprite();

    void setSprite(std::string path);

    void randomEnemyMove(int number, Level* currentLevel);

    int getCurrentTile();

    void setCurrentTile(int currentTile);

    int getDamage(int damage);

    void respawn(int number);


private:
    sf::Sprite sprite;
    sf::Texture texture;
    int currentTile;
    bool alive;
};
#endif //DUNGEON_QUEST_ENEMY_H
