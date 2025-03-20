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

    createGrid();
    printGrid();

    while(!WindowShouldClose()){
        BeginDrawing();


        ClearBackground(GRAY);
        EndDrawing();
    }

    CloseWindow();


}

void Simulation::createGrid(){
    std::vector<std::vector<int>> newGrid (GRIDROWS, std::vector<int> (GRIDCOLS));

    for(int i = 0; i < GRIDROWS; ++i){
        for(int j = 0; j < GRIDCOLS; ++j){
            newGrid.at(i).at(j) = 0;
        }
    }

    grid = newGrid;
}

void Simulation::printGrid(){

    for(int i = 0; i < GRIDROWS; ++i){
        for (int j = 0; j < GRIDCOLS; ++j){
            std::cout << grid.at(i).at(j) << " ";
        }
        
        std::cout << std::endl;
    }
}