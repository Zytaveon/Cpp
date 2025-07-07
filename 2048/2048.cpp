#include <iostream>
#include "include/raylib.h"
#include "vector"

void printGrid(std::vector<std::vector<int>> grid, int gridRows, int gridCols);
void drawGrid(std::vector<std::vector<int>> grid, int gridRows, int gridCols, int WHeight, int WWidth, Texture2D image);
std::vector<std::vector<int>> addBlockBlankGrid(std::vector<std::vector<int>> grid);

int main(void){

    int windowHeight = 800;
    int windowWidth = 800;

    InitWindow(windowWidth, windowHeight, "2048"); //Creates window
    SetTargetFPS(60); //Set window to 60fps

    Texture2D practiceImage = LoadTexture("assets/Spray2.png");

    int gridRows = 4; // Standard Rows for 2048
    int gridCols = 4; // Standard Cols for 2048

    std::vector<std::vector<int>> grid (4, std::vector<int>(4));

    for(int i = 0; i < gridRows; ++i){
        for(int j = 0; j < gridCols; ++j){
            grid.at(i).at(j) = 0;
        }
    }

    grid = addBlockBlankGrid(grid);

    printGrid(grid, gridRows, gridCols);

    while(!WindowShouldClose()){ //Check for when window is closed or ESC key hit
        BeginDrawing();
            ClearBackground(GRAY);

            
            drawGrid(grid, gridRows, gridCols, windowHeight, windowWidth, practiceImage);
        //Code to be put into window goes here.   

        EndDrawing();
    }
    
    UnloadTexture(practiceImage);
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

void drawGrid(std::vector<std::vector<int>> grid, int gridRows, int gridCols, int WHeight, int WWidth, Texture2D image){
    
    int cellHeight = WHeight / gridRows;
    int cellWidth = WWidth / gridCols;

    for(int i = 0; i < gridRows; ++i){
        for(int j = 0; j < gridCols; ++j){
            if(grid.at(i).at(j) == 0){
                DrawRectangle(cellWidth * j, cellHeight * i, cellWidth - 2, cellHeight - 2, WHITE);           
            }

            if(grid.at(i).at(j) == 1){
                DrawRectangle(cellWidth * j, cellHeight * i, cellWidth - 2, cellHeight - 2, RED);
                DrawTexturePro(image,
                {0, 0, 100, 100},
                {(float)cellWidth * j, (float) cellHeight * i, (float)cellWidth - 2, (float)cellHeight - 2},
                {0,0},
                0,
                WHITE
                );
            }
        }
    }
}

std::vector<std::vector<int>> addBlockBlankGrid(std::vector<std::vector<int>> grid){
    grid.at(2).at(1) = 1;

    return grid;
}