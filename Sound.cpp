#include "Sound.h"

Sound::Sound(std::string path){
    this->soundBuffer.loadFromFile(path);
    this->sound.setBuffer(soundBuffer);
}

sf::Sound Sound::getSound() {
    return this->sound;
}

void Sound::Play(){
    this->sound.play();
}