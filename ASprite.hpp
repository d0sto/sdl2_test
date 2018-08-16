#ifndef ASPRITE_HPP
#define ASPRITE_HPP

#include "CSprite.hpp"
#include "Animation.hpp"

class ASprite {
    public:
        ASprite(CSprite *cs);
        ASprite(CSprite *cs, SDL_Rect*, int screenHeight,
                int screenWidth, bool currentlyAnimating, int maxAnimationDuration,
                int maxAnimationImg);

        void handleMovement();

        Animation* getAni();
        CSprite* getCs();

    private:
        int screenHeight;
        int screenWidth;

        Animation *ani;
        CSprite *cs;
};

#endif
