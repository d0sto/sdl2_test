#include "stdafx.hpp"
#include "CSprite.hpp"

CSprite::CSprite(SDL_Renderer* passed_renderer, std::string file_path, SDL_Rect src, SDL_Rect dest)
    : renderer{passed_renderer}, file_path{file_path}, src{src}, dest{dest}
{
    /** Texture for image will be created in the constructor
     */
    image = IMG_LoadTexture(renderer, file_path.c_str());
	if (image == NULL)
		std::cout << "Couldn't load image " << file_path.c_str() << std::endl;
}


CSprite::~CSprite(void)
{ 
    /** Take care of memory leaks
     */
    SDL_DestroyTexture(image); 
}

void CSprite::draw()
{ 
    /** Draw image to renderer + call handle_motion
     */
    SDL_RenderCopy(renderer, image, &src, &dest); handle_motion(); 
}

void CSprite::do_tile_fill(int until_x, int until_y)
{
    /** Fills whole renderer (limits are until_x, until_y)
     * with image. Useful for static backgrounds.
     */
    for(int x = 0; x < until_x; x++)
    {
        for(int y = 0; y < until_y; y++)
        {
            SDL_Rect temp_dest { x*dest.w, y*dest.h, dest.w, dest.h};
            SDL_RenderCopy(renderer, image, &src, &temp_dest);
        }
    }
}

SDL_Rect* CSprite::get_dest() { return &dest; }
int CSprite::get_x() { return dest.x; }
int CSprite::get_y() { return dest.y; }

void CSprite::set_dest_x(int x) { dest.x = x; }
void CSprite::set_dest_y(int y) { dest.y = y; }
void CSprite::set_dest_x_y(int x, int y) { dest.x = x; dest.y = y; };

void CSprite::add_dest_x(int x) { dest.x += x; }
void CSprite::add_dest_y(int y) { dest.y += y; }
void CSprite::add_dest_x_y(int x, int y) { dest.x += x; dest.y += y; }

void CSprite::apply_add_x() { add_dest_x(x); }
void CSprite::apply_add_y() { add_dest_y(y); }
void CSprite::apply_add_x_y() { add_dest_x(x); add_dest_y(y); }

void CSprite::set_add_x(int x) { this->x = x; }
void CSprite::set_add_y(int y) { this->y = y; }

SDL_Renderer* CSprite::get_renderer() { return renderer; }

void CSprite::update_animation() {;}
void CSprite::set_animation_mode(int h) {;}
bool CSprite::do_animate() { return false; }

void CSprite::setAtmAnimate(bool) {}
bool CSprite::getAtmAnimate() { return true; }

void CSprite::handle_motion() {;}

void CSprite::w() { }
void CSprite::a() { }
void CSprite::s() { }
void CSprite::d() { }
