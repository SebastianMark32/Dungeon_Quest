#include "Character.h"

Character::Character(std::string path){
    this->texture.loadFromFile(path);
    this->sprite.setTexture(texture);
}

Character::Character(std::string path, sf::IntRect textRec) {
    this->texture.loadFromFile(path);
    this->sprite.setTextureRect(textRec);
    this->sprite.setTexture(texture);
}

void Character::setPosition(float x, float y){
    this->sprite.setPosition(x, y);
}

void Character::setScale(float x, float y){
    this->sprite.setScale(x, y);
}

sf::Vector2f Character::getPosition() {
    return this->sprite.getPosition();
}

sf::Sprite* Character::getSprite(){
    return &this->sprite;
}

void Character::setTile(int tileIndex) {
    this->currentTile = tileIndex;
}

void setHealth(int health){

}
