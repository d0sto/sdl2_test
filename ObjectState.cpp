#include "ObjectState.hpp"

ObjectState::ObjectState()
{
}

ObjectState::ObjectState(std::list<ASprite*> asl)

{
    for(auto as: asl) {
        addToSpriteList(as);
    }
}

void ObjectState::addToSpriteList(ASprite* as) {
    spriteList.push_back(as);
}

void ObjectState::removeFromSpriteList(ASprite *as) {
    /* \brief Removes cs from spriteList 
     *  This takes advantage of the std::find function found in <algorithm>
     * */
    std::list<ASprite*>::iterator it;
    it = std::find(spriteList.begin(), spriteList.end(), as);

    if(it != spriteList.end()) {
        spriteList.erase(it);
    }
}

void ObjectState::handleInput(SDL_Event* e) {
    /* \brief Sets state according to input achieved from e
     */
    switch(e->type) {
        case SDL_KEYDOWN:
            switch(e->key.keysym.sym) {
                case SDLK_w:
                    std::cout << "Setting state to VEL_UP" << std::endl;
                    activeState = VEL_UP;
                    break;

                case SDLK_s:
                    activeState = VEL_DOWN;
                    break;

                case SDLK_a:
                    activeState = VEL_LEFT;
                    break;

                case SDLK_d:
                    activeState = VEL_RIGHT;
                    break;
            }
            break;

        case SDL_KEYUP:
            switch(e->key.keysym.sym) {
                case SDLK_w:
                    activeState = STILL_UP;
                    break;

                case SDLK_s:
                    activeState = STILL_DOWN;
                    break;

                case SDLK_a:
                    activeState = STILL_LEFT;
                    break;

                case SDLK_d:
                    activeState = STILL_RIGHT;
                    break;
            }
            break;
    }
}

void ObjectState::runState() {
    /* \brief Applies activeState to all elements in spriteList
     */
    for(auto as: spriteList) {
        std::cout << "In for" << std::endl;
        switch (activeState) {

            //Moving states
            case VEL_UP:
                std::cout << "State: VEL_UP" << std::endl;
                as->getCs()->set_add_y(-5);
                as->getAni()->setCurrentlyAnimating(true);
                break;

            case VEL_DOWN:
                as->getCs()->set_add_y(5);
                as->getAni()->setCurrentlyAnimating(true);
                break;

            case VEL_LEFT:
                as->getCs()->set_add_x(-5);
                as->getAni()->setCurrentlyAnimating(true);
                as->getAni()->setImgPos(1);
                break;

            case VEL_RIGHT:
                as->getCs()->set_add_x(5);
                as->getAni()->setCurrentlyAnimating(true);
                as->getAni()->setImgPos(0);
                break;

            // STILL_STATES
            case STILL_UP:
            case STILL_DOWN:
                as->getCs()->set_add_y(0);
                as->getAni()->setCurrentlyAnimating(false);
                break;

            case STILL_LEFT:
            case STILL_RIGHT:
                as->getCs()->set_add_x(0);
                as->getAni()->setCurrentlyAnimating(false);
                break;

            case NOTHING:
                break;
        }
    as->handleMovement();
    }
}
