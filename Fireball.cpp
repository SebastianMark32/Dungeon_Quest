//
// Created by Cyborg on 4/29/23.
//

#include "Fireball.h"

Fireball::Fireball(std::string path) {
    this->texture.loadFromFile(path);
    this->sprite.setTexture(texture);
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

void Fireball::shoot(int direction, int newCurrentTile, sf::Vector2f cords) {
    this->currentDirection = static_cast<Fireball::direction>(direction);
    this->currentTile = newCurrentTile;
    sprite.setPosition(cords);
}


int Fireball::getCurrentTile() {
    return 0;
}

void Fireball::setCurrentTile(int currentTile) {

}

