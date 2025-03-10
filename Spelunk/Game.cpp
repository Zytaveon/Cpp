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
    Shop shop = Shop();

    Camera2D camera = {0};
    camera.offset = {(float)((WINDOWWIDTH/2) - 25), (float)((WINDOWHEIGHT / 2) - 25)};
    camera.rotation = 0;
    camera.zoom = 1.0f;

    while(!WindowShouldClose()){

        if(level.getCellValue(player.getPosition().y / 50, player.getPosition().x / 50) == static_cast<int>(LevelValues::SHOP) && IsKeyPressed(KEY_B) && !shop.isShopActive()){
            shop.activateShop();
        }
        else if(shop.isShopActive() && IsKeyPressed(KEY_B)){
            shop.disableShop();
        }
        

        BeginDrawing();

        ClearBackground(GRAY);

        if(!shop.isShopActive()){
            player.updatePlayer(&level);
        }
        // player.updatePlayer(&level);
        camera.target = player.getPosition();

        BeginMode2D(camera);
        
        level.drawLevel();
        player.drawPlayer();

        EndMode2D();

        if(shop.isShopActive()){
            shop.drawShop(WINDOWWIDTH, WINDOWHEIGHT);
        }

        EndDrawing();


    }

    level.unloadtextures();
    CloseWindow();
}