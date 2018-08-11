#pragma once

/* This argument creates a SDL_Surface and a SDL_Texture from the arguments given.extern
 * You can use these as a static background */

#include "stdafx.hpp"

class BSprite
{
    public:
    BSprite(int width, int height, std::string file_path, SDL_Rect src, SDL_Rect dest, SDL_Surface* surface, SDL_Renderer* renderer);

    SDL_Surface* get_surface();
    SDL_Texture* get_texture();

    private:
    void do_tile_fill(int until_x, int until_y);

    int width;
    int height;
    SDL_Rect src;
    SDL_Rect dest;
    std::string file_path;

    SDL_Surface* image;
    SDL_Surface* surface;
    SDL_Texture* texture;
};
