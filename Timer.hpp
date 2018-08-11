#pragma once
#include <SDL2/SDL.h>
class Timer
{
public:
	/* Initalize variables */
	Timer();
	
	/* Basic actions */
	void start();
	void stop();
	void pause();
	void unpause();

	/* Get timer's time */
	unsigned long int getTicks();

	/* Get status of timer */
	bool isStarted();
	bool isPaused();

private:
	/* The clock time when timer was started */
	unsigned long int mStartTicks;

	/* The ticks stored when the timer was paused */
	unsigned long int mPausedTicks;

	/* The timer status */
	bool mPaused;
	bool mStarted;
};
