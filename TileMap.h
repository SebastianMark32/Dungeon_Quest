#ifndef DUNGEON_QUEST_TILEMAP_H
#include <string>
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
#define DUNGEON_QUEST_TILEMAP_H

class TileMap : public sf::Drawable, public sf::Transformable {
public:
    bool load(const std::string &tileset, sf::Vector2u tileSize, const int *tiles, unsigned int width, unsigned int height);
private:
    sf::VertexArray m_vertices;
    sf::Texture m_tileset;
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};
#endif //DUNGEON_QUEST_TILEMAP_H
