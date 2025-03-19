#include "simulation.hpp"

int main(void){

    int WINDOWWIDTH = 800;
    int WINDOWHEIGHT = 800;
    int gridRows = 20;
    int gridCols = 20;

    Simulation sim = Simulation(WINDOWWIDTH, WINDOWHEIGHT, gridRows, gridCols);
    sim.runSimulation();
}

