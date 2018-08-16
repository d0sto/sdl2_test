#include "Animation.hpp"

Animation::Animation(SDL_Rect* src, bool currentlyAnimating,
         int maxAnimationDuration, int maxAnimationImg) 
    : src{src}, currentlyAnimating{currentlyAnimating},
      maxAnimationDuration{maxAnimationDuration}, maxAnimationImg{maxAnimationImg},
      // Initialize rest to 0
      currentAnimationImg{0}, imgPos{0}, newMaxAnimationDuration{0},
      timer{Timer()}
{
}

void Animation::updateAnimation() {
    /* \brief Makes sure src matches new animation frame after max_animation_delay
     *  Delay between frames is max_animation_ticks
     *
     * Uses Timer instance to track delay between each animated frame.
     */
    if(!timer.isStarted())
        timer.start();
    if(timer.isPaused())
        timer.unpause();

    if(currentAnimationImg > maxAnimationImg)
        currentAnimationImg = 0;

    if(timer.getTicks() > newMaxAnimationDuration)
    {
        timer.stop();
        setAnimationSrc();
        currentAnimationImg++;
        newMaxAnimationDuration = timer.getTicks() + maxAnimationDuration; 
    }
    timer.pause();
}

void Animation::setAnimationSrc() {
    /* \brief Update src to point to next frame 
     */
    src->x = currentAnimationImg * src->w;
    src->y = src->h * imgPos;
}

//====================== Getters and Setter

bool Animation::getCurrentlyAnimating() { return currentlyAnimating; }
void Animation::setCurrentlyAnimating(bool animate) { this->currentlyAnimating = animate; }

int Animation::getMaxAnimationImg() { return maxAnimationImg; }
void Animation::setMaxAnimationImg(int images) { maxAnimationImg = images; }
int Animation::getImgPos() { return imgPos; }
void Animation::setImgPos(int new_pos) { imgPos = new_pos; }
