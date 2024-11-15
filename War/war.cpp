#include <iostream>
//#include "cards.h"
#include "deck.h"

int main(){
    //For shuffles, seemed more chaotic not being inside the function
    srand(time(0));

    //Initial Deck
    DEW::Deck deck = DEW::Deck(1);

    DEW::Deck playerOneActive = DEW::Deck(0);
    DEW::Deck playerOneDormant = DEW::Deck(0);

    DEW::Deck playerTwoActive = DEW::Deck(0);
    DEW::Deck playerTwoDormant = DEW::Deck(0);
    
    bool gameOver = false;

    for(int i = 0; i < 26; ++i){
        playerOneActive.addCard(deck.getNextCard());
        playerTwoActive.addCard(deck.getNextCard());
    }

    

    
}