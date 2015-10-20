#include "GameLoop.h"


GameLoop::GameLoop()
{
    Running = true;
    SDL_Window*     window = NULL;
    SDL_Renderer*   renderer = NULL;
    SDL_Texture*    Texture_Grid = NULL, *Texture_X = NULL, *Texture_O = NULL;
    int             playerTurn = PLAYER_X;
    vector<GRID_TYPE>     theGrid;
}

void GameLoop::SetCell(int ID, GRID_TYPE Type) {
    if(ID < 0 || ID >= 9) return;
    if(Type < 0 || Type > GRID_TYPE_O) return;

    theGrid[ID] = Type;
}

void GameLoop::ResetGrid(){
    for(int i = 0; i < theGrid.size() ; i++){
        theGrid[i] = GRID_TYPE_NONE;
    }
}
void GameLoop::OnLoop()
{
    bool gridFull = true;
    for(int i = 0; i < theGrid.size() ; i++){
        if(theGrid[i] == GRID_TYPE_NONE){
            gridFull = false;
        }
    }
    if(gridFull){
        ResetGrid();
    }

}

void GameLoop::OnCleanup()
{
    //Free loaded image
    SDL_DestroyTexture( Texture_Grid );
    SDL_DestroyTexture( Texture_X );
    SDL_DestroyTexture( Texture_O );
    Texture_Grid    = NULL;
    Texture_X       = NULL;
    Texture_O       = NULL;

    //Destroy window
    SDL_DestroyRenderer( renderer );
    SDL_DestroyWindow( window );
    renderer = NULL;
    window = NULL;
    SDL_Quit();
}

int GameLoop::OnExecute()
{
    if(OnInit() == false)
    {
        return -1;
    }

    SDL_Event Event;

    while(Running)
    {
        while(SDL_PollEvent(&Event))
        {
            OnEvent(&Event);
        }
        OnLoop();
        OnRender();
    }

    OnCleanup();

    return 0;
}

int main(int argc, char* argv[])
{
    GameLoop theApp;

    return theApp.OnExecute();
}
