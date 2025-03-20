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

        std::vector<std::vector<int>> grid;

        void createGrid();
        void printGrid();

};

#endif