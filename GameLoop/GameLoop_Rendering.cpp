#include "GameLoop.h"

void GameLoop::OnRender()
{
    //Clear screen
    SDL_RenderClear( renderer );

    //Render texture to screen
    CTexture::OnDraw(renderer, Texture_Background);
    CTexture::OnDraw(renderer, Texture_Menu, &menuRect, NULL);
    CTexture::OnDraw(renderer, Texture_Grid, &gridRect, NULL);

    //Draw each marks
    for(int i = 0; i < 9; i++)
    {
        tokenRect.x = (i % 3)*TILE_SIZE+OFFSETX;
        tokenRect.y = (i / 3)*TILE_SIZE+OFFSETY;
        tokenRect.h = tokenRect.w = TILE_SIZE;
        if(theGrid[i] == GRID_TYPE_X)
        {
            CTexture::OnDraw(renderer,Texture_X, &tokenRect, NULL);
        }
        else if(theGrid[i] == GRID_TYPE_O)
        {
            CTexture::OnDraw(renderer,Texture_O,&tokenRect,NULL);
        }
    }

    //If gameOver
    if(gameOver(&theGrid)){
        CTexture::OnDraw(renderer, Texture_Line, &lineRect, NULL);
        cout << "                           x y"<< lineRect.x << " " << lineRect.y <<endl;
    }
    //Update screen
    SDL_RenderPresent( renderer );
}
