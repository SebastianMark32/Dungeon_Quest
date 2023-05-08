// Created by Cyborg on 4/29/23.
#include "Fireball.h"

Fireball::Fireball(std::string path, std::string shootSoundPath, std::string fizzleSoundPath) {
    this->texture.loadFromFile(path);
    this->sprite.setTexture(texture);
    this->sprite.setOrigin(sprite.getGlobalBounds().width/2, sprite.getGlobalBounds().height/2);
    this->shootSoundBuffer.loadFromFile(fizzleSoundPath);
    this->shootSound.setBuffer(this->shootSoundBuffer);
    this->fizzleSoundBuffer.loadFromFile(fizzleSoundPath);
    this->fizzleSound.setBuffer(this->fizzleSoundBuffer);
}
void Fireball::setTexture(std::string path) {
    this->texture.loadFromFile(path);
    this->sprite.setTexture(texture);
}
sf::Sprite* Fireball::getSprite() {
    return &sprite;
}
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

void Fireball::playFizzleSound(){
    fizzleSound.play();
}

void Fireball::shoot(int direction, int currentTile, sf::Vector2f cords) {
    this->currentDirection = static_cast<Fireball::direction>(direction);
    this->currentTile = currentTile;
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

int Fireball::getCurrentTile() {
    return this->currentTile;
}
void Fireball::setCurrentTile(int currentTile) {
    this->currentTile = currentTile;
}

