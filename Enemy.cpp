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
sf::Sprite Enemy::getSprite() {
    return this->sprite;
}
void Enemy::randomEnemyMove(int number){
    number = number % 4;

    if ((number == 0) & (sprite.getPosition().y > 0)){
        sprite.move(0.0f, -121.0f);
    }
    if ((number == 1) & (sprite.getPosition().x > 8)){
        sprite.move(-133, 0.0f);
    }
    if ((number == 2) & (sprite.getPosition().y < 484)){
        sprite.move(0.0f, 121.0f);
    }
    if ((number == 3) & (sprite.getPosition().x < 673)) {
        sprite.move(133, 0.0f);
    }
}
