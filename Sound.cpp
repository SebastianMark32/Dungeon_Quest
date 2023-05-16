#include "Sound.h"

//constructors
Sound::Sound() {

}
Sound::Sound(std::string path){
    this->soundBuffer.loadFromFile(path);
    this->sound.setBuffer(soundBuffer);
}
//returns the sf::sound object to handle direct function calls
sf::Sound Sound::getSound() {
    return this->sound;
}
//allows the sound to change
void Sound::setSound(std::string path){
    this->soundBuffer.loadFromFile(path);
    this->sound.setBuffer(soundBuffer);
}
//plays the sound
void Sound::play(){
    this->sound.play();
}