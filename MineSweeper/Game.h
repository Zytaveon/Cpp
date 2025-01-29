#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>

class Game{
    public:
        Game(int rows, int cols);

        
        //testerFunctions
        void printTopGrid();
        void printBottomGrid();

    private:

        /*
            Top Grid is going to decide if a square has been uncovered or not
            Bottom Grid is going to have mines/number of mines
        */    
        std::vector<std::vector<int>> bottomGrid;
        std::vector<std::vector<int>> topGrid;

        int gridRows;
        int gridCols;


};

#endif