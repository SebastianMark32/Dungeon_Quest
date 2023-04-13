
#include "Rocket.h"

Rocket::Rocket(){}
Rocket::~Rocket(){}

void Rocket::init(std::string textureName, sf::Vector2f position, float _speed){
   m_speed = _speed;
}