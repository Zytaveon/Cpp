#include <iostream>
#include <vector>
#include "cards.h"

/*
    Deck class which creates a deck of (cards) object
*/

namespace DEW{

    class Deck{

        public:
            Deck(int numOfDecks);
            void setDeck();
            void shuffle();

            //Test Function
            void printDeck();

        private:
            std::vector<DEW::Card> deck;

            void cutShuffle();
            void washShuffle();
            void riffleshuffle();           


    };
}