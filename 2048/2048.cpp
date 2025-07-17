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

        if(IsKeyPressed(KEY_A) || IsKeyPressed(KEY_LEFT)){ game.shiftLeft(); }

        if(IsKeyPressed(KEY_D) || IsKeyPressed(KEY_RIGHT)){
             game.shiftRight();
             game.gameTester(); }

        if(IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP)){ game.shiftUp(); }

        if(IsKeyPressed(KEY_S) || IsKeyPressed(KEY_DOWN)){ game.shiftDown(); }
    }

    CloseWindow();
}