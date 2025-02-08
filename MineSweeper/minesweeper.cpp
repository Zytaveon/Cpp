#include <iostream>
#include "include/raylib.h"
#include "Game.h"

int main(void){

    int WINDOWWIDTH = 500;
    int WINDOWHEIGHT = 500;

    int GRIDCOLS = 10;
    int GRIDROWS = 10;

    Game game = Game(WINDOWWIDTH, WINDOWHEIGHT, GRIDROWS, GRIDCOLS);

    InitWindow(WINDOWWIDTH, WINDOWHEIGHT, "Minesweeper");
    SetTargetFPS(60);

    game.LoadResources();

    while(!WindowShouldClose()){
        BeginDrawing();

        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            game.revealSquares(GetMousePosition());
        }

        game.drawGame(WINDOWWIDTH, WINDOWHEIGHT);

        EndDrawing();
    }

    game.UnloadResources();

    CloseWindow();

    return 0;
}


