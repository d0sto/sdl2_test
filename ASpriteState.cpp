#include "ASpriteState.hpp"

void ASpriteState::handleInput(SDL_Event* e) {
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
    switch (activeState) {
        case VEL_UP:
            set_add_y(5);
            break;

        case VEL_DOWN:
            set_add_y(-5);
            break;

        case VEL_LEFT:
            set_add_x(-5);
            break;

        case VEL_RIGHT:
            set_add_x(5);
            break;

        // STILL_STATES
        case STILL_UP:
        case STILL_DOWN:
            set_add_y(0);
            break;

        case STILL_LEFT:
        case STILL_RIGHT:
            set_add_x(0);
            break;

    }
}
