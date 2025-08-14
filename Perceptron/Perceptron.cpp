#include <iostream>
#include "include/raylib.h"

struct Point{
    int x;
    int y;
};

int main(void){
    std::cout << "Hello from Raylib Base!" << std::endl; 

    InitWindow(800,800, "Perceptron"); 
    SetTargetFPS(60); 

    Point newPoint;
    newPoint.x = 1;
    newPoint.y = 2;

    while(!WindowShouldClose()){
        BeginDrawing();

        ClearBackground(WHITE);

        DrawLine(0,0,800,800,BLACK);

        EndDrawing();
    }

    CloseWindow(); 

    return 0; 
}
