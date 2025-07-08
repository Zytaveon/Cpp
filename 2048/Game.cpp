#include "Game.h"

Game::Game(int WinWidth, int WindHeight, int gridRows, int gridCols){
    WindowWidth = WinWidth;
    WindowHeight = WindHeight;

    this->gridCols = gridCols;
    this->gridRows = gridRows;

    cellHeight = WindowHeight / gridRows;
    cellWidth = WindowWidth / gridCols;

    std::vector<std::vector<int>> newGrid (gridRows, std::vector<int>(gridCols));
    
    for(int i = 0; i < this->gridRows; ++i){
        for(int j = 0; j < this->gridCols; ++j){
            newGrid.at(i).at(j) = 0;
        }
    }

    Grid = newGrid;

    printGrid(); //Check if Grid was made correct

    addStartBlocks();
}

//Currently starting blocks aren't random.
void Game::addStartBlocks(){
    Grid.at(0).at(1) = 1;
    Grid.at(2).at(2) = 1;

    printGrid();
}

void Game::printGrid(){
    for(int i = 0; i < gridRows; ++i){
        for(int j = 0; j < gridCols; ++j){
            std::cout << Grid.at(i).at(j) << " ";
        }
        std::cout << std::endl;
    }
}

void Game::drawGame(){

    ClearBackground(GRAY);

    for(int i = 0; i < gridRows; ++i){
        for(int j = 0; j < gridCols; ++j){
            if(Grid.at(i).at(j) == 0){
                DrawRectangle(cellWidth * j, cellHeight * i, cellWidth - 2, cellHeight - 2, WHITE);
            }
            if(Grid.at(i).at(j) == 1){
                DrawRectangle(cellWidth * j, cellHeight * i, cellWidth - 2, cellHeight - 2, RED);
            }
        }
    }

    
}

