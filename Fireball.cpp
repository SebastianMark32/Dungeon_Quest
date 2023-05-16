// Created by Cyborg on 4/29/23.
#include "Fireball.h"

#include <utility>

//constuctor
Fireball::Fireball(std::string path, std::string shootSoundPath, std::string fizzleSoundPath) {
    this->texture.loadFromFile(path);
    this->sprite.setTexture(texture);
    this->sprite.setOrigin(sprite.getGlobalBounds().width/2, sprite.getGlobalBounds().height/2);
    this->shootSound.setSound(std::move(shootSoundPath));
    this->fizzleSound.setSound(std::move(fizzleSoundPath));
    this->shootSound.getSound().setVolume(50);
    this->fizzleSound.getSound().setVolume(50);
    this->isAlive = false;
}

//set fireball sprite
void Fireball::setTexture(std::string path) {
    this->texture.loadFromFile(path);
    this->sprite.setTexture(texture);
}
//get the fireball sprite for direct sprite function calls
sf::Sprite* Fireball::getSprite() {
    return &sprite;
}
//moves the fireball 1 tile
void Fireball::move() {
    if (currentDirection == up){
        currentTile -= 16;
        sprite.move(0, -121.0f);
    }
    if (currentDirection == down){
        currentTile += 16;
        sprite.move(0, 121.0f);
    }
    if (currentDirection == left){
        currentTile -= 1;
        sprite.move(-121.0f, 0);
    }
    if (currentDirection == right){
        currentTile += 1;
        sprite.move(121.0f, 0);
    }
}
//play fireball fizzle sound
void Fireball::playFizzleSound(){
    fizzleSound.play();
}
//shoot the fireball in a given direction
void Fireball::shoot(int direction, int newCurrentTile, sf::Vector2f cords) {
    this->currentDirection = static_cast<Fireball::direction>(direction);
    this->currentTile = newCurrentTile;
    this->isAlive = true;
    sprite.setPosition(cords);
    shootSound.play();
    switch(direction){
        case 1:
            sprite.setRotation(270);
            break;
        case 2:
            sprite.setRotation(90);
            break;

        case 3:
            sprite.setRotation(180);
            break;

        case 4:
            sprite.setRotation(0);
            break;

        default:
            std::cout << "ERROR: direction is an invalid value";
    }
}
//returns current tile of fireball
int Fireball::getCurrentTile() {
    return this->currentTile;
}
//sets current tile of fireball
void Fireball::setCurrentTile(int currentTile) {
    this->currentTile = currentTile;
}
//returns if fireball is active or not
bool Fireball::getIsAlive() {
    return this->isAlive;
}
//sets if fireball is active or not
void Fireball::setIsAlive(bool isAlive){
    this->isAlive = isAlive;
}

