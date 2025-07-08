#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include "include/raylib.h"

class Game{
    public:
        
        Game(int WinWidth, int WinHeight, int gridRows, int gridCols);

        void drawGame();
        void printGrid();

    private:

        int WindowWidth;
        int WindowHeight;

        int gridCols;
        int gridRows;
        int cellHeight;
        int cellWidth;

        std::vector<std::vector<int>> Grid;

};

#endif