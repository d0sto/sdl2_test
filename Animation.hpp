#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include "stdafx.hpp"

#include <algorithm>
#include "Timer.hpp"
#include <map>

class Animation {

  public:
    Animation(SDL_Rect* src, bool currentlyAnimating = false,
            int maxAnimationDuration = 100, int maxAnimationImg = 0);

    void updateAnimation();
    void setAnimationSrc();

    //====================== Getters and Setter
    bool getCurrentlyAnimating();
    void setCurrentlyAnimating(bool animate);

    int getMaxAnimationImg();
    void setMaxAnimationImg(int images);
    int getImgPos();
    void setImgPos(int new_pos);

    SDL_Rect* getSrc();

  private:
    Timer timer;

    bool currentlyAnimating;

    int maxAnimationImg;
    int currentAnimationImg;
    int imgPos;
    SDL_Rect* src;

    int maxAnimationDuration;
    int newMaxAnimationDuration;
};

#endif
