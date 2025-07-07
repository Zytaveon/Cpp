#include "simulation.hpp"

int main(void){

    int WINDOWWIDTH = 800;
    int WINDOWHEIGHT = 800;
    int gridRows = 100;
    int gridCols = 100;

    Simulation sim = Simulation(WINDOWWIDTH, WINDOWHEIGHT, gridRows, gridCols);
    sim.runSimulation();
}

