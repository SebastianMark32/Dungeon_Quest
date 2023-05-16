#include "Music.h"
//constructor
Music::Music(std::string path){
    this->music.openFromFile(path);
    this->music.play();
    this->music.setLoop(true);
}
//play the music
void Music::play(){
    this->music.play();
}
//pause the music
void Music::pause(){
    this->music.pause();
}
//change the music
void Music::changeMusic(std::string path) {
    this->music.stop();
    this->music.openFromFile(path);
    this->music.play();
}
//change music volume
void Music::setVolume(float volume){
    this->music.setVolume(volume);
}
