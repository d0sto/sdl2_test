#pragma once

#include "stdafx.hpp"

class SDL_Setup
{
public:
	SDL_Setup(bool* quit, int ScreenWidth, int ScreenHeight);
	~SDL_Setup(void);

	SDL_Renderer* GetRenderer();
	SDL_Event* GetMainEvent();
    SDL_Window* GetWindow();
    SDL_Surface* GetWindowSurface();

    int poll_event();

	void Begin();
	void End();
private:
	
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Event* mainEvent;

    SDL_Surface* window_surface;
};
