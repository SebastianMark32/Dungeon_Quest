#include "Enemy.h"

Enemy::Enemy(std::string path) {
    this->texture.loadFromFile(path);
    this->sprite.setTexture(texture);
    this->alive = true;
}
Enemy::Enemy(std::string path, sf::IntRect textRec) {
    this->texture.loadFromFile(path);
    this->sprite.setTextureRect(textRec);
    this->sprite.setTexture(texture);
    this->alive = true;
}

void Enemy::setPosition(float x, float y) {
    this->sprite.setPosition(x, y);
}
void Enemy::setScale(float x, float y) {
    this->sprite.setScale(x, y);
}
sf::Sprite * Enemy::getSprite() {
    return &this->sprite;
}

bool Enemy::isAlive(){
    return this->alive = true;
}
void Enemy::set_Alive(bool alive) {
    this->alive = alive;
}

// Nate's code for random enemy movement
void Enemy::randomEnemyMove(int number, Level* currentLevel){

    // we need to comment
    number = number % 4;
    if (number == 0 && currentLevel->isTileXWalkable(this->currentTile - 16)){
        this->currentTile -= 16;
        sprite.move(0.0f, -121.0f);
    }
    if (number == 1 && currentLevel->isTileXWalkable(this->currentTile - 1)){
        this->currentTile -= 1;
        sprite.move(-121.0f, 0.0f);
    }
    if (number == 2 && currentLevel->isTileXWalkable(this->currentTile + 16)){
        this->currentTile += 16;
        sprite.move(0.0f, 121.0f);
    }
    if (number == 3 && currentLevel->isTileXWalkable(this->currentTile + 1)) {
        this->currentTile += 1;
        sprite.move(121.0f, 0.0f);
    }
}
//A random respawn method in case an enemy object "dies"
void Enemy::respawn(int number){
    number = number % 3;
    switch (number){
        case 0:
            sprite.setPosition(968.f, 484.f);
            currentTile = 72;
            break;
        case 1:
            sprite.setPosition(968.f, 484.f);
            currentTile = 72;
            break;
        case 2:
            sprite.setPosition(968.f, 484.f);
            currentTile = 72;
            break;
        case 3:
            sprite.setPosition(968.f, 484.f);
            currentTile = 72;
            break;
        default:
            break;
    }
}
int Enemy::getCurrentTile() {
    return this->currentTile;
}
void Enemy::setCurrentTile(int currentTile) {
    this->currentTile = currentTile;
}
