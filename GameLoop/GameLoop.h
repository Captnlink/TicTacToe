#ifndef GameLoop_H_
    #define GameLoop_H_

#include "../Define.h"
#include "../EventHandler/EventHandlerAbstract.h"
#include "../Surfaces_Textures/CSurface.h"
#include "../Surfaces_Textures/CTexture.h"

class GameLoop : public EventHandlerAbstract{
    private:
        bool            Running;
        SDL_Window*     window;
        SDL_Renderer*   renderer;
        SDL_Texture*    Texture_Grid, *Texture_X, *Texture_O;
        int             playerTurn;                             //int to give the player turn PLAYER_START | PLAYER_X | PLAYER_O
        vector<GRID_TYPE>     theGrid;

    public:
        GameLoop();
        int OnExecute();

    private:
        bool OnInit();
        void OnEvent(SDL_Event* Event);
        void OnLoop();
        void OnRender();
        void OnCleanup();
        void SetCell(int ID, GRID_TYPE Type);
        void ResetGrid(vector<GRID_TYPE>* grid);
        tPlayer whoWins(const vector<GRID_TYPE>* grid);
        bool gameOver(const vector<GRID_TYPE>* grid);
        //Events
        void OnKeyDown(const Uint8* scancode);
        void OnMButtonDown(int x, int y);
        void OnExit();
};

#endif
