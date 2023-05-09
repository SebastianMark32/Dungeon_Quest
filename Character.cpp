#include "Character.h"

Character::Character(std::string path, std::string walkSoundPath){
    this->texture.loadFromFile(path);
    this->sprite.setTexture(texture);
    this->walkSound.setSound(walkSoundPath);
}
Character::Character(std::string path, sf::IntRect textRec, std::string walkSoundPath) {
    this->texture.loadFromFile(path);
    this->sprite.setTextureRect(textRec);
    this->sprite.setTexture(texture);
    this->walkSound.setSound(walkSoundPath);
    this->walkSound.getSound().setVolume(50);
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

void Character::move(float offSetX, float offSetY) {
    this->sprite.move(offSetX, offSetY);
    this->walkSound.play();
}

void setHealth(int health){
}
