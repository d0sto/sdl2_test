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

    struct sprite_movement sBob { bob };
    move_me.push_back(sBob);
    hero = &move_me.at(0);
}


CMain::~CMain(void)
{
}

void CMain::manage_keys(SDL_Event* event)
{
    switch (event->type)
    {

    case SDL_QUIT:
        std::cout << "Received quit event. Exiting..." << std::endl;
        quit = true;
        break;

    case SDL_KEYDOWN:
        switch (event->key.keysym.sym)
        {
            case SDLK_w:
                std::cout << "w pressed" << std::endl;
                hero->sprite->set_add_y(-move_y);
                hero->sprite->setAtmAnimate(true);
                break;

            case SDLK_a:
                std::cout << "a pressed" << std::endl;
                hero->sprite->set_add_x(-move_x);
                hero->sprite->setAtmAnimate(true);
                hero->sprite->set_animation_mode(1);
                break;

            case SDLK_s:
                std::cout << "s pressed" << std::endl;
                hero->sprite->set_add_y(move_y);
                hero->sprite->setAtmAnimate(true);
                break;

            case SDLK_d:
                std::cout << "d pressed" << std::endl;
                hero->sprite->set_add_x(move_x);
                hero->sprite->setAtmAnimate(true);
                hero->sprite->set_animation_mode(0);
                break;

            case SDLK_LSHIFT:
                move_x = 2;
                move_y = 2;
                break;

            default:
                break;

        }
        break;

    case SDL_KEYUP:
        switch (event->key.keysym.sym)
        {
            case SDLK_w:
                std::cout << "w released" << std::endl;
                hero->sprite->set_add_y(0);
                hero->sprite->setAtmAnimate(false);
                break;

            case SDLK_a:
                std::cout << "a released" << std::endl;
                hero->sprite->set_add_x(0);
                hero->sprite->setAtmAnimate(false);
                break;

            case SDLK_s:
                std::cout << "s released" << std::endl;
                hero->sprite->set_add_y(0);
                hero->sprite->setAtmAnimate(false);
                break;

            case SDLK_d:
                std::cout << "d released" << std::endl;
                hero->sprite->set_add_x(0);
                hero->sprite->setAtmAnimate(false);
                break;

            case SDLK_LSHIFT:
                move_x = 5;
                move_y = 5;
                break;

            default:
                break;
        }
        break;

    case SDL_WINDOWEVENT:
        switch(event->window.event)
        {
            std::cout << "Window size changed" << std::endl;
            case SDL_WINDOWEVENT_SIZE_CHANGED:
                SDL_GetWindowSize(sdl_setup->GetWindow(), &ScreenWidth, &ScreenHeight);
                break;

            default:
                break;
        }

    default:
        break;
    }
}

void CMain::GameLoop(void)
{
    SDL_Event* temp_event {sdl_setup->GetMainEvent()};

	while (!quit && temp_event->type != SDL_QUIT)
	{
        fpscap.newFrame();

		sdl_setup->Begin();

        while(sdl_setup->poll_event())
            manage_keys(temp_event);

        SDL_RenderCopy(sdl_setup->GetRenderer(), grass->get_texture(), NULL, NULL);
        bob->handle_motion();
		bob->draw();

		sdl_setup->End();


        fpscap.calcCorrectFps();
        fpscap.frameEarly();
	}
}