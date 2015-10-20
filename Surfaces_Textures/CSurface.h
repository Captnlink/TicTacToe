#ifndef CSURFACE_H_
    #define CSURFACE_H_

#include "../Define.h"

class CSurface {
    private:
    SDL_Surface* loadedImage;

    public:
        CSurface();

    public:
        static SDL_Surface* OnLoad(string path);
        static SDL_Surface* OnLoad(string path, SDL_Surface* screenSurface);
        static bool         OnDraw(SDL_Surface* Surf_Dest, SDL_Surface* Surf_Src, int X, int Y);
        static bool         OnDraw(SDL_Surface* Surf_Dest, SDL_Surface* Surf_Src, int X, int Y, int x2, int y2, int width, int height);
        static bool         Transparent(SDL_Surface* Surf_Dest, int R, int G, int B);
};

#endif
