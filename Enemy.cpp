#include "Enemy.h"

Enemy::Enemy(std::string path) {
    this->texture.loadFromFile(path);
    this->sprite.setTexture(texture);
    this->alive = true;
    this->isBoss = false;
}
Enemy::Enemy(std::string path, sf::IntRect textRec) {
    this->texture.loadFromFile(path);
    this->sprite.setTextureRect(textRec);
    this->sprite.setTexture(texture);
    this->alive = true;
    this->isBoss = false;
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

void Enemy::setSprite(std::string path) {
    this->texture.loadFromFile(path);
    this->sprite.setTexture(texture);
}
//retunrs if enemy is alive
bool Enemy::isAlive(){
    return this->alive;
}
//sets if enemy is alive or not
void Enemy::set_Alive(bool alive) {
    this->alive = alive;
}

/********************************************************
* randomEnemyMove - randomly moves an enemy
*
* Parameters
* number - random number
* Level* - Pointer to level object for function calls based on level
*
* Return - false if no fireballs shot, true if boss shoots fireball
********************************************************/
bool Enemy::randomEnemyMove(int number, Level* currentLevel){
    // we need to comment NO! COMMENTING ISN'T FOR REAL MEN!

    //if the enemy is not a boss randomly move up, down, left, or right
    if (!isBoss) {
        number = number % 4;
        if (number == 0 && currentLevel->isTileXWalkable(this->currentTile - 16)) {
            this->currentTile -= 16;
            sprite.move(0.0f, -121.0f);
        }
        if (number == 1 && currentLevel->isTileXWalkable(this->currentTile - 1)) {
            this->currentTile -= 1;
            sprite.move(-121.0f, 0.0f);
        }
        if (number == 2 && currentLevel->isTileXWalkable(this->currentTile + 16)) {
            this->currentTile += 16;
            sprite.move(0.0f, 121.0f);
        }
        if (number == 3 && currentLevel->isTileXWalkable(this->currentTile + 1)) {
            this->currentTile += 1;
            sprite.move(121.0f, 0.0f);
        }
        return false;
    }
    else{
        //if enemy is a boss randomly move left, right, up, down, or shoot fireballs
        number = number % 5;
        if (number == 0 && currentLevel->isTileXWalkable(this->currentTile - 16)) {
            this->currentTile -= 16;
            sprite.move(0.0f, -121.0f);
        }
        if (number == 1 && currentLevel->isTileXWalkable(this->currentTile - 1)) {
            this->currentTile -= 1;
            sprite.move(-121.0f, 0.0f);
        }
        if (number == 2 && currentLevel->isTileXWalkable(this->currentTile + 16)) {
            this->currentTile += 16;
            sprite.move(0.0f, 121.0f);
        }
        if (number == 3 && currentLevel->isTileXWalkable(this->currentTile + 1)) {
            this->currentTile += 1;
            sprite.move(121.0f, 0.0f);
        }
        if (number == 4){
            return true;
        }
        return false;
    }
}
int Enemy::getCurrentTile() {
    return this->currentTile;
}
void Enemy::setCurrentTile(int currentTile) {
    this->currentTile = currentTile;
}

//function to make enemy use Boss AI.
void Enemy::setBoss(bool isBoss) {
    this->isBoss = isBoss;
}

bool Enemy::getBoss(){
    return this->isBoss;
}


