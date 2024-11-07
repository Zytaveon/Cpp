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

        private:
            std::vector<DEW::Card> createDeck();


    };
}