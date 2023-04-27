#include "Enemy.h"

Enemy::Enemy(std::string path) {
    this->texture.loadFromFile(path);
    this->sprite.setTexture(texture);
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

int getDamage(int damage){
    return damage;
}

// Nate's code for random enemy movement
void Enemy::randomEnemyMove(int number){
    number = number % 4;

    if ((number == 0) & (sprite.getPosition().y > 242)){
        sprite.move(0.0f, -121.0f);
    }
    if ((number == 1) & (sprite.getPosition().x > 242)){
        sprite.move(-121, 0.0f);
    }
    if ((number == 2) & (sprite.getPosition().y < 726)){
        sprite.move(0.0f, 121.0f);
    }
    if ((number == 3) & (sprite.getPosition().x < 1573)) {
        sprite.move(121, 0.0f);
    }
}

//A random respawn method in case an enemy object "dies"
void Enemy::respawn(int number){
    number = number % 3;
    switch (number){
        case 0:
            sprite.setPosition(968.f, 484.f);
            break;
        case 1:
            sprite.setPosition(968.f, 484.f);
            break;
        case 2:
            sprite.setPosition(968.f, 484.f);
            break;
        case 3:
            sprite.setPosition(968.f, 484.f);
            break;
        default:
            break;
    }
}
