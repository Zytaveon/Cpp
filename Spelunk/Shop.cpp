#include "Shop.h"
#include "Player.h"
#include "include/raylib.h"

Shop::Shop(Player* player){
    currentPlayer = player;
    activeShop = false;
};

void Shop::drawShop(int windowWidth, int windowHeighth){
    float width = windowHeighth * .8;
    float height = windowWidth * .8;
    float widthBorder = windowWidth * .1;
    float heightBorder = windowHeighth * .1;

    DrawRectanglePro(
        {widthBorder, heightBorder, width, height},
        {0,0},
        0,
        BROWN
    );
}

bool Shop::isShopActive(){
    return activeShop;
}

void Shop::activateShop(){

    //Shouldn't be activating shop if already active.
    if(activeShop){
        std::cout << "Shop was activated when already active" << std::endl;
    }

    activeShop = true;
}

void Shop::disableShop(){

    //Shouldn't be deactivating shop if already deactive.
    if(!activeShop){
        std::cout << "Shop was deactivated when already deactive" << std::endl;
    }

    activeShop = false;
}