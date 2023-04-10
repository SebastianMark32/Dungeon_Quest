#ifndef DUNGEON_QUEST_ENEMY_H
#define DUNGEON_QUEST_ENEMY_H

#include <string>
#include <SFML/Graphics.hpp>

class Enemy{

public:

    /**
     * declaring parameter for the constructor
     * using this in the Enemy.cpp file
     ***/
    Enemy(std::string path);

    void setPosition(float x, float y);

    void setScale(float x, float y);

    sf::Sprite getSprite();

    void randomEnemyMove(int number);

private:
    sf::Sprite sprite;
    sf::Texture texture;

};


#endif //DUNGEON_QUEST_ENEMY_H
