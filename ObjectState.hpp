#ifndef OBJECT_STATE_HPP
#define OBJECT_STATE_HPP

#include "ASprite.hpp"
#include "CSprite.hpp"
#include "StateMachine.hpp"
#include "Animation.hpp"

#include <algorithm> ///< For std::find
#include <memory> ///< For unique_ptr
#include <list>

class ObjectState : StateMachine {
    public:
        ///< Default parameter is neccessary in order for this thing to be the default constructor
        ObjectState();
        ObjectState(std::list<ASprite*> asl);

        void handleInput(SDL_Event* e);

        //bool isComplete();

        void runState();

        void addToSpriteList(ASprite* as);
        void removeFromSpriteList(ASprite *as);

    private:
        std::list<ASprite*> spriteList;
};

#endif
