#include <iostream>
#include <vector>

/*
    Deck class which creates a deck of (cards) object
*/

namespace DEW{

    class Card{
        public:
            Card();
            Card(int rank, int suit);
            int getSuit();
            int getRank();
            std::string getCardString();
            bool isEqualRank(DEW::Card otherCard);

        private:
            int suit;
            int rank;
            std::string stringy;
    };

    class Deck{

        public:
            Deck(int numOfDecks);
            void setDeck();
            void shuffle();
            DEW::Card getRandomCard();
            DEW::Card getNextCard();
            void addCard(DEW::Card newCard);


            //Test Function
            void printDeck();

        private:
            std::vector<DEW::Card> deck;

            void cutShuffle();
            void washShuffle();
            void riffleshuffle();           


    };
}