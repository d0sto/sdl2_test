#include "ASpriteState.hpp"

ASpriteState::ASpriteState(std::list<CSprite*> spriteList)
    : spriteList{spriteList}
{
}

void ASpriteState::addToSpriteList(CSprite* as) {
    spriteList.push_back(as);
}

void ASpriteState::removeFromSpriteList(CSprite* as) {
    /* \brief Removes as from spriteList 
     *  This takes advantage of the std::find function found in <algorithm>
     * */
    spriteList.erase(std::find(spriteList.begin(), spriteList.end(), as));
}

void ASpriteState::handleInput(SDL_Event* e) {
    /* \brief Sets state according to input achieved from e
     */
    switch(e->type) {
        case SDL_KEYDOWN:
            switch(e->key.keysym.sym) {
                case SDLK_w:
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

void ASpriteState::runState() {
    /* \brief Applies activeState to all elements in spriteList
     */
    for(auto as: spriteList) {
        switch (activeState) {

            //Moving states
            case VEL_UP:
                as->set_add_y(-5);
                as->setAtmAnimate(true);
                break;

            case VEL_DOWN:
                as->set_add_y(5);
                as->setAtmAnimate(true);
                break;

            case VEL_LEFT:
                as->set_add_x(-5);
                as->setAtmAnimate(true);
                as->set_animation_mode(1);
                break;

            case VEL_RIGHT:
                as->set_add_x(5);
                as->setAtmAnimate(true);
                as->set_animation_mode(0);
                break;

            // STILL_STATES
            case STILL_UP:
            case STILL_DOWN:
                as->set_add_y(0);
                as->setAtmAnimate(false);
                break;

            case STILL_LEFT:
            case STILL_RIGHT:
                as->set_add_x(0);
                as->setAtmAnimate(false);
                break;
        }
    }
}
