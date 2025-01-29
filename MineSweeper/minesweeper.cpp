#include <iostream>
#include "include/raylib.h"
#include "Game.h"

int main(void){

    std::cout << "Hello!" << std::endl;

    Game game = Game(10, 10);

    game.printBottomGrid();

    return 0;
}


