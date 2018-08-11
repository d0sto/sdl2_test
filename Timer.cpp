#include "stdafx.hpp"
#include "Timer.hpp"

Timer::Timer()
	: mStartTicks{0}, mPausedTicks{0}, mPaused{false}, mStarted{false} {}

void Timer::start()
{
	mStarted = true;
	mPaused = false;

	mStartTicks = SDL_GetTicks();
	mPausedTicks = 0;
}

void Timer::stop()
{
    //std::cout << "timer stopped" << std::endl;
	if(mStarted && !mPaused)
	{
		mPaused = false;
        mStarted = false;

		mPausedTicks = SDL_GetTicks() - mStartTicks;
		mStartTicks = 0;
	}
}

void Timer::unpause()
{
	if(mStarted && mPaused)
	{
		mPaused = false;

		mStartTicks = SDL_GetTicks() - mPausedTicks;
		mPausedTicks = 0;
	}
}

void Timer::pause()
{
    if(mStarted && !mPaused)
    {
        mPausedTicks = SDL_GetTicks();
        mPaused = true;
        //std::cout << "Timer paused" << std::endl;
    }
}


unsigned long int Timer::getTicks()
{
	if(mStarted)
	{
		if(mPaused)
			return mPausedTicks;
		else
			return SDL_GetTicks() - mStartTicks;
	}
    return SDL_GetTicks();
}

bool Timer::isStarted()
{
	return mStarted;
}

bool Timer::isPaused()
{
	return mPaused && mStarted;
}
