#include "Fonts.h"

Fonts::Fonts(std::string font_path){
        this->fonts.loadFromFile(font_path);
        this->text1.setFont(fonts);
}
void Fonts::setSize(float size){
    this->text1.setCharacterSize(size);
}
void Fonts::setString(std::string message){
    this->text1.setString(message);
}
void Fonts::setStyle(sf::Text::Style style){
    this->text1.setStyle(style);
}
void Fonts::setPosition(float x, float y){
    this->text1.setPosition(x, y);
}
sf::Text Fonts::getText(){
    return this->text1;
}

