#ifndef SIMULATION_HPP
#define SIMULATION_HPP

#include <iostream>
#include <vector>
#include "include/raylib.h"

class Simulation{
    public:
        Simulation(int windowWidth, int windowHeight, int gridRows, int gridCols);

        void runSimulation();

    private:
        int WINDOWWIDTH;
        int WINDOWHEIGHT;
        int GRIDROWS;
        int GRIDCOLS;
        float boxWidth;
        float boxHeight;

        std::vector<std::vector<int>> grid;
        std::vector<std::vector<int>> oldGrid;

        void drawGrid();
        void addSand(Vector2 mousePosition);

        Vector2 mouseToGridPositon(Vector2 mousePosition);
        void updateGrid();
        void createGrid();
        void printGrid();
        

};

#endif