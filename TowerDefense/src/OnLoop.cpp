#include "Game.h"

void Game::OnLoop()
{
    OnStartup();

    //Cursor

    SDL_SetCursor(SDL_GetDefaultCursor());

    Map1.OnHover();

    FrameRate(FPS);
}

void Game::MouseDrag(Entity *object)
{
    //Cursor on Hover

    if(dragOne == true && object->draggable == false)
        return;

    int mouseX = 0;
    int mouseY = 0;

    SDL_GetMouseState(&mouseX, &mouseY);

    if(object->Hover(mouseX, mouseY) == true)
    {
        SDL_SetCursor(Cursor);

        if(LeftButtonPressed == true)
            object->draggable = true;
    }

    if(LeftButtonPressed == false)
        object->draggable = false;

    if(object->draggable == true)
    {
        object->XPos = mouseX - object->Width / 2;
        object->YPos = mouseY - object->Height / 2;
        SDL_SetCursor(DragCursor);
        dragOne = true;
    }
    else
        dragOne = false;
}

void Game::MakeResponsive()
{
    SDL_GetWindowSize(Window, &WindowWidth, &WindowHeight);

    float Window_Width = WindowWidth;
    float Window_Height = WindowHeight;

    Kx = Window_Width / MIN_WINDOW_X;
    Ky = Window_Height / MIN_WINDOW_Y;
}
