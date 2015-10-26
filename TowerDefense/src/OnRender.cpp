#include "Game.h"

void Game::OnRender()
{
    SDL_RenderClear(Renderer);

    Map1.RenderMap(Renderer);

    SDL_RenderPresent(Renderer);
}

/// Draw Functions ...

bool Game::Draw(SDL_Renderer* Rend,
                SDL_Texture* Temp,
                int x, int y, int w, int h,
                SDL_RendererFlip Flip)
{
    //Rectangle for Position
    SDL_Rect dstrect;

    //Texture is empty
    if(Temp == NULL)
    {
        return false;
    }

    dstrect.x = x;
    dstrect.y = y;
    dstrect.w = w;
    dstrect.h = h;


    //Draw on the screen
	SDL_RenderCopyEx(Rend, Temp, NULL, &dstrect, 0, NULL, Flip);

	return true;
}

bool Game::Draw(SDL_Renderer* Rend,
                SDL_Texture* Temp,
/*Location*/    int x, int y, int w, int h,
/*  Part  */    int x2, int y2, int w2, int h2,
                SDL_RendererFlip Flip)
{
    //Rectangle for position
    SDL_Rect dstrect;
    //Rectangle for part of an image
    SDL_Rect srtrect;

    //Texture is empty
    if(Temp == NULL)
    {
        return false;
    }

    dstrect.x = x;
    dstrect.y = y;
    dstrect.w = w;
    dstrect.h = h;

    srtrect.x = x2;
    srtrect.y = y2;
    srtrect.w = w2;
    srtrect.h = h2;


    //Draw on the screen
	SDL_RenderCopyEx(Rend, Temp, &srtrect, &dstrect, 0, NULL, Flip);

	return true;
}
