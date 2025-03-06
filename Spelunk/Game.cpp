#include "Game.h"

Game::Game(int windowHeight, int windowWidth){
    WINDOWWIDTH = windowWidth;
    WINDOWHEIGHT = windowHeight;
}

void Game::runGame(){

    InitWindow(WINDOWWIDTH, WINDOWHEIGHT, "Spelunky");
    SetTargetFPS(60);
    
    Level level = Level(0);
    Player player = Player();
    player.setPosition(level.getPlayerStartPos());

    Camera2D camera = {0};
    camera.offset = {(float)((WINDOWWIDTH/2) - 25), (float)((WINDOWHEIGHT / 2) - 25)};
    camera.rotation = 0;
    camera.zoom = 1.0f;

    while(!WindowShouldClose()){

        BeginDrawing();

        camera.target = player.getPosition();
        BeginMode2D(camera);
        ClearBackground(GRAY);
        
        level.drawLevel();
        EndMode2D();
        EndDrawing();


    }

    level.unloadtextures();
    CloseWindow();
}