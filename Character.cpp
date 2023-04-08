#include "Character.h"

Character::Character(std::string path){
    this->texture.loadFromFile(path);
    this->sprite.setTexture(texture);
}

void Character::setPosition(float x, float y){
    this->sprite.setPosition(x, y);
}

void Character::setScale(float x, float y){
    this->sprite.setScale(x, y);
}

sf::Sprite Character::getSprite(){
    return this->sprite;
}