#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>

class Game{
    public:
        Game(int windowWidth, int windowHeight, int rows, int cols);

        
        //testerFunctions
        void printTopGrid();
        void printBottomGrid();

        void drawGame(int gridWidth, int gridHeight);
        void revealSquares(struct Vector2 mousePosition);

    private:

        /*
            Top Grid is going to decide if a square has been uncovered or not
            Bottom Grid is going to have mines/number of mines
        */    
        std::vector<std::vector<int>> bottomGrid;
        std::vector<std::vector<int>> topGrid;

        int gridRows;
        int gridCols;
        int totalGridSquares;
        int windowHeight;
        int windowWidth;

        //To start, mines will be 10% of totalGridSquares, but always aleast one.
        void addMines();

        //For every square, count how many mines it has for its "neighbors"
        //and change the value to reflect that.
        void addNeighbors();

        //Helper function for addNeighbors
        int getNeighbors(int currentRow, int currentCol);

        struct Color getColor(int row, int col);

        bool isCovered(int row, int col) {return !topGrid.at(row).at(col);}

        /*
            revealSquares takes the raw mouseInput and will give it to this function

            This function should uncover multiple squares at a time if there is no
            number value associated with the square (No mines as its neighbor)
        */
        void revealSquaresHelper(int row, int col);

};

#endif