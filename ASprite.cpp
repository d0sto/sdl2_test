#include "ASprite.hpp"

ASprite::ASprite(SDL_Renderer* passed_renderer, std::string file_path, SDL_Rect src, SDL_Rect dest,
        int max_animation_count, int max_animation_ticks,
        int &screenWidth, int &screenHeight)
        : CSprite(passed_renderer, file_path, src, dest), screenHeight{screenHeight}, screenWidth{screenWidth},
        max_animation_count{max_animation_count},
        max_animation_ticks{max_animation_ticks}, current_animation_count{0}, 
        animation_mode{0}, timer{Timer()}

{
}


void ASprite::update_animation()
{
    if(!timer.isStarted())
        timer.start();
    if(timer.isPaused())
        timer.unpause();

    if(current_animation_count > max_animation_count)
        current_animation_count = 0;

    if(timer.getTicks() > new_max_animation_ticks)
    {
        timer.stop();
        set_animation_src();
        current_animation_count++;
        new_max_animation_ticks = timer.getTicks() + max_animation_ticks;
    }
    timer.pause();
}

void ASprite::set_animation_src()
{
    //std::cout << "animation count " << current_animation_count << std::endl;
    src.x = current_animation_count * src.w;
    src.y = src.h * animation_mode;
}

void ASprite::handle_motion()
{
    
    if(dest.y > screenHeight)
        set_dest_y(0);
    else if(dest.y < 0)
        set_dest_y(screenHeight);

    if(dest.x > screenWidth)
        set_dest_x(0);
    else if(dest.x < 0)
        set_dest_x(screenWidth);

    apply_add_x_y();
    if(atm_animate)
        update_animation();
}


void ASprite::set_animation_mode(int mode) { if (animation_mode != mode) { animation_mode = mode; } }
void ASprite::set_max_animation_ticks(int ticks) { max_animation_ticks = ticks; }
int ASprite::get_max_animation_ticks() { return max_animation_ticks; }
bool ASprite::do_animate() { return true; }

void ASprite::setAtmAnimate(bool atm_animate) { this->atm_animate = atm_animate; }
bool ASprite::getAtmAnimate() { return atm_animate; }
