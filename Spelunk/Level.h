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
        void grabCollectable(int row, int col);
        void enableShop();
        void disableShop();
        void loadTextures();
        void unloadtextures();

        void printBoard();

    private:

        int textureSize = 32;
        Texture2D textures = {};

        static constexpr int boardHeight = 50;
        static constexpr int boardWidth = 50;

        int board[boardHeight][boardWidth];
        int currentLevel;

        bool shopEnabled = false;

        std::string getLevelFile(int currentLevel);
        void loadLevel(std::string file);

        //Tester Functions
        // void printBoard();



};

#endif