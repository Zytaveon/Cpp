#include <iostream>
#include "include/raylib.h"
#include "vector"

class Grid{
public:
    int rows;
    int cols;

    Grid(const int rows, const int cols){
        this->rows = rows; this->cols = cols;

        int grid[][cols] = {0};

        return;
    }

    void printGrid(){
        std::cout << this->grid[2][2];
    }
};

int main(void){

    int windowWidth = 500;
    int windowHeight = 500; 

    const int ROWS = 5;
    const int COLS = 5;

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



