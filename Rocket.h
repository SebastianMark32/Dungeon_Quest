#pragma
#include <SFML/Graphics.hpp>
#ifndef DUNGEON_QUEST_ROCKET_H
#define DUNGEON_QUEST_ROCKET_H

class Rocket {
    Rocket();
    ~Rocket();

    void init(std::string textureName, sf::Vector2f position, float _speed);
private:
    sf::Texture m_texture;
    sf::Sprite m_sprite;
    sf::Vector2f  m_position;
    float m_speed;
};
#endif //DUNGEON_QUEST_ROCKET_H
