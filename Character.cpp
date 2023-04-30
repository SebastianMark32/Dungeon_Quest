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
int Character::getCurrentTile() {
    return currentTile;
}
void Character::setCurrentTile(int currentTile) {
    this->currentTile = currentTile;
}
void setHealth(int health){
}
