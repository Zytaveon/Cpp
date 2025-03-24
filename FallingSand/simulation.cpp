#include "simulation.hpp"

Simulation::Simulation(int windowWidth, int windowHeight, int gridRows, int gridCols){
    WINDOWWIDTH = windowWidth;
    WINDOWHEIGHT = windowWidth;
    GRIDROWS = gridRows;
    GRIDCOLS = gridCols;

    boxWidth = WINDOWWIDTH / GRIDCOLS;
    boxHeight = WINDOWHEIGHT / GRIDROWS;
}

void Simulation::runSimulation(){

    InitWindow(WINDOWWIDTH, WINDOWHEIGHT, "Falling Sand");
    SetTargetFPS(60);

    createGrid();
    printGrid();

    while(!WindowShouldClose()){
        updateGrid();
        if(IsMouseButtonDown(MOUSE_BUTTON_RIGHT) || IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
            addSand(GetMousePosition());
        }

        BeginDrawing();
        ClearBackground(GRAY);
        drawGrid();

        EndDrawing();

        
    }

    CloseWindow();


}

void Simulation::drawGrid(){

    Color boxColor = PURPLE;

    for(int i = 0; i < GRIDROWS; ++i){
        for(int j = 0; j < GRIDCOLS; ++j){

            if(grid.at(i).at(j) == 0){
                boxColor = WHITE;
            }
            
            if(grid.at(i).at(j) == 1){
                boxColor = BLACK;
            }

            DrawRectanglePro(
                {j * boxWidth, i * boxHeight, boxWidth - 2, boxHeight - 2},
                {0, 0},
                0,
                boxColor
            );
        }
    }
}

void Simulation::addSand(Vector2 mousePosition){
    Vector2 gridPosition = mouseToGridPositon(mousePosition);
    
    if(grid.at(gridPosition.y).at(gridPosition.x) == 0){
        grid.at(gridPosition.y).at(gridPosition.x) = 1;
        std::cout << "X: " << static_cast<int>(gridPosition.x) << ", Y: " << static_cast<int>(gridPosition.y) << std::endl;
    }
}

Vector2 Simulation::mouseToGridPositon(Vector2 mousePosition){
    return {(mousePosition.x / boxWidth),
            (mousePosition.y / boxHeight)};
}

void Simulation::updateGrid(){
    //Reset OldGrid
    for(int i = 0; i < GRIDROWS; ++i){
        for(int j = 0; j < GRIDCOLS; ++j){
            oldGrid.at(i).at(j) = 0;
        }
    }

    //Update oldGrid
    for(int i = 0; i < GRIDROWS - 1; ++i){
        for(int j = 0; j < GRIDCOLS; ++j){
            if(grid.at(i).at(j) == 1 && grid.at(i + 1).at(j) == 0){
                oldGrid.at(i + 1).at(j) = 1;
            }
        }
    }

    for(int j = 0; j < GRIDCOLS; ++j){
        if(oldGrid.at(GRIDROWS - 1).at(j) == 1){
            //Do Nothing
        }
        else{
            oldGrid.at(GRIDROWS - 1).at(j) = grid.at(GRIDROWS - 1).at(j);
        }
    }

    grid = oldGrid;
}

void Simulation::createGrid(){
    std::vector<std::vector<int>> newGrid (GRIDROWS, std::vector<int> (GRIDCOLS));

    for(int i = 0; i < GRIDROWS; ++i){
        for(int j = 0; j < GRIDCOLS; ++j){
            newGrid.at(i).at(j) = 0;
        }
    }

    grid = newGrid;
    oldGrid = newGrid;
}

void Simulation::printGrid(){

    for(int i = 0; i < GRIDROWS; ++i){
        for (int j = 0; j < GRIDCOLS; ++j){
            std::cout << grid.at(i).at(j) << " ";
        }
        
        std::cout << std::endl;
    }
}