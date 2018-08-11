#pragma once
#include "CSprite.hpp"
#include "Timer.hpp"
#include <SDL2/SDL.h>
#include <iostream>

class ASprite : public CSprite {

public:
	ASprite(SDL_Renderer* passed_renderer, std::string file_path, SDL_Rect src, SDL_Rect dest,
            int max_animation_count, int max_animation_ticks, 
            int &screenWidth, int &screenHeight);

    bool do_animate();
    void update_animation();
    void set_animation_mode(int mode);
    void handle_motion();

    void setAtmAnimate(bool animate);
    bool getAtmAnimate();

private:
    bool atm_animate;

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
