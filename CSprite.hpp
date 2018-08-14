#pragma once
#include "Timer.hpp"
#include <string>
#include <iostream>

class CSprite
{
public:
	CSprite(SDL_Renderer* passed_renderer, std::string file_path, SDL_Rect src, SDL_Rect dest);
	~CSprite(void);

	void draw();
    
    void set_dest_x(int x);
    void set_dest_y(int y);
    void set_dest_x_y(int x, int y);

    void add_dest_x(int x);
    void add_dest_y(int y);
    void add_dest_x_y(int x, int y);

    void set_add_x(int x);
    void set_add_y(int y);
    void set_add_x_y(int x, int y);

    void apply_add_x_y();
    void apply_add_x();
    void apply_add_y();

    virtual void w();
    virtual void a();
    virtual void s();
    virtual void d();

    SDL_Renderer* get_renderer();

    virtual bool do_animate();
    virtual void set_animation_mode(int);

    SDL_Rect* get_dest();
    int get_x();
    int get_y();

    void do_tile_fill(int until_x, int until_y);

    virtual void update_animation();

    virtual void handle_motion();
    virtual void setAtmAnimate(bool);
    virtual bool getAtmAnimate();

protected:
    //These are for adding velocity to the object and can be applied using the add_add functions
    //The real postition is in "dest"
    int x;
    int y;

	SDL_Renderer* renderer;

    std::string file_path;

	SDL_Texture* image;
	SDL_Rect src;
    SDL_Rect dest;
};
