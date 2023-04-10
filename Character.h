#ifndef DUNGEON_QUEST_CHARACTER_H
#include <string>
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
#define DUNGEON_QUEST_CHARACTER_H


class Character{
public:
    /**
     * declaring parameter for the constructor
     * using this in the Character.cpp file
     ***/
    Character(std::string path);

    void setPosition(float x, float y);

    void setScale(float x, float y);

    sf::Vector2f getPosition();

    sf::Sprite* getSprite();

private:
    // making the sprite
    sf::Sprite sprite;
    sf::Texture texture;
};

#endif //DUNGEON_QUEST_CHARACTER_H
