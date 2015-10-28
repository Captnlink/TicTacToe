#ifndef CCTEXTURE_H_
    #define CTEXTURE_H_

#include "../Define.h"

class CTexture {
    private:
    SDL_Texture* newTexture;

    public:
        CTexture();

    public:
        static SDL_Texture* OnLoad(string path, SDL_Renderer* renderer);
        static SDL_Texture* OnLoadTransparent(string path, SDL_Renderer* renderer, int red, int green, int blue);
        static bool         OnDraw(SDL_Renderer* renderer, SDL_Texture* Texture,int x = 0, int y = 0, int w = 0, int h = 0);
        static bool         OnDraw(SDL_Renderer* renderer, SDL_Texture* Texture, SDL_Rect* destRect,SDL_Rect* srcRect);
        static bool OnDrawAngle(SDL_Renderer* renderer, SDL_Texture* Texture, SDL_Rect* destRect,SDL_Rect* srcRect = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);

};

#endif
