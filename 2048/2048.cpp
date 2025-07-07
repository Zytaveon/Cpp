#include <iostream>
#include "include/raylib.h"
#include "vector"

void printGrid(std::vector<std::vector<int>> grid, int gridRows, int gridCols);
void drawGrid(std::vector<std::vector<int>> grid, int gridRows, int gridCols, int WHeight, int WWidth);

int main(void){

    int windowHeight = 800;
    int windowWidth = 800;

    InitWindow(windowWidth, windowHeight, "2048"); //Creates window
    SetTargetFPS(60); //Set window to 60fps

    int gridRows = 4; // Standard Rows for 2048
    int gridCols = 4; // Standard Cols for 2048

    std::vector<std::vector<int>> grid (4, std::vector<int>(4));

    for(int i = 0; i < gridRows; ++i){
        for(int j = 0; j < gridCols; ++j){
            grid.at(i).at(j) = 0;
        }
    }

    printGrid(grid, gridRows, gridCols);

    while(!WindowShouldClose()){ //Check for when window is closed or ESC key hit
        BeginDrawing();
            ClearBackground(GRAY);

            
            drawGrid(grid, gridRows, gridCols, windowHeight, windowWidth);
        //Code to be put into window goes here.   

        EndDrawing();
    }
    
    CloseWindow(); //Need to close window when done. 

    return 0; 
}

void printGrid(std::vector<std::vector<int>> grid, int gridRows, int gridCols){
    for(int i = 0; i < gridRows; ++i){
        for (int j = 0; j < gridCols; ++j){
            std::cout << grid.at(i).at(j) << " ";
        }
        std::cout << std::endl;
    }
}

void drawGrid(std::vector<std::vector<int>> grid, int gridRows, int gridCols, int WHeight, int WWidth){
    
    int cellHeight = WHeight / gridRows;
    int cellWidth = WWidth / gridCols;

    for(int i = 0; i < gridRows; ++i){
        for(int j = 0; j < gridCols; ++j){
            DrawRectangle(cellHeight * i, cellWidth * j, cellWidth - 2, cellHeight - 2, WHITE);           
        }
    }
}
