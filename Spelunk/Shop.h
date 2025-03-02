#ifndef SHOP_H
#define SHOP_H

class Player;

class Shop{
    public:

        Shop(Player* player);
        void drawShop(int windowWidth, int windowHeighth);
        bool isShopActive();
        void activateShop();
        void disableShop();

    private:
        Player* currentPlayer;
        bool activeShop;

};

#endif