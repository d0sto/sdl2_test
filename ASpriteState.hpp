#ifndef ASPRITE_STATE_HPP
#define ASPRITE_STATE_HPP

#include "ASprite.hpp"
#include "StateMachine.hpp"

class ASpriteState : public ASprite, StateMachine {
    public:
        void handleInput(SDL_Event* e);

        //bool isComplete();

        void runState();
};

#endif
