#ifndef ITEM_H
#define ITEM_H

enum class ItemType{
    MELEEWEAPON,
    RANGEWEAPON,
    BOOTS, //Could be clothing later?
    POTION
};

class Item{
    public:
        Item(ItemType type, int itemCost);   

        int getCost();

    protected:
        ItemType itemType;
        int cost;

};

class SingleBoots : public Item{
    public:
        SingleBoots() : Item(ItemType::BOOTS, 100){};

    private:
};

#endif