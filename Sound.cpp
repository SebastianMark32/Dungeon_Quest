#include "Sound.h"

Sound::Sound() {

}

Sound::Sound(std::string path){
    this->soundBuffer.loadFromFile(path);
    this->sound.setBuffer(soundBuffer);
}
sf::Sound Sound::getSound() {
    return this->sound;
}
void Sound::setSound(std::string path){
    this->soundBuffer.loadFromFile(path);
    this->sound.setBuffer(soundBuffer);
}
void Sound::play(){
    this->sound.play();
}