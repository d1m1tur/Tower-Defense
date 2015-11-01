#ifndef ENEMIES_H
#define ENEMIES_H

#include "Includes.h"

class Enemies
{
    public:
        Enemies();
        virtual ~Enemies();

        int health;
        int speed;

        float xPos;
        float yPos;
        float width;
        float height;

        SDL_Texture* Enemy_Image;

    protected:
    private:
};

#endif // ENEMIES_H
