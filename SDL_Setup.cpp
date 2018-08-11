#include "SDL_Setup.hpp"


SDL_Setup::SDL_Setup(bool* quit, int ScreenWidth, int ScreenHeight)
{
	window = NULL;
	window = SDL_CreateWindow("This is a test", ScreenWidth, ScreenHeight, ScreenWidth,
             ScreenHeight, SDL_WINDOW_RESIZABLE);

	if (window == NULL)
	{
		std::cout << "Window couldn't be created" << std::endl;
		*quit = true;
	}

    std::cout << "IMG_INIT: " << IMG_Init(IMG_INIT_PNG) << std::endl;

	renderer = NULL;
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	mainEvent = new SDL_Event();

    window_surface = SDL_GetWindowSurface(window);
    if(window_surface == nullptr)
        std::cout<< "Window surface could not be created" << std::endl;
}


SDL_Setup::~SDL_Setup(void)
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	delete mainEvent;
}

SDL_Renderer* SDL_Setup::GetRenderer()
{
	return renderer;
}

SDL_Event* SDL_Setup::GetMainEvent()
{
	return mainEvent;
}

SDL_Window* SDL_Setup::GetWindow() { return window; }
SDL_Surface* SDL_Setup::GetWindowSurface() { return window_surface; }
int SDL_Setup::poll_event() { return SDL_PollEvent(mainEvent); }

void SDL_Setup::Begin()
{
	SDL_RenderClear(renderer);
}

void SDL_Setup::End()
{
	SDL_RenderPresent(renderer);
}
