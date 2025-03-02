#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "include/raylib.h"
#include "Level.h"
#include "Player.h"
#include "Shop.h"

class Game{
    public:
        Game(int windowHeight, int windowWidth);

        void runGame();
    
    private:
        int WINDOWWIDTH;
        int WINDOWHEIGHT;

};

#endif