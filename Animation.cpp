// Code from SFML Animation Tutorial
// https://github.com/SFML/SFML/wiki/Easy-Animations-With-Spritesheets

#include "Animation.h"

Animation::Animation(sf::Sprite &target) : target(target) {
    progress = totalLength = 0.0;
}

void Animation::addFrame(Frame&& frame) {
    totalLength += frame.duration;
    frames.push_back(std::move(frame));
}
void Animation::update(double elapsed) {
    progress += elapsed;
    double p = progress;
    for(size_t i = 0; i < frames.size(); i++) {
        p -= frames[i].duration;

        // We check if p has some time left at the end of the animation...
        if (p > 0.0 && &(frames[i]) == &(frames.back())) {
            i = 0;    // start over from the beginning
            continue; // break off the loop and start where i is
        }

        // if we have progressed OR if we're on the last frame, apply and stop.
        if (p <= 0.0 || &(frames[i]) == &frames.back()){
            target.setTextureRect(frames[i].rect);
            break; // we found our frame
        }
    }
}




