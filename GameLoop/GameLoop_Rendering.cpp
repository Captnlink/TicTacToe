#include "GameLoop.h"

void GameLoop::OnRender()
{
    //Clear screen
    SDL_RenderClear( renderer );

    //Render texture to screen
    CTexture::OnDraw(renderer,Texture_Grid);

    for(int i = 0; i < 9; i++)
    {
        int X = (i % 3)*TILE_SIZE;
        int Y = (i / 3)*TILE_SIZE;
        if(theGrid[i] == GRID_TYPE_X)
        {
            CTexture::OnDraw(renderer,Texture_X,X,Y);
        }
        else if(theGrid[i] == GRID_TYPE_O)
        {
            CTexture::OnDraw(renderer,Texture_O,X,Y);
        }
    }
    //Update screen
    SDL_RenderPresent( renderer );
}
