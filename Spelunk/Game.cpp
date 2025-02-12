#include "Game.h"

Game::Game(int windowHeight, int windowWidth){
    WINDOWWIDTH = windowWidth;
    WINDOWHEIGHT = windowHeight;
}

void Game::runGame(){

    InitWindow(WINDOWWIDTH, WINDOWHEIGHT, "Spelunky");
    SetTargetFPS(60);

    while(!WindowShouldClose()){
        BeginDrawing();
        
        ClearBackground(GRAY);



        EndDrawing();
    }

    CloseWindow();
}