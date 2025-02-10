#include "Game.h"

Game::Game(){
    std::cout << "Hi from this game" << std::endl;
}

void Game::runGame(){

    InitWindow(500, 500, "Spelunky");
    SetTargetFPS(60);

    while(!WindowShouldClose()){
        BeginDrawing();
        EndDrawing();
    }

    CloseWindow();
}