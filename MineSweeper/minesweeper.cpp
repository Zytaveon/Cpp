#include <iostream>
#include "include/raylib.h"

int main(void){

    Image desertBackground = LoadImage("resources/desertBackground.jpg");


   std::cout << IsImageValid(desertBackground) << std::endl; 
    
    int WINDOWWIDTH = 800;
    int WINDOWHEIGHT = 800;

    InitWindow(WINDOWWIDTH, WINDOWHEIGHT, "Minesweeper");

    Image copy = ImageCopy(desertBackground);

    Rectangle cropRec = {100, 100, 800, 800};

    ImageCrop(&copy, cropRec);

    Texture2D text = LoadTextureFromImage(copy);

    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(RED);

        DrawTexture(text, 0, 0, WHITE);
        EndDrawing();
    }



    UnloadImage(desertBackground);
    CloseWindow();
    

    return 0;
}


