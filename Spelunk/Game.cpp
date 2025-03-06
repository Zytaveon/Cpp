#include "Game.h"

Game::Game(int windowHeight, int windowWidth){
    WINDOWWIDTH = windowWidth;
    WINDOWHEIGHT = windowHeight;
}

void Game::runGame(){

    InitWindow(WINDOWWIDTH, WINDOWHEIGHT, "Spelunky");
    SetTargetFPS(60);
    
    // Player player = Player();
    Level level = Level(0);
    

    // Camera2D camera = {0};
    // camera.offset = {(float)((WINDOWWIDTH/2) - 25), (float)((WINDOWHEIGHT / 2) - 25)};
    // camera.rotation = 0;
    // camera.zoom = 1.0f;

    while(!WindowShouldClose()){

        BeginDrawing();
        
        ClearBackground(GRAY);
        
        level.drawLevel();

        EndDrawing();


    }

    level.unloadtextures();
    CloseWindow();
}