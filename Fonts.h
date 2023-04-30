#ifndef DUNGEON_QUEST_FONTS_H
#define DUNGEON_QUEST_FONTS_H

#include <string>
#include <SFML/Graphics.hpp>

class Fonts {

public:
    /**
     * declaring parameter for the constructor
     * using this in the Enemy.cpp file
     ***/
    Fonts(std::string font_path);

    void setSize(float size);

    void setString(std::string message);

    void setStyle(sf::Text::Style style);

    void setPosition(float x, float y);

    sf::Text getText();

private:
    sf::Font fonts;
    sf::Text text1;
};
#endif //DUNGEON_QUEST_FONTS_H
