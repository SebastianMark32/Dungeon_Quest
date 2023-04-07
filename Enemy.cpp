#include "Enemy.h"
#include <string>

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
sf::Sprite Enemy::getSprite() {
    return this->sprite;
}

