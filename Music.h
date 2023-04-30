#ifndef DUNGEON_QUEST_MUSIC_H
#include <string>
#include <SFML/Audio.hpp>
#define DUNGEON_QUEST_MUSIC_H

class Music {
public:
    Music(std::string path);

    void play();

    void pause();

    void changeMusic(std::string path);

    void setVolume(float volume);
private:
    sf::Music music;
};
#endif //DUNGEON_QUEST_MUSIC_H
