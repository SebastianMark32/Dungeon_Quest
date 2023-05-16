/**
 * This class is for the hero/main character
 *
 * @author Nathan Clark and Sebastian Mark
 */

#include "Character.h"

// constructor for the character
//constructors
Character::Character(std::string path, std::string walkSoundPath){
    this->texture.loadFromFile(path);
    this->sprite.setTexture(texture);
    this->walkSound.setSound(walkSoundPath);
}

// overloaded constructor
Character::Character(std::string path, sf::IntRect textRec, std::string walkSoundPath) {
    this->texture.loadFromFile(path);
    this->sprite.setTextureRect(textRec);
    this->sprite.setTexture(texture);
    this->walkSound.setSound(walkSoundPath);
    this->walkSound.getSound().setVolume(50);
}

// setting character (hero) position
void Character::setPosition(float x, float y){
    this->sprite.setPosition(x, y);
}
// setting scale/size of the hero
void Character::setScale(float x, float y){
    this->sprite.setScale(x, y);
}
// returning the position of the hero when called
sf::Vector2f Character::getPosition() {
    return this->sprite.getPosition();
}
// returns the sprite object when called
sf::Sprite* Character::getSprite(){
    return &this->sprite;
}

// returns current tile for the hero
int Character::getCurrentTile() {
    return currentTile;
}
// setting current tile for the hero
void Character::setCurrentTile(int currentTile) {
    this->currentTile = currentTile;
}
// movement function for the x,y axis

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
