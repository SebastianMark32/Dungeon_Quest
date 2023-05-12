#include "Music.h"

Music::Music(std::string path){
    this->music.openFromFile(path);
    this->music.play();
    this->music.setLoop(true);
}
void Music::play(){
    this->music.play();
}

void Music::pause(){
    this->music.pause();
}
void Music::changeMusic(std::string path) {
    this->music.stop();
    this->music.openFromFile(path);
    this->music.play();
}
void Music::setVolume(float volume){
    this->music.setVolume(volume);
}
