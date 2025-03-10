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

            if(board[i][j] == static_cast<int>(LevelValues::SPACE)){
                blockColor = WHITE;
            }

            else if(board[i][j] == static_cast<int>(LevelValues::WALL)){
                blockColor = BLACK;
            }

            else if(board[i][j] == static_cast<int>(LevelValues::COLLECTABLE)){
                blockColor = YELLOW;
            }

            else if(board[i][j] == static_cast<int>(LevelValues::SHOP)){
                blockColor = PINK;
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
                playerStart = {(float)j * 50 + 25, (float)i * 50 + 25};
            }

            else{
                board[i][j] = currentLine.at(j);
            }
        }
        ++i;
    }
    levelFile.close();

}

void Level::changeBoardSquare(int row, int col, int newValue){
    if(row >= boardHeight || col >= boardWidth){
        std::cout << "Out of bounds, can't change board value" << std::endl;
    }
    else{
        board[row][col] = newValue;
    }
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