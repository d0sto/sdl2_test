#include "FPSCap.hpp"

FpsCap::FpsCap()
	: fpsTimer{Timer()}, capTimer{Timer()}, countedFrames{0}, avgFPS{0} {}

void FpsCap::start()
{
	fpsTimer.start();
}

void FpsCap::newFrame()
{
	capTimer.start();
}

void FpsCap::calcCorrectFps()
{
	avgFPS = countedFrames / (fpsTimer.getTicks() / 1000.f);
	if(avgFPS > 2000000)
		avgFPS = 0;
}

void FpsCap::frameEarly()
{
	countedFrames++;

	/* If frame finished early */
	int frameTicks = capTimer.getTicks();
	if(frameTicks < SCREEN_TICKS_PER_FRAME)
		SDL_Delay(SCREEN_TICKS_PER_FRAME - frameTicks);
}

int FpsCap::getAvgFPS()
{
    return avgFPS;
}
