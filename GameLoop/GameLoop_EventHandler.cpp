#include "GameLoop.h"

void GameLoop::OnEvent(SDL_Event* Event){
    EventHandlerAbstract::OnEvent(Event);
}
void GameLoop::OnExit()
{
    Running = false;
}

void GameLoop::OnKeyDown(const Uint8* scancode)
{
    if(scancode[SDL_SCANCODE_UP])
    {
        cout << "Key Pressed : UP" << endl;
    }
    else if(scancode[SDL_SCANCODE_DOWN])
    {
        cout << "Key Pressed : DOWN" << endl;
    }
    else if(scancode[SDL_SCANCODE_LEFT])
    {
        cout << "Key Pressed : LEFT" << endl;
    }
    else if(scancode[SDL_SCANCODE_RIGHT])
    {
        cout << "Key Pressed : RIGHT" << endl;
    }
}
void GameLoop::OnMButtonDown(int x, int y)
{
    cout << "Mouse Coordinate x : " << x << " y : " << y << endl;
    if(x>OFFSETX && y>OFFSETY && !gameOver(&theGrid))
    {
        int ID = ((x-OFFSETX)/TILE_SIZE) + (((y-OFFSETY)/TILE_SIZE)*3);
        //cout << "ID : " << ID << endl;
        if(playerTurn == PLAYER_X && theGrid[ID] == GRID_TYPE_NONE)
        {
            SetCell( ID, GRID_TYPE_X);
            playerTurn = PLAYER_O;
        }
        else if(playerTurn == PLAYER_O && theGrid[ID] == GRID_TYPE_NONE)
        {
            SetCell( ID, GRID_TYPE_O);
            playerTurn = PLAYER_X;
        }
    }
    //x70 y165 x1:270 y1:200 h:35 w:200
    if(70<x && x<270 && 165<y && y<200){
        cout << "New Game" << endl;
        ResetGrid(&theGrid);
    }
}

