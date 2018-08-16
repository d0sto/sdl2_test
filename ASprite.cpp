#include "ASprite.hpp"

ASprite::ASprite(CSprite *cs)
    : cs{cs}, screenHeight{0}, screenWidth{0}, ani{nullptr}
{
}

ASprite::ASprite(CSprite *cs, SDL_Rect* src, int screenHeight,
                 int screenWidth, bool currentlyAnimating,
                 int maxAnimationDuration, int maxAnimationImg) 
    : cs{cs}, screenHeight{screenHeight}, screenWidth{screenWidth}
{
    ani = new Animation(src, currentlyAnimating, maxAnimationDuration,
                                maxAnimationImg);
    std::cout << ani << "Was the pointer " <<std::endl;
}

void ASprite::handleMovement()
{
    /* \brief Makes sure object does not move out of the window
     */

    std::cout << "Y : " << cs->get_dest()->y << "\n";
    std::cout << "X : " << cs->get_dest()->x << std::endl;
    
    if(cs->get_dest()->y > screenHeight)
        cs->set_dest_y(0);
    else if(cs->get_dest()->y < 0)
        cs->set_dest_y(screenHeight);

    if(cs->get_dest()->x > screenWidth)
        cs->set_dest_x(0);
    else if(cs->get_dest()->x < 0)
        cs->set_dest_x(screenWidth);

    cs->apply_add_x_y();
}

CSprite* ASprite::getCs() { return cs; }
Animation* ASprite::getAni() { return ani; }
