#include "CTexture.h"
#include "CSurface.h"

CTexture::CTexture() {
}

/**
* Load a image to a *texture
* @param path of the file
* @param renderer The renderer
*/
SDL_Texture* CTexture::OnLoad(string path, SDL_Renderer* renderer) {
    SDL_Texture* newTexture = IMG_LoadTexture(renderer, path.c_str());
    if( newTexture == NULL )
    {
        printf( "Unable to load texture %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
        return NULL;
    }
    else if(PRINT_DEBUG) {cout << "Image Textured : " << path << endl;}

    return newTexture;
}

/**
* Load an image on a surface and apply to it some transparency
*After, transform the surface to a texture
* @param renderer The renderer we want to draw to
* @param path to the file we want to load
* @param Color keying of the transparency
*/
SDL_Texture* CTexture::OnLoadTransparent(string path, SDL_Renderer* renderer, int red, int green, int blue){

    SDL_Surface* surface = CSurface::OnLoad( path );
    CSurface::Transparent(surface, red, green, blue);
    SDL_Texture* newTexture = SDL_CreateTextureFromSurface( renderer, surface);
    SDL_FreeSurface( surface );

    return newTexture;
}


/**
* Draw an SDL_Texture to an SDL_Renderer at position x, y, with some desired
* width and height
* @param renderer The renderer we want to draw to
* @param Texture The source texture we want to draw
* @param x2 The x coordinate to draw to
* @param y2 The y coordinate to draw to
*/
bool CTexture::OnDraw(SDL_Renderer* renderer, SDL_Texture* Texture,int x, int y) {
    if(renderer == NULL || Texture == NULL) {
        return false;
    }
    int w, h;
	SDL_QueryTexture(Texture, NULL, NULL, &w, &h);

    SDL_Rect destRect;
    destRect.x = x;
    destRect.y = y;
    destRect.h = h;
    destRect.w = w;

    SDL_RenderCopy( renderer, Texture,NULL, &destRect);

    return true;
}

/**
* Draw an SDL_Texture to an SDL_Renderer at position x, y
* with some desired width and height
* @param renderer The renderer we want to draw to
* @param Texture The source texture we want to draw
* @param x The x coordinate to draw to
* @param y The y coordinate to draw to
* @param w The width of the texture to draw
* @param h The height of the texture to draw
*/
bool CTexture::OnDraw(SDL_Renderer* renderer, SDL_Texture* Texture, int x, int y, int w, int h) {
    if(renderer == NULL || Texture == NULL) {
        return false;
    }
    SDL_Rect destRect;

    destRect.x = x;
    destRect.y = y;
    destRect.w = w;
    destRect.h = h;

    SDL_RenderCopy( renderer, Texture,NULL, &destRect);

    return true;
}

/**
* Draw an SDL_Texture to an SDL_Renderer at position x, y
* with some desired width and height
* @param renderer The renderer we want to draw to
* @param Texture The source texture we want to draw
* @param srcRect.x The x coordinate of top left corner
* @param srcRect.y The y coordinate of top left corner
* @param srcRect.w The width of the texture to draw
* @param srcRect.h The height of the texture to draw
* @param destRect.x The x coordinate of top left corner on the window
* @param destRect.y The y coordinate of top left corner on the window
* @param destRect.w The width of the texture on the window
* @param destRect.h The height of the texture on the window
*/
bool CTexture::OnDraw(SDL_Renderer* renderer, SDL_Texture* Texture, SDL_Rect* destRect,SDL_Rect* srcRect) {
    if(renderer == NULL || Texture == NULL) {
        return false;
    }

    SDL_RenderCopy( renderer, Texture,srcRect, destRect);

    return true;
}
