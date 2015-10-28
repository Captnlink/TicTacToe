#include "GameLoop.h"

void GameLoop::OnRender()
{
    //Clear screen
    SDL_RenderClear( renderer );

    //Render texture to screen
    CTexture::OnDraw(renderer, Texture_Background, 0,0);
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
        SDL_Point point;
        double angle = 0.0;
        int ID = IDWins(&theGrid);
        cout  << "ID " << ID ;
        if(ID == 0 || ID == 1 || ID == 2){
            lineRect.x = 3*TILE_SIZE/16 + (OFFSETX);
            lineRect.y = ID*TILE_SIZE + OFFSETY + TILE_SIZE/3 +10;
            lineRect.w = TILE_SIZE*2.5;
            angle = 0.0;
            point.x = lineRect.w/2;
            point.y = lineRect.h/2;
            cout  << "X : " << 3*TILE_SIZE/16 + (OFFSETX) << " Y : " << ID*TILE_SIZE + OFFSETY + TILE_SIZE/3 +10;
        }
        else if(ID == 3|| ID == 4|| ID == 5){
            lineRect.x = (ID-3)*TILE_SIZE + OFFSETX + TILE_SIZE/3 +40;
            lineRect.y = TILE_SIZE/4 + OFFSETY-10;
            lineRect.w = TILE_SIZE*2.5;
            point.x = point.y = 0;
            angle = 90.0;
            cout  << "X : " << (ID-3)*TILE_SIZE + OFFSETX + TILE_SIZE/3 +40 << "Y : " << TILE_SIZE/4 + OFFSETY-10;
        }

         else if(ID == 6 || ID == 7) {
            lineRect.x = OFFSETX + TILE_SIZE/3 +30;
            lineRect.y = TILE_SIZE/3 + OFFSETY;
            lineRect.w = TILE_SIZE*3;
            angle = 45.0;
            point.x = point.y = 0;
            cout  << "X : " << OFFSETX + TILE_SIZE/3 +30 << "Y : " << TILE_SIZE/3 + OFFSETY;
         }
        if(ID == 7){
            lineRect.x = OFFSETX + TILE_SIZE/3 + 2.5*TILE_SIZE;
            angle = 135.0;
            cout << "FLIP" << endl;
        }
        cout << "lineRect." << "X : " << lineRect.x << " " << "lineRect." << "Y : " << lineRect.y <<endl;
        CTexture::OnDrawAngle(renderer, Texture_Line, &lineRect, NULL, angle, &point);
    }
    //Update screen
    SDL_RenderPresent( renderer );
}
