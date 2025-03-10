#ifndef SHOP_H
#define SHOP_H

#include "Character.H"

class Shop{
    public:

        Shop();
        void drawShop(int windowWidth, int windowHeighth);
        bool isShopActive();
        void activateShop();
        void disableShop();

    private:
        Player* currentPlayer;
        bool activeShop = false;

};

#endif