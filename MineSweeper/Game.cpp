#include "Game.h"
#include "include/raylib.h"

Game::Game(int rows, int cols){

    srand(GetTime());

    gridRows = rows;
    gridCols = cols;
    totalGridSquares = gridCols * gridRows;

    std::vector<std::vector<int>> newGrid (gridRows, std::vector<int>(gridCols));

    for(int i = 0; i < gridRows; ++i){
        for(int j = 0; j < gridCols; ++j){
            newGrid.at(i).at(j) = 0;
        }
    }

    bottomGrid = newGrid;
    topGrid = newGrid;

    addMines();
    addNeighbors();

}

void Game::printBottomGrid(){
    for(int i = 0; i < gridRows; ++i){
        for(int j = 0; j < gridCols; ++j){
            std::cout << bottomGrid.at(i).at(j) << " ";
        }

        std::cout << std::endl;

    }
}

void Game::printTopGrid(){
    for(int i = 0; i < gridRows; ++i){
        for(int j = 0; j < gridCols; ++j){
            std::cout <<topGrid.at(i).at(j) << " ";
        }

        std::cout << std::endl;

    }
}

void Game::addMines(){

    int mineSquares = totalGridSquares / 10;
    int minesCreated = 0;

    int randomRow = 0;
    int randomCol = 0;
    
    while(minesCreated < mineSquares){

        randomRow = rand() % gridRows;
        randomCol = rand() % gridCols;

        if(bottomGrid.at(randomRow).at(randomCol) == 0){
            bottomGrid.at(randomRow).at(randomCol) = 9;
            minesCreated++;
            
        }
        
    }

    return;
}

void Game::addNeighbors(){
    
    int neighbors = 0;

    for(int i = 0; i < gridRows; ++i){
        for(int j = 0; j < gridCols; ++j){
            if(bottomGrid.at(i).at(j) != 9){
                neighbors = getNeighbors(i, j);
                bottomGrid.at(i).at(j) = neighbors;
            }
        
        }
    }
}


int  Game::getNeighbors(int currentRow, int currentCol){

    int neighbors = 0;

    if(currentRow > 0 && currentCol > 0){
        if(bottomGrid.at(currentRow - 1).at(currentCol - 1) == 9){neighbors++;}
    }
    
    if(currentRow > 0){
        if(bottomGrid.at(currentRow - 1).at(currentCol) == 9){neighbors++;}
    }

    if(currentRow > 0 && currentCol < gridCols - 1){
        if(bottomGrid.at(currentRow - 1).at(currentCol + 1) == 9){neighbors++;}
    }

    if(currentCol > 0){
        if(bottomGrid.at(currentRow).at(currentCol - 1) == 9){neighbors++;}
    }

    if(currentCol < gridCols - 1){
        if(bottomGrid.at(currentRow).at(currentCol + 1) == 9){neighbors++;}
    }

    if(currentRow < gridRows - 1 && currentCol > 0){
        if(bottomGrid.at(currentRow + 1).at(currentCol - 1) == 9){neighbors++;}
    }

    if(currentRow < gridRows - 1){
        if(bottomGrid.at(currentRow + 1).at(currentCol) == 9){neighbors++;}
    }

    if(currentRow < gridRows - 1 && currentCol < gridCols - 1){
        if(bottomGrid.at(currentRow + 1).at(currentCol + 1) == 9){neighbors++;}
    }

    return neighbors;
}