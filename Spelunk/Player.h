#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include "include/raylib.h"

class Player{
    public:
        Player(Vector2 position);
        void drawPlayer();
        Vector2 getPlayerPosition();

        void moveUp();
        void moveDown();
        void moveRight();
        void moveLeft();

        //Test struct
        Color spriteColor = GREEN;
    private:
        struct Vector2 playerPosition;
        static constexpr int playerWidth = 50;
        static constexpr int playerHeight = 50;

};

#endif