#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include "include/raylib.h"
#include "Level.h"
#include <vector>

class Shop;

class Player{
    public:
        Player(Vector2 position);

        void drawPlayer();
        void drawGold();
        Vector2 getPlayerPosition();
        void updatePlayer(Level* level, Shop* shop);
        void checkCollision(Level board);

        //Test variable
        Color spriteColor = GREEN;

    private:
        struct Vector2 playerPosition;
        static constexpr int playerWidth = 50;
        static constexpr int playerHeight = 50;
        Level* currentLevel;
        Shop* currentShop;

        int movementSpeed = 4;

        static constexpr float maxGravity = 20.0;
        float currentGravity = 0;
        float gravityStep = .2;
        bool jumping = false;
        bool readyTojump = false;
        float jumpTime;
        static constexpr float jumpDuration = 0.3;

        bool shopEnabled = false;
        int playerGold;
        
        void printPlayerPosition();

        void moveUp();
        void moveDown();
        void moveRight();
        void moveRightPro();
        void moveLeft();
        void moveLeftPro();
        void jump();
        void checkGravity();
        void checkGravityPro();
        void checkjump();
        void checkjumpPro();
        void stopjumo();

        void checkCollectable();
        void checkShop();
        int getPlayerGold();

};

#endif