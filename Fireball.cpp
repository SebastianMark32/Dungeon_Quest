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

void Fireball::move(Level currentLevel) {
    if (currentDirection == up && currentLevel.isTileXWalkable(currentTile - 16)){
        currentTile -= 16;
        sprite.move(0, -121.0f);
    }
    if (currentDirection == down && currentLevel.isTileXWalkable(currentTile + 16)){
        currentTile += 16;
        sprite.move(0, 121.0f);
    }
    if (currentDirection == left && currentLevel.isTileXWalkable(currentTile - 1)){
        currentTile -= 1;
        sprite.move(-121.0f, 0);
    }
    if (currentDirection == right && currentLevel.isTileXWalkable(currentTile + 1)){
        currentTile += 1;
        sprite.move(121.0f, 0);
    }
    else{
        sprite.setPosition(-100, -100);
    }
}

void Fireball::shoot(int direction, int currentTile, sf::Vector2f cords) {
    this->currentDirection = static_cast<Fireball::direction>(direction);
    this->currentTile = currentTile;
    sprite.setPosition(cords);
}


int Fireball::getCurrentTile() {
    return 0;
}

void Fireball::setCurrentTile(int currentTile) {

}

