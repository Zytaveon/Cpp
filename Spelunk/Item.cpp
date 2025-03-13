#include "Item.h"

Item::Item(ItemType type, int itemCost){
    itemType = type;
    cost = itemCost;
}

int Item::getCost(){
    return cost;
}


