#include <iostream>
#include "include/raylib.h"
#include "Game.h"
#include "vector"

int main(){

    int WindowHeight = 800;
    int WindowWidth = 800;

    int gridRows = 4; //Standard 2048 rows
    int gridCols = 4; //Standard 2048 cols

    InitWindow(WindowWidth, WindowHeight, "2048");
    SetTargetFPS(60);

    Game game = Game(WindowHeight, WindowWidth, gridRows, gridCols);

    while(!WindowShouldClose()){

        BeginDrawing();

            game.drawGame();

        EndDrawing();
    }

    CloseWindow();
}