#include "Game.hpp"

Game::Game(){

    std::string Answer;
    std::cout << "New or Returning Player?" << std::endl;
    std::cout << "Type 1 for New, Type 2 for Returning. Answer: ";
    std::cin >> Answer;
    std::cout << std::endl;

    std::cout << "Answer: " << Answer << std::endl;
}