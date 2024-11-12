#include <iostream>
//#include "cards.h"
#include "deck.h"

int main(){

    std::cout << "Hello there!" << std:: endl;
    DEW::Card card = DEW::Card(1, 1);
    std::cout << card.getCardString() << std::endl;

    DEW::Deck deck = DEW::Deck(1);
    deck.printDeck();
    for(int i = 0; i < 10; ++i){
        std::cout << std::rand() << std::endl;
    }
    return 0;
}