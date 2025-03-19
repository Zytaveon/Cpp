#ifndef SIMULATION_HPP
#define SIMULATION_HPP

#include <iostream>
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

};

#endif