#include "CSurface.h"


CSurface::CSurface() {
    SDL_Surface* loadedImage = NULL;

}

SDL_Surface* CSurface::OnLoad(string path) {
    SDL_Surface* loadedImage = IMG_Load( path.c_str() );
    if( loadedImage == NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
    }
    //Convert surface to screen format
    else if(PRINT_DEBUG) {cout << "Image Loaded : " << path << endl;}

    return loadedImage;
}

SDL_Surface* CSurface::OnLoad(string path, SDL_Surface* screenSurface) {
    SDL_Surface* optimizedSurface = NULL;
    SDL_Surface* loadedImage = IMG_Load( path.c_str() );
    if( loadedImage == NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
    }
    else{
        //Convert surface to screen format
        if(PRINT_DEBUG) {cout << "Image Loaded : " << path << endl;}

		optimizedSurface = SDL_ConvertSurface( loadedImage, screenSurface->format, NULL );
		if( optimizedSurface == NULL )
		{
			printf( "Unable to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}
        else if(PRINT_DEBUG) {cout << "Image Optimized : " << path << endl;}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedImage );
		loadedImage = NULL;
    }


    return optimizedSurface;
}

bool CSurface::OnDraw(SDL_Surface* Surf_Dest, SDL_Surface* Surf_Src, int X, int Y) {
    if(Surf_Dest == NULL || Surf_Src == NULL) {
        return false;
    }
    SDL_Rect DestR;

    DestR.x = X;
    DestR.y = Y;

    SDL_BlitSurface(Surf_Src, NULL, Surf_Dest, &DestR);

    return true;
}

bool CSurface::OnDraw(SDL_Surface* Surf_Dest, SDL_Surface* Surf_Src, int X, int Y, int x2, int y2, int width, int height) {
    if(Surf_Dest == NULL || Surf_Src == NULL) {
        return false;
    }
    SDL_Rect DestR;
    DestR.x = X;
    DestR.y = Y;

    //Apply the image stretched
    SDL_Rect stretchRect;
    stretchRect.x = x2;
    stretchRect.y = y2;
    stretchRect.w = width;
    stretchRect.h = height;
    SDL_BlitScaled( Surf_Src, &DestR, Surf_Dest, &stretchRect );

    return true;
}

bool CSurface::Transparent(SDL_Surface* Surf_Dest, int R, int G, int B){
    if(Surf_Dest == NULL) {
        return false;
    }
    SDL_SetColorKey(Surf_Dest, SDL_TRUE , SDL_MapRGB(Surf_Dest->format, R, G, B));
    return true;
}
