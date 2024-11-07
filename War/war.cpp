#include <iostream>
#include "cards.h"

int main(){

    std::cout << "Hello there!" << std:: endl;
    DEW::Card card = DEW::Card(0, 1);
    std::cout << card.getCardString() << std::endl;
    return 0;
}