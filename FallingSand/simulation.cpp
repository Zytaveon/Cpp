#include "simulation.hpp"

Simulation::Simulation(int windowWidth, int windowHeight, int gridRows, int gridCols){
    WINDOWWIDTH = windowWidth;
    WINDOWHEIGHT = windowWidth;
    GRIDROWS = gridRows;
    GRIDCOLS = gridCols;
}

void Simulation::runSimulation(){

    InitWindow(WINDOWWIDTH, WINDOWHEIGHT, "Falling Sand");
    SetTargetFPS(60);

    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(GRAY);
        EndDrawing();
    }

    CloseWindow();


}