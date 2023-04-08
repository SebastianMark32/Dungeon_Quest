#ifndef DUNGEON_QUEST_BACKGROUND_H
#include <SFML/Graphics.hpp>
#include <string>
#define DUNGEON_QUEST_BACKGROUND_H


class Background{
public:
    Background(std::string path);

    void setScale(float x, float y);

    sf::Sprite getSprite();

private:
    //making the background
    sf::Texture texture;
    sf::Sprite background;
};
#endif //DUNGEON_QUEST_BACKGROUND_H
