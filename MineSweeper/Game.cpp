#include "Game.h"

Game::Game(int rows, int cols){

    gridRows = rows;
    gridCols = cols;

    std::vector<std::vector<int>> newGrid (gridRows, std::vector<int>(gridCols));

    for(int i = 0; i < gridRows; ++i){
        for(int j = 0; j < gridCols; ++j){
            newGrid.at(i).at(j) = (i * 10) + j;
        }
    }

    bottomGrid = newGrid;
    topGrid = newGrid;

}

void Game::printBottomGrid(){
    for(int i = 0; i < gridRows; ++i){
        for(int j = 0; j < gridCols; ++j){
            std::cout << bottomGrid.at(i).at(j) << " ";
        }

        std::cout << std::endl;
    }
}