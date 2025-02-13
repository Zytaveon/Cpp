#include "Game.h"

Game::Game(int windowHeight, int windowWidth){
    WINDOWWIDTH = windowWidth;
    WINDOWHEIGHT = windowHeight;
}

void Game::runGame(){

    InitWindow(WINDOWWIDTH, WINDOWHEIGHT, "Spelunky");
    SetTargetFPS(60);
    
    Player player = Player({(float)WINDOWWIDTH/2, (float)WINDOWHEIGHT/2});
    Level level = Level();

    Camera2D camera = {0};
    camera.target = player.getPlayerPosition();
    camera.offset = player.getPlayerPosition();
    camera.rotation = 0;
    camera.zoom = 1.0f;

    while(!WindowShouldClose()){
        if(IsKeyDown(KEY_W)){
            player.moveUp();
        }

        if(IsKeyDown(KEY_S)){
            player.moveDown();
        }

        if(IsKeyDown(KEY_D)){
            player.moveRight();
        }

        if(IsKeyDown(KEY_A)){
            player.moveLeft();
        }

        BeginDrawing();
        
        ClearBackground(GRAY);

        BeginMode2D(camera);
        
        level.drawLevel();
        player.drawPlayer();
        camera.target = player.getPlayerPosition();

        EndMode2D();

        EndDrawing();


    }

    CloseWindow();
}