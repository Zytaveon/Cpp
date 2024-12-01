#include "deck.h"

/*
    Card Class
    ->Creates a single Card given suit and rank
*/

DEW::Card::Card(){

}

DEW::Card::Card(int newRank, int newSuit){
     //suit = newSuit;
     //rank = newRank;

    try{
        if(newRank <= 0 || newRank >= 15){
            throw std::runtime_error("Can't create card, Rank out of bounds");
        }

        if(newSuit <= 0 || newSuit >= 5){
            throw std::runtime_error("Can't create card, Suit out of bounds");
        }
    }
    catch(const std::runtime_error& e){
        std::cerr << "Error: " << e.what() <<std::endl;
    }

    suit = newSuit;
    rank = newRank;
    std::string stringy = getCardString();

}

int DEW::Card::getSuit(){
    return suit;
}

int DEW::Card::getRank(){
    return rank;
}

std::string DEW::Card::getCardString(){
    std::string cardString = "";
        if(rank <= 9 && rank > 0){
            cardString += std::to_string(rank);
        }
        
        else{
            switch(rank){
                case 10:
                    cardString += "T";
                    break;

                case 11:
                    cardString += "J";
                    break;
            
                case 12:
                    cardString += "Q";
                    break;
            
                case 13:
                    cardString += "K";
                    break;
            
                case 14:
                    cardString += "A";
                    break;

                default:
                    std::cout << "Case/Switch Rank Error. Card index out of bounds" << std::endl;
                    cardString += "CaseSwitchRankError";
                    break;
            }
        }

        switch(suit){
            case 1:
                cardString += "S";
                break;
            
            case 2:
                cardString += "C";
                break;

            case 3:
                cardString += "D";
                break;

            case 4:
                cardString += "H";
                break;

            default:
                std::cout << "Case/Switch Suit Error. Card index out of bounds." << std::endl;
                cardString += "CaseSwitchSuitError";
        }

    stringy = cardString;
    return cardString;
}

bool DEW::Card::isEqualRank(DEW::Card otherCard){
    if(rank == otherCard.getRank()){
        return true;
    }
    
    return false;
}

/*
    Deck Class
    ->Creates a standard American Deck of cards 2-A Four suits
*/

DEW::Deck::Deck(int numOfDecks){

    std::vector<DEW::Card> newDeck = {};

    for(int i = 0; i < numOfDecks; ++i){    //Decks
        for(int j  = 1; j < 5; ++j){        //Suits
            for(int k = 2; k < 15; ++k){    //Ranks
                newDeck.push_back(DEW::Card(k, j));
            }
        }
    }

    deck = newDeck;

}

void DEW::Deck::shuffle(){
    washShuffle();
    riffleshuffle();
    cutShuffle();
}

void DEW::Deck::washShuffle(){
    std::vector<DEW::Card> newDeck = {};

    for(int i = 0; i < deck.size(); ++i){

    }
}

void DEW::Deck::riffleshuffle(){

    std::vector<DEW::Card> newDeck = {};

    //I'm worried deck.size() will change in for loop as I take cards away
    //Creating variable just in case. 
    int deckSize = deck.size();

    for(int i = 0; i < deckSize; ++i){
        newDeck.push_back(deck.at(std::rand() % deck.size()));
        
    }

}

void DEW::Deck::cutShuffle(){
      return;
}

void DEW::Deck::printDeck(){
    for(int i = 0; i < deck.size(); ++i){
        std::cout << deck.at(i).getCardString() << " i:" << i << std::endl;
    }
}

DEW::Card DEW::Deck::getRandomCard(){
    srand(time(0));
    return deck.at(std::rand() % deck.size());
}

DEW::Card DEW::Deck::getNextCard(){
    DEW::Card newCard = deck.at(deck.size() - 1);
    deck.pop_back();

    return newCard;
}

void DEW::Deck::addCard(DEW::Card newCard){
    deck.push_back(newCard);
    return;
}
