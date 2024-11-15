#include <iostream>
#include <vector>
//#include "cards.h"
#include "deck.h"

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

