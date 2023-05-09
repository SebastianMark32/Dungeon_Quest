#ifndef DUNGEON_QUEST_SOUND_H
#include <string>
#include <SFML/Audio.hpp>
#define DUNGEON_QUEST_SOUND_H

class Sound {
public:
    Sound();

    Sound(std::string path);

    sf::Sound getSound();

    void setSound(std::string path);

    void play();
private:
    sf::Sound sound;
    sf::SoundBuffer soundBuffer;
};
#endif //DUNGEON_QUEST_SOUND_H
