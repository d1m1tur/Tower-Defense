#ifndef TILE_H
#define TILE_H

#include "Includes.h"

#define TILE_WIDTH 32
#define TILE_HEIGHT 32

class TILE
{
    public:
        TILE();
        virtual ~TILE();

        int xCoord; // X of the matrix
        int yCoord; // Y of the matrix
        int tileProperty; // Tile Properties : 0 for disabled 1 for solid etc.
        int tileSetCoord; // Coordinates of the image from the tile set

        void DrawTile(SDL_Renderer* Rend, SDL_Texture* TileTemp);
        void LoadTile(int x, int y, int prop, int xImg);

    protected:
    private:
};

#endif // TILE_H
