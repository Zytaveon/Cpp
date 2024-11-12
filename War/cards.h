#include <iostream>
#include <string>

/*
    Class for a single card in a regular deck of cards

    Suits will be ints following
        1 -> Spade
        2 -> Club
        3 -> Diamond
        4 -> Heart

    Ranks will be ints following
        1 -> Ace (If needed)
        2 -> 2
        3 -> 3
        ...
        10 -> 10
        11 -> Jack
        12 -> Queen
        13 -> King
        14 -> Ace (Generally want highest unless necessary to have small Ex. A - 5 straight)

        Might run into issues later with Ace being 1/13 in some cases.
        Might have to have a function that tests if Ace is wanted as big or little?
*/

namespace DEW{

    class Card{
        public:
            Card();
            Card(int rank, int suit);
            int getSuit();
            int getRank();
            std::string getCardString();

        private:
            int suit;
            int rank;
    };
}