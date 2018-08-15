#include "stdafx.hpp"
#include "Main.hpp"

CMain::CMain(int passed_ScreenWidth, int passed_ScreenHeight)
{
	ScreenWidth = passed_ScreenWidth;
	ScreenHeight = passed_ScreenHeight;
	quit = false;

    move_x = 5;
    move_y = 5;

    fpscap = FpsCap();
    fpscap.start();

	sdl_setup = new SDL_Setup(&quit, ScreenWidth, ScreenHeight);

    grass = new BSprite(ScreenWidth, ScreenHeight, "assets/primitive_tiles.png",
                SDL_Rect {20, 20, 10, 10}, SDL_Rect {0, 0, 50, 50},
                sdl_setup->GetWindowSurface(), sdl_setup->GetRenderer());

    //150 is good max_animation_ticks
    bob = new ASprite(sdl_setup->GetRenderer(),"assets/sheet_hero_walk_f.png",
        SDL_Rect {0, 0, 27, 31}, SDL_Rect {0, 0, 36, 41}, 2, 50,
        ScreenWidth, ScreenHeight);

    stateMachine = ASpriteState(std::list<CSprite*> { bob });
}


CMain::~CMain(void)
{
}

void CMain::GameLoop(void)
{
    SDL_Event* temp_event {sdl_setup->GetMainEvent()};

	while (!quit && temp_event->type != SDL_QUIT)
	{
        fpscap.newFrame();

		sdl_setup->Begin();

        while(sdl_setup->poll_event()) {
            stateMachine.handleInput(temp_event);
            stateMachine.runState(); 
        }

        SDL_RenderCopy(sdl_setup->GetRenderer(), grass->get_texture(), NULL, NULL);
        bob->handle_motion();
		bob->draw();

		sdl_setup->End();

        fpscap.calcCorrectFps();
        fpscap.frameEarly();
        std::cout << fpscap.getAvgFPS() << std::endl;
	}
}
