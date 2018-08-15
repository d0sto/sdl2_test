#ifndef ASPRITE_STATE_HPP
#define ASPRITE_STATE_HPP

#include "CSprite.hpp"
#include "StateMachine.hpp"

//< For std::find
#include <algorithm>
#include <list>

class ASpriteState : StateMachine {
    public:
        //< Default parameter is neccessary in order for this thing to be the default constructor
        ASpriteState(std::list<CSprite*> spriteList =  std::list<CSprite*> {nullptr});

        void handleInput(SDL_Event* e);

        //bool isComplete();

        void runState();

        void addToSpriteList(CSprite *as);
        void removeFromSpriteList(CSprite *as);

    private:
        std::list<CSprite*> spriteList;
};

#endif
