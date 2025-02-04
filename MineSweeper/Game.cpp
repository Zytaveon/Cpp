#include "Game.h"

Game::Game(int windowWidth, int windowHeight, int rows, int cols){

    srand(GetTime());

    gridRows = rows;
    gridCols = cols;
    totalGridSquares = gridCols * gridRows;

    this->windowHeight = windowHeight;
    this->windowWidth = windowWidth;

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


void Game::drawNumber(){
    DrawText("1", 0, 0, 100, RED);
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

void Game::drawGame(int gridWidth, int gridHeight){

    int boxWidth = gridWidth/ gridCols;
    int boxHeight = gridHeight / gridRows;

    Color boxColor = PURPLE;

    for(int i = 0; i < gridRows; ++i){
        for(int j = 0; j < gridCols; ++j){

            boxColor = getColor(i, j);

            DrawRectangle(j * boxWidth, i * boxHeight, boxWidth - 1, boxHeight - 1, boxColor);
        }
    }
    
    return;
}

struct Color Game::getColor(int row, int col){
    if(isCovered(row, col)){
        return GREEN;
    }
    int bottomValue = bottomGrid.at(row).at(col);

    switch(bottomValue){
        case 0:
            return BROWN;
            break;

        case 1:
            return BLUE;
            break;

        case 2:
            return PURPLE;
            break;
        
        case 3:
            return RED;
            break;
        
        case 4:
            return ORANGE;
            break;
        
        case 5:
            return MAROON;
            break;
        
        case 6:
            return MAROON;
            break;

        case 7:
            return MAROON;
            break;

        case 8:
            return MAROON;
            break;

        case 9:
            return BLACK;
            break;

        default:
            return WHITE;
            break;
    } 
}

void Game::revealSquares(Vector2 mousePosition){
    int rowPosition = mousePosition.y;
    int colPosition = mousePosition.x;

    int currentRow = rowPosition / (windowHeight / gridRows);
    int currentCol = colPosition / (windowWidth / gridCols);

    revealSquaresHelper(currentRow, currentCol);
}

void Game::revealSquaresHelper(int row, int col){
    //Square already revealed, I don't think should do anything
    if(!isCovered(row, col)){
        return;
    }

    //This is a "number tile" and not their job to reveal any other tiles but their own
    if(isCovered(row, col) && bottomGrid.at(row).at(col) != 0 && bottomGrid.at(row).at(col) != 9){
        topGrid.at(row).at(col) = 1;
        return;
    }

    if(isCovered(row, col) && bottomGrid.at(row).at(col) == 0){
        topGrid.at(row).at(col) = 1;

        //Reveal neighbors including "number tiles"
        if(row > 0 && col > 0){
            revealSquaresHelper(row - 1, col -1);
        }
    
        if(row > 0){
            revealSquaresHelper(row - 1, col);
        }

        if(row > 0 && col < gridCols - 1){
            revealSquaresHelper(row - 1, col + 1);
        }

        if(col> 0){
            revealSquaresHelper(row, col - 1);
        }

        if(col < gridCols - 1){
            revealSquaresHelper(row, col + 1);
        }

        if(row < gridRows - 1 && col > 0){
            revealSquaresHelper(row + 1, col - 1);
        }

        if(row < gridRows - 1){
            revealSquaresHelper(row + 1, col);
        }

        if(row < gridRows - 1 && col < gridCols - 1){
            revealSquaresHelper(row + 1, col + 1);
        }
    }
}