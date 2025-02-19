#include "Game.h"

Game::Game(int windowHeight, int windowWidth){
    WINDOWWIDTH = windowWidth;
    WINDOWHEIGHT = windowHeight;
}

void Game::runGame(){

    InitWindow(WINDOWWIDTH, WINDOWHEIGHT, "Spelunky");
    SetTargetFPS(60);
    
    Player player = Player({100, 100});
    Level level = Level();

    Camera2D camera = {0};
    camera.target = player.getPlayerPosition();
    camera.offset = {(float)((WINDOWWIDTH/2) - 25), (float)((WINDOWHEIGHT / 2) - 25)};
    camera.rotation = 0;
    camera.zoom = 1.0f;

    while(!WindowShouldClose()){


        player.updatePlayer(level);

        BeginDrawing();
        
        ClearBackground(GRAY);

        BeginMode2D(camera);
        
        level.drawLevel();
        player.drawPlayer();
        camera.target = player.getPlayerPosition();

        EndMode2D();

        EndDrawing();


    }
    level.unloadtextures();
    CloseWindow();
}