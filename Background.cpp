#include "Background.h"

Background::Background(std::string path){
    this->texture.loadFromFile(path);
    this->background.setTexture(texture);
}
void Background::setScale(float x, float y){
    this->background.setScale(x,y);
}
sf::Sprite Background::getSprite(){
    return this->background;
}