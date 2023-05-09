// Created by Cyborg on 4/27/23.

#ifndef DUNGEON_QUEST_ANIMATION_H
#define DUNGEON_QUEST_ANIMATION_H
#include <SFML/Graphics.hpp>

struct Frame {
    sf::IntRect rect;
    double duration; // in seconds
};

class Animation {
public:
    Animation();

    Animation(sf::Sprite &target);

    void setSpriteTarget();

    void addFrame(Frame&& frame);

    void update(double elapsed);

    const double getLength() const { return totalLength;
    }
private:
    std::vector<Frame> frames;
    double totalLength;
    double progress;
    sf::Sprite &target;
    sf::Sprite dummySprite;
};
#endif //DUNGEON_QUEST_ANIMATION_H
