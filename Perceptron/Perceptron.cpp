#include <iostream>
#include "include/raylib.h"
#include "Point.hpp"

int main(void){

    InitWindow(800,800, "Perceptron"); 
    SetTargetFPS(60); 

    Point point = Point();

    while(!WindowShouldClose()){
        BeginDrawing();

        ClearBackground(WHITE);

        EndDrawing();
    }

    CloseWindow(); 

    return 0; 
}
