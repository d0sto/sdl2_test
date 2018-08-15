#ifndef ASPRITE_HPP
#define ASPRITE_HPP

#include <SDL2/SDL.h>
#include <iostream>

#include "CSprite.hpp"
#include "Timer.hpp"


class ASprite : public CSprite {

public:
	ASprite(SDL_Renderer* passed_renderer, std::string file_path, SDL_Rect src, SDL_Rect dest,
            int max_animation_count, int max_animation_ticks, 
            int &screenWidth, int &screenHeight);

    void updateState();

    void handle_motion();
    void update_animation();
    bool do_animate();

    void set_animation_mode(int mode);

    void setAtmAnimate(bool animate);
    bool getAtmAnimate();

private:
    bool atm_animate; ///< Used to disable animation handling, e.g. if handle_motion is called from loop

    int &screenHeight;
    int &screenWidth;

    int max_animation_count;
    int max_animation_ticks;
    int current_animation_count;
    int new_max_animation_ticks;
    int animation_mode;

    void set_max_animation_ticks(int ticks);
    int get_max_animation_ticks();
    void set_animation_src();


    Timer timer;
};
#endif
