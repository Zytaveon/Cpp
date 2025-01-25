#include <iostream>
#include "include/raylib.h"
#include "vector"

class Grid{
public:
    int gridRows = 0;
    int gridCols = 0;

    std::vector<std::vector<int>> grid;
    std::vector<std::vector<int>> nextGrid;


    Grid(int rows, int cols){
        gridRows = rows;
        gridCols = cols;

        std::vector<std::vector<int>> newGrid (gridRows, std::vector<int>(gridCols));

        for(int i = 0; i < gridRows; ++i){
            for(int j = 0; j < gridCols; ++j){
                newGrid.at(i).at(j) = rand() % 2;
            }
        }

        grid = newGrid;
        //Doesn't matter values because will get overwritten anyways... I think.
        nextGrid = newGrid;

        return;
    }

    Grid(std::vector<std::vector<int>> newGrid){
        gridRows = newGrid.size();
        gridCols = newGrid[0].size();

        grid = newGrid;
        nextGrid = newGrid;

    }

    void printGrid(){
        
        for(int i = 0; i < gridRows; ++i){
            for(int j = 0; j < gridCols; ++j){
                std::cout << grid.at(i).at(j) << " ";
            }

            std::cout << std::endl;
        }
    }

    /*
        Conway's Game of Life Rules:
            Birth: A dead cell becomes alive if it has exactly three live neighbors
            Death by Isolation: A live cell dies if has one or fewer live neighbors
            Death by Overcrowding: A live cell dies if it has four or more live neighbors
            Survival: A live cell survives if it has two or three live neighbors

    */
    void getNextGrid(){

        int neighbors = 0;
        for(int i = 0; i < gridRows; ++i){
            for(int j = 0; j < gridCols; ++j){
                neighbors = getNeighbors(i, j);

                //Birth
                if(neighbors == 3 && grid.at(i).at(j) == 0){
                    
                    nextGrid.at(i).at(j) = 1;
                }
                
                //Death by Isolation
                else if(neighbors <= 1 && grid.at(i).at(j) == 1){
                    nextGrid.at(i).at(j) = 0;
                }
                //Death by Overcrowding
                else if(neighbors >= 4 && grid.at(i).at(j) == 1){
                    nextGrid.at(i).at(j) = 0;
                }
                //Survival
                else if((neighbors == 2 || neighbors == 3) && (grid.at(i).at(j) == 1)){
                    nextGrid.at(i).at(j) = 1;
                }
                else{
                    nextGrid.at(i).at(j) = 0;
                }

            }
        }

        grid = nextGrid;
    }

    int getNeighbors(int i, int j){
        int neighbors = 0;

        if(i > 0 && j > 0){
            if(grid.at(i - 1).at(j - 1) == 1){neighbors++;}
        }

        if(i > 0){
            if(grid.at(i - 1).at(j) == 1){neighbors++;}
        }

        if(i > 0 && j < gridCols - 1){
            if(grid.at(i - 1).at(j + 1) == 1){neighbors++;}
        }

        if(j > 0){
            if(grid.at(i).at(j - 1) == 1){neighbors++;}
        }

        if(j < gridCols - 1){
            if(grid.at(i).at(j + 1) == 1){neighbors++;}
        }

        if(i < gridRows - 1 && j > 0){
            if(grid.at(i + 1).at(j - 1) == 1){neighbors++;}
        }

        if(i < gridRows - 1){
            if(grid.at(i + 1).at(j) == 1){neighbors++;}
        }

        if(i < gridRows - 1 && j < gridCols - 1){
            if(grid.at(i + 1).at(j + 1) == 1){neighbors++;}
        }

        return neighbors;
    }
};

int main(void){

    int ROWS = 5;
    int COLS = 5;
    
    std::vector<std::vector<int>> userGrid = {
        {0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0}, 
        {0, 1, 0, 1, 0}, 
        {0, 1, 0, 1, 0}, 
        {0, 0, 1, 0, 0}
        };

    //Grid grid = Grid(ROWS, COLS);
    Grid grid = Grid(userGrid);
    std::cout << "Original: " << std::endl;
    grid.printGrid();
    grid.getNextGrid();

    std::cout << std::endl;
    std::cout << "After: " << std::endl;

    grid.printGrid();





    return 0; 
}



