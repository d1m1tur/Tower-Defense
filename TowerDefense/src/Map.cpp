#include "Map.h"

Map::Map()
{
    Tileset_Image = NULL;
    hoverImage = 2;
}

Map::~Map()
{
    //dtor
}

bool Map::LoadTileSet()
{
    int firstPar;
    int secondPar;
    char spliter;

    if(Tileset_Image == NULL)
    {
        cout<<"Tile set Image not loaded!"<<endl;
        return false;
    }

    if(loadMap == NULL)
    {
        cout<<"Map not loaded!"<<endl;
        return false;
    }

    for(int y = 0; y < MAP_Y; y ++)
    {
        for(int x = 0; x < MAP_X; x ++)
        {
            loadMap >> firstPar;
            loadMap >> spliter;
            loadMap >> secondPar;

            tile_map[y][x].LoadTile(x, y, firstPar, secondPar);
        }
    }

    return true;
}

void Map::RenderMap(SDL_Renderer* Rend)
{
    for(int i = 0; i < MAP_X; i ++)
    {
        for(int j = 0; j < MAP_Y; j ++)
        {
            if(tile_map[i][j].tileProperty == 0) continue; // Don't Render if the tile is disabled

            tile_map[i][j].DrawTile(Rend, Tileset_Image);
        }
    }
}

TILE* Map::GetHoverTile()
{
    int Mx = 0;
    int My = 0;

    SDL_GetMouseState(&Mx, &My);

    if(Mx < 0 || Mx > MAP_X * TILE_WIDTH)
        return NULL;
    if(My < 0 || My > MAP_Y * TILE_HEIGHT)
        return NULL;

    int tileX = Mx / TILE_WIDTH;
    int tileY = My / TILE_HEIGHT;

    return &tile_map[tileY][tileX];
}

bool Map::OnHover()
{
    if(hoverTile != NULL)
        hoverTile->tileSetCoord = 1 * TILE_WIDTH;

    if((hoverTile = GetHoverTile()) == NULL)
    {
        cout<<"Mouse out of the window"<<endl;
        return false;
    }



    hoverTile->tileSetCoord = hoverImage * TILE_WIDTH;

    return true;
}

void Map::BuildTower()
{

}
