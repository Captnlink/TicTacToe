#include "GameLoop.h"

//Initialization of GameLoop
bool GameLoop::OnInit()
{
    //Initialization of SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0){
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        return false;}
    else if(PRINT_DEBUG){cout << "SDL Initialized" << endl;}

    //Initialization of the window
    window = SDL_CreateWindow( WINDOW_TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
    if( window == NULL ){
        printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
        return false;}
    else if(PRINT_DEBUG){cout << "Window created" << endl;}

    //Initialization of SDL_Image
    int imgFlags = IMG_INIT_PNG;
    if( !( IMG_Init( imgFlags ) & imgFlags ) ){
        printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
        return false;}
    else if(PRINT_DEBUG){cout << "SDL_image Initialized" << endl;}

    //Create renderer for window
    renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );
    if( renderer == NULL ){
        printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
        return false;}
    else if(PRINT_DEBUG){cout << "renderer Initialized" << endl;}
    //Initialize renderer color
    SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );

    //Loading of Loading screen
    CTexture texture_Image;
    Texture_Grid = CTexture::OnLoad("Images\\Loading.png", renderer);
    CTexture::OnDraw(renderer,Texture_Grid,0,0,SCREEN_WIDTH,SCREEN_HEIGHT);
    SDL_RenderPresent( renderer );
    SDL_DestroyTexture( Texture_Grid );

    //Loading Texture
    Texture_X =         CTexture::OnLoadTransparent("Images\\x.png", renderer, 0xFF, 0x00, 0xFF);
    Texture_O =         CTexture::OnLoadTransparent("Images\\o.png", renderer, 255, 0, 255);
    Texture_Grid =      CTexture::OnLoad("Images\\grid.png", renderer);
    Texture_Menu =      CTexture::OnLoad("Images\\UI_Menu.png", renderer);
    Texture_Background =CTexture::OnLoad("Images\\background.png", renderer);
    Texture_Line =      CTexture::OnLoad("Images\\lines.png", renderer);

    if(Texture_X == NULL || Texture_O == NULL || Texture_Grid == NULL){
        printf( "Texture could not be loaded!\n SDL Error: %s\n", SDL_GetError() );
        return false;}
    if(PRINT_DEBUG){cout << "Texture Loaded" << endl;}

    playerTurn = PLAYER_X;

    //Initializing the grid
    for(int i = 0; i < 9 ; i++){
        theGrid.push_back(GRID_TYPE_NONE);}
    if(theGrid.size() == 9){
        cout << "The grid has been initialized to : " << theGrid.size() << endl;    }
    else return false;

 // Test de placement de grid et menu

    menuRect.y = menuRect.x =0;
    menuRect.h = 550;
    menuRect.w = 350;

    gridRect.x = OFFSETX;
    gridRect.y = OFFSETY;
    gridRect.h = gridRect.w = GRID_WIDTH;

    int  h;
	SDL_QueryTexture(Texture_Line, NULL, NULL, NULL, &h);
    lineRect.h = h;
    lineRect.w = 2*TILE_SIZE;

    SDL_Delay(500);
    if(PRINT_DEBUG){cout << "Init End : NO_ERROR" << endl;}
    return true;
}
