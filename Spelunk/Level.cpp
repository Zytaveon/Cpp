#include "Level.h"

//Will get the defualt level currently
Level::Level(int startingLevel){
    currentLevel = startingLevel;
    loadLevel(getLevelFile(currentLevel));
    loadTextures();
}

void Level::drawLevel(){

    //Error color. Should get changed later
    Color blockColor = PURPLE;

    for(int i = 0; i < boardHeight; ++i){
        for (int j = 0; j < boardWidth; ++j){

            //Open Space
            if(board[i][j] ==  48){
                blockColor = WHITE;
            }

            //Wall
            else if(board[i][j] == 49){
                blockColor = BLACK;
            }

            else if(board[i][j] == 67){
                blockColor = YELLOW;
            }

            //Should never happen
            else{
                blockColor = PURPLE;
            }

            DrawRectanglePro(
                {(float)j * 50, (float)i * 50, 50 - 1, 50 -1 },
                {0,0},
                0,
                blockColor
            );

            // DrawTexturePro(
                // textures,
                // {(float)textureSize * board[i][j], 0, (float)textureSize, (float)textureSize},
                // {(float)j * 50, (float)i * 50, 50 - 1, 50 - 1},
                // {0,0},
                // 0.0f,
                // WHITE
            // );
        }
    }
}

int Level::getCellValue(int row, int col){
    return board[row][col];
}

void Level::grabCollectable(int row, int col){
    if(board[row][col] != 2){
        std::cout <<"ERROR IN GRABBING COLLECTABLE" << std::endl;
    }
    else{
        board[row][col] = 0;
    }

}

void Level::enableShop(){
    shopEnabled = true;
}

void Level::disableShop(){
    shopEnabled = false;
}

void Level::loadTextures(){

    if(currentLevel == 0){
        textures = LoadTexture("resources/Spelunky_Terrain.png");
    }

}

void Level::unloadtextures(){
    UnloadTexture(textures);
}

std::string Level::getLevelFile(int currentLevel){

    std::string fileName;

    switch(currentLevel){
        case(0):
            fileName = "levels/TEST_LEVEL";
            break;

        default:
            fileName = "levels/TEST_LEVEL";
            break;
    }

    return fileName;
}

void Level::loadLevel(std::string file){
    
    std::ifstream levelFile(file);
    std::string currentLine = "";

    int i = 0;

    while(std::getline(levelFile, currentLine)){
        for(int j = 0; j < 50; ++j){

            if(currentLine.at(j) == 'P'){
                //Want the player starting block to be open space
                //Need to get playerPosition from P in level
                board[i][j] = '0';
            }

            else{
                board[i][j] = currentLine.at(j);
            }
        }
        ++i;
    }
    levelFile.close();

}

void Level::printBoard(){
    for(int i = 0; i < boardHeight; ++i){
        for(int j = 0; j < boardWidth; ++j){
            std::cout << board[i][j];
        }
        std::cout << std::endl;
    }
}

Vector2 Level::getPlayerStartPos(){
    return playerStart;
}