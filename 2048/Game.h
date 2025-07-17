#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include "include/raylib.h"

class Game{
    public:
        
        Game(int WinWidth, int WinHeight, int gridRows, int gridCols);

        void drawGame();

        void shiftLeft();
        void shiftRight();
        void shiftUp();
        void shiftDown();

        //Used for testing
        void gameTester();

    private:

        int WindowWidth;
        int WindowHeight;

        int gridCols;
        int gridRows;
        int cellHeight;
        int cellWidth;

        Color blockColor;

        std::vector<std::vector<int>> Grid;
        std::vector<std::vector<int>> tempGrid;

        void printGrid();
        void addStartBlocks();

        /*
        All shifts will use this function
        The turn param will decide when the gravity is taken into effect
        For example, shift right will do ONE 90 degree turn,
            push the blocks all down,
            then move 3 more times to be back to normal
        */
        void shiftBlocks(int turn);

        void clockwiseRotate();

        void gravityOnBlocks();

};

#endif