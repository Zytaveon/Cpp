#include "Level.h"

//Will get the defualt level currently
Level::Level(){
    currentLevel = 0;
    loadLevel(getLevelFile(currentLevel));
    printBoard();
}

void Level::drawLevel(){

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
            //With single digits automatically converts to ASCII value,
            //so have to minus 0 ASCII value to get actual value
            board[i][j] = currentLine.at(j)  - '0';
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