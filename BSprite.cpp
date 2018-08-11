#include "BSprite.hpp"

BSprite::BSprite(int width, int height, std::string file_path,
        SDL_Rect src, SDL_Rect dest, SDL_Surface* surface, SDL_Renderer* renderer)
    : width{width}, height{height}, src{src}, dest{dest}, file_path{file_path},
      surface{surface}
{
    image = IMG_Load(file_path.c_str());
    if(image == nullptr)
        std::cout << "Could not load image " << file_path << std::endl;

    do_tile_fill(width, height);
    texture = SDL_CreateTextureFromSurface(renderer, surface);
}


void BSprite::do_tile_fill(int until_x, int until_y)
{
    for(int x = 0; x < until_x; x++)
    {
        for(int y = 0; y < until_y; y++)
        {
            SDL_Rect temp_dest { x*dest.w, y*dest.h, dest.w, dest.h};
            SDL_BlitScaled(image, &src, surface, &temp_dest);
        }
    }
}

SDL_Surface* BSprite::get_surface() { return surface; }
SDL_Texture* BSprite::get_texture() { return texture; }
