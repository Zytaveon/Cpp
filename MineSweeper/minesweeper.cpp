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

    while(!WindowShouldClose()){
        BeginDrawing();

        if(IsMouseButtonPressed(MOUSE_BUTTON_RIGHT) || IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            game.revealSquares(GetMousePosition());
        }

        game.drawGame(WINDOWWIDTH, WINDOWHEIGHT);
        game.drawNumber();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}


