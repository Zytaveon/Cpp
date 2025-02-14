#ifndef LEVEL_H
#define LEVEL_H

#include <iostream>
#include <array>
#include <fstream>
#include <string>
#include "include/raylib.h"

class Level{
    public:
        Level();
        void drawLevel();
        int getCellValue(int row, int col);

    private:
        static constexpr int boardHeight = 50;
        static constexpr int boardWidth = 50;

        int board[boardHeight][boardWidth];
        int currentLevel;

        std::string getLevelFile(int currentLevel);
        void loadLevel(std::string file);

        //Tester Functions
        void printBoard();



};

#endif