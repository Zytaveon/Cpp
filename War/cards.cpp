#include "cards.h"

//This should create a generic card most likely.
//Could do a random card, but probably better to have a getRandomCard function
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

    return cardString;
}