#include "Character.h"
//constructors
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
//set posisiton of sprite
void Character::setPosition(float x, float y){
    this->sprite.setPosition(x, y);
}
//set scale of sprite
void Character::setScale(float x, float y){
    this->sprite.setScale(x, y);
}
//return sprite position
sf::Vector2f Character::getPosition() {
    return this->sprite.getPosition();
}
//returns the sprite for direct function calls
sf::Sprite* Character::getSprite(){
    return &this->sprite;
}
//gets player's current tile
int Character::getCurrentTile() {
    return currentTile;
}
//set players current tile
void Character::setCurrentTile(int currentTile) {
    this->currentTile = currentTile;
}
//moves player sprite by given x and y
void Character::move(float offSetX, float offSetY) {
    this->sprite.move(offSetX, offSetY);
    this->walkSound.play();
}
