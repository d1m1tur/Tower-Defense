#include "Game.h"

bool Game::OnInit()
{
    //Initialize everything in SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        return false;
    }

    //Creating Window             title ,Xpos,Ypos,Width,Height, settings
    if((Window = SDL_CreateWindow("Tower Defense", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, MIN_WINDOW_X, MIN_WINDOW_Y,
                                  SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE)) == NULL)
    {
        return false;
    }

    SDL_SetWindowMaximumSize(Window, MAX_WINDOW_X, MAX_WINDOW_Y);
    SDL_SetWindowMinimumSize(Window, MIN_WINDOW_X, MIN_WINDOW_Y);

    SDL_GetWindowSize(Window, &WindowWidth, &WindowHeight);

    Fullscreen = false;

    if((Icon = IMG_Load("./Resources/Images/favicon.png")) == NULL)
    {
        return false;
    }

    SDL_SetWindowIcon(Window, Icon);

    // Creating Renderer
    Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);


    //Creating Entities

    if( (Cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_HAND)) == NULL)
    {
        return false;
    }

    if( (DragCursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_SIZEALL)) == NULL)
    {
        return false;
    }

    //Check Renderer
    if(Renderer == NULL)
    {
        cout << SDL_GetError() << endl;
        return false;
    }

    //Load Images

    Map1.Tileset_Image = OnLoad(Renderer, "./Resources/Images/tileset.png");

    Map1.loadMap.open("./Resources/Maps/map1.txt");

    if(Map1.LoadTileSet() == false)
    {
        return false;
    }

    return true;
}

SDL_Texture* Game::OnLoad(SDL_Renderer* Rend, char* File)
{
    SDL_Surface* Surf_Temp = NULL;
    SDL_Texture* Text_Return = NULL;

    if((Surf_Temp = IMG_Load(File)) == NULL)
    {
        cout<<"Surface not loaded"<<endl;
        return NULL;
    }

    if((Text_Return = SDL_CreateTextureFromSurface(Rend, Surf_Temp)) == NULL)
    {
        cout<<"Creating texture from surface failed! Check your Renderer."<<endl;
        return NULL;
    }

    SDL_FreeSurface(Surf_Temp);

    return Text_Return;
}
