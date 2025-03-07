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
        float characterWidth = 25;
        float characterHeight = 25;
        Level* currentLevel;

        void moveRight();
        void moveLeft();
        
        
    private:

        float movementSpeed = 4.0;


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
};

class Monster : public Character{
    public:

    private:

};

#endif