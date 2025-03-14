#include "Item.h"
/*
    Item
*/
Item::Item(ItemType type, int itemCost){
    itemType = type;
    cost = itemCost;
}

int Item::getCost(){
    return cost;
}

/*
    SingleBoots
*/

void SingleBoots::jump(){

}

void SingleBoots::checkjump(){

}


