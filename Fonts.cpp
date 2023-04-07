#include "Fonts.h"


Fonts::Fonts(std::string font_path){
        this->fonts.loadFromFile(font_path);
}

void Fonts::setSize(float size){
    this->text1.setCharacterSize(size);
}

void Fonts::setString(std::string message){
    this->text1.setString(message);
}

sf::Text Fonts::getText(){
    return this->text1;
}

