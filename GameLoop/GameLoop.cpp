#include "GameLoop.h"


GameLoop::GameLoop()
{
    Running = true;
    SDL_Window*     window = NULL;
    SDL_Renderer*   renderer = NULL;
    SDL_Texture*    Texture_Grid = NULL, *Texture_X = NULL, *Texture_O = NULL;
    tPlayer         playerTurn = PLAYER_X;
    vector<GRID_TYPE>     theGrid;
}

void GameLoop::SetCell(int ID, GRID_TYPE Type) {
    if(ID < 0 || ID >= 9) return;
    if(Type < 0 || Type > GRID_TYPE_O) return;

    theGrid[ID] = Type;
}

void GameLoop::ResetGrid(vector<GRID_TYPE>* grid){
    for(int i = 0; i < (*grid).size() ; i++){
        (*grid).at(i) = GRID_TYPE_NONE;
    }
}

bool GameLoop::gameOver(const vector<GRID_TYPE>* grid){
    if(whoWins(grid)==PLAYER_NONE) {return false;}
    else {return true;}
}

tPlayer GameLoop::whoWins(const vector<GRID_TYPE> *grid){
    tPlayer winner = PLAYER_NONE;
    for(int i = 0; i < 3; i++){
        if(((*grid)[3*i]== GRID_TYPE_X && (*grid)[3*i+1]== GRID_TYPE_X && (*grid)[3*i+2]== GRID_TYPE_X) ||
            ((*grid)[i] == GRID_TYPE_X && (*grid)[3+i]  == GRID_TYPE_X && (*grid)[6+i]  == GRID_TYPE_X)){
            winner=PLAYER_X;
        }
        else if(((*grid)[3*i]== GRID_TYPE_O && (*grid)[3*i+1]== GRID_TYPE_O && (*grid)[3*i+2]== GRID_TYPE_O) ||
                ((*grid)[i]  == GRID_TYPE_O && (*grid)[3+i]  == GRID_TYPE_O && (*grid)[6+i]  == GRID_TYPE_O)){
            winner=PLAYER_O;
        }
    }
    if(((*grid)[0] == GRID_TYPE_X && (*grid)[4]== GRID_TYPE_X && (*grid)[8]== GRID_TYPE_X) ||
        ((*grid)[2]== GRID_TYPE_X && (*grid)[4]== GRID_TYPE_X && (*grid)[6]== GRID_TYPE_X)){
        winner=PLAYER_X;
    }
    else if(((*grid)[0]== GRID_TYPE_O && (*grid)[4]== GRID_TYPE_O && (*grid)[8]== GRID_TYPE_O) ||
            ((*grid)[2]== GRID_TYPE_O && (*grid)[4]== GRID_TYPE_O && (*grid)[6]== GRID_TYPE_O)){
        winner=PLAYER_O;
    }
    return winner;
}
void GameLoop::OnLoop()
{
    bool gridFull = true;
    for(int i = 0; i < theGrid.size() ; i++){
        if(theGrid[i] == GRID_TYPE_NONE){
            gridFull = false;
        }
    }
    if(gameOver(&theGrid)||gridFull){
        if(whoWins(&theGrid)== PLAYER_X){
            cout << "Player X won" <<endl;
        }
        else if (whoWins(&theGrid)== PLAYER_O){cout << "Player O won" <<endl;}
        else cout << "Draw" << endl;
        cout << "Reset must be done" << endl;
        ResetGrid(&theGrid);
        cout << "Reset done" << endl;
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
