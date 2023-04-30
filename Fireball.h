//
// Created by Cyborg on 4/29/23.
//

#ifndef DUNGEON_QUEST_FIREBALL_H
#define DUNGEON_QUEST_FIREBALL_H
#include <SFML/Graphics.hpp>

class Fireball {
public:
    Fireball(std::string path);

    void setTexture(std::string path);

    sf::Sprite* getSprite();

    void move();

    int getCurrentTile();

    void shoot(int direction, int newCurrentTile, sf::Vector2f cords);

    void setCurrentTile(int newCurrentTile);

private:
    enum direction{up = 1, down = 2, left = 3, right = 4};
    direction currentDirection;
    sf::Texture texture;
    sf::Sprite sprite;
    int currentTile;
};


#endif //DUNGEON_QUEST_FIREBALL_H
