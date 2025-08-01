#include <iostream>
#include "include/raylib.h"
#include <vector>

enum class Direction : int {
    UP = 0,
    RIGHT = 1,
    DOWN = 2,
    LEFT = 3
};

struct Ant {
    Direction direction;
};

void drawBoard(std::vector<std::vector<int>> grid, int WWidth, int WHeight, int rows, int cols){

    int cellHeight = WHeight / rows;
    int cellWidth = WWidth / cols;

    for(int i = 0; i < (int)grid.size(); ++i){
        for(int j = 0; j < (int)grid.at(0).size(); ++j){
            DrawRectangle(j * cellWidth, i * cellHeight, cellWidth - 2, cellHeight - 2, BLUE);
        }
    }
}

int main(void){

    int WindowWidth = 800;
    int WindowHeight = 800;

    InitWindow(WindowWidth,WindowHeight, "Hello from Raylib Base");
    SetTargetFPS(60);
    int GRIDROWS = 5;
    int GRIDCOLS = 5;

    int num = 0;

    std::vector<std::vector<int>> grid (GRIDROWS, std::vector<int> (GRIDCOLS));

    for(int i = 0; i < GRIDROWS; ++i){
        for(int j = 0; j < GRIDCOLS; ++j){
            grid.at(i).at(j) = num;
            num++;
        }
    }

    // drawBoard(grid, WindowWidth, WindowHeight, GRIDROWS, GRIDCOLS);


    while(!WindowShouldClose()){
        BeginDrawing();

            ClearBackground(WHITE);
        
            drawBoard(grid, WindowWidth, WindowHeight, GRIDROWS, GRIDCOLS);

        EndDrawing();
    }

    CloseWindow(); 

    return 0; 
}
