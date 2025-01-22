#include <iostream>
#include "include/raylib.h"
#include "vector"

class Grid{
public:
    int rows;
    int cols;

    std::vector<std::vector<int>> grid = {{}};

    Grid(const int rows, const int cols){
        this->rows = rows; this->cols = cols;

        std::vector<std::vector<int>> newGrid = {{}};
        std::vector<int> currentLine = {};

        for(int i = 0; i < this->rows; ++i){
            currentLine = {};
            for(int j = 0; j < this->cols; ++j){
                currentLine.push_back((i * 10) + j);
            }

            newGrid.push_back(currentLine);
        }

        return;
    }

    void printGrid(){
        std::cout << this->grid[2][2];
    }
};

int main(void){

    int windowWidth = 500;
    int windowHeight = 500; 

    InitWindow(windowWidth, windowHeight, "Conway's Game of Life");
    SetTargetFPS(60);

    Grid grid = Grid(10,10);

    while(!WindowShouldClose()){
        BeginDrawing();


        EndDrawing();
    }

    CloseWindow(); 

    grid.printGrid();


    return 0; 
}



