#ifndef FPSCAP
#define FPSCAP

#include <SDL2/SDL.h>
#include "Timer.hpp"

class FpsCap {
    private:

    int SCREEN_FPS = 60;
    int SCREEN_TICKS_PER_FRAME = 1000 / SCREEN_FPS;
	Timer fpsTimer;
	Timer capTimer;

	int countedFrames;
	float avgFPS;
	
	public:

	FpsCap();
	void start();
	void newFrame();
	void calcCorrectFps();
	void frameEarly();
	int getAvgFPS();
};

#endif
