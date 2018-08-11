#pragma once
#include <map>
#include <list>

#include "SDL_Setup.hpp"

#include "CSprite.hpp"
#include "ASprite.hpp"
#include "BSprite.hpp"

#include "FPSCap.hpp"

class CMain
{
public:
	CMain(int passed_ScreenWidth, int passed_ScreenHeight);
	~CMain(void);
	void GameLoop();

private:
	int ScreenWidth;
	int ScreenHeight;

	bool quit;

    FpsCap fpscap;
	
	BSprite* grass;
	CSprite* bob;

	SDL_Setup* sdl_setup;

    // Get function pointers when passing SDL_Event.type
    // Replacement for the big switch block
    std::map< Uint32, std::list<void*> > event_functions;

    int move_x;
    int move_y;

    struct sprite_movement
    {
        CSprite* sprite;
    };
    std::vector<sprite_movement> move_me;
    struct sprite_movement* hero;
    void move_all();

    void manage_keys(SDL_Event* event);
};
