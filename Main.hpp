#ifndef MAIN_HPP
#define MAIN_HPP

#include <map>
#include <list>

#include "SDL_Setup.hpp"

#include "ASprite.hpp"
#include "CSprite.hpp"
#include "BSprite.hpp"
#include "ObjectState.hpp"

#include "FPSCap.hpp"

class CMain
{
public:
	CMain(int passed_ScreenWidth, int passed_ScreenHeight);
	~CMain(void);

	void GameLoop();
    void add_to_event_functions(Uint32 k, void* f);
    void remove_from_event_functions(Uint32 k, void* f);

private:
    ObjectState stateMachine;

	int ScreenWidth;
	int ScreenHeight;

	bool quit;

    FpsCap fpscap;
	
	BSprite* grass;
	CSprite* bob;

	SDL_Setup* sdl_setup;
};

#endif
