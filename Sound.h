#ifndef DUNGEON_QUEST_SOUND_H
#include <string>
#include <SFML/Audio.hpp>
#define DUNGEON_QUEST_SOUND_H

class Sound {
public:
    //constructors
    Sound();

    Sound(std::string path);


    //get the sound
    sf::Sound getSound();
    //change the sound
    void setSound(std::string path);
    //play the sound
    void play();
private:
    sf::Sound sound;
    sf::SoundBuffer soundBuffer;
};
#endif //DUNGEON_QUEST_SOUND_H
