#ifndef MAP_H
#define MAP_H

#include "TILE.h"
#include "Includes.h"

#define MAP_X 16
#define MAP_Y 16

class Map
{
    public:
        Map();
        virtual ~Map();

        ifstream loadMap;

        TILE* hoverTile;

        TILE tile_map[MAP_X][MAP_Y];

        SDL_Texture* Tileset_Image;
        int hoverImage;

        bool LoadTileSet();
        void RenderMap(SDL_Renderer* Rend);
        TILE* GetHoverTile();
        bool OnHover();
        void BuildTower();

    protected:
    private:
};

#endif // MAP_H
