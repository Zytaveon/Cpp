#ifndef CHARACTER_H
#define CHARACTER_H

#include "include/raylib.h"
#include <iostream>
#include "Level.h"

class Character{
    public:
        //Constructor
        Character();

        void updateCharacter();
        void setPosition(Vector2 newPosition);
        Vector2 getPosition();
        
    protected:

        Vector2 position;
        float characterWidth = 50;
        float characterHeight = 50;
        Level* currentLevel;

        bool jumping = false;
        bool readyTojump = false;


        void moveRight();
        void moveLeft();
        void gravity();
        void jump();
        void checkjump();
        
        
    private:

        float movementSpeed = 4.0;
        float gravityStep = 0.2;
        float maxGravity = 10.0;
        float currentGravity = 0;
        float jumpTime;
        float jumpDuration = 0.3;



};

class Player : public Character{
    public:
        Player();

        void drawPlayer();
        void updatePlayer(Level* level);

    private:

        Color playerColor = GREEN;
        int playerWidth = 50;
        int playerHeight = 50;
        int playerGold = 0;

        void grabCollectable();
};

class Monster : public Character{
    public:

    private:

};

#endif