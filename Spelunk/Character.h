#ifndef CHARACTER_H
#define CHARACTER_H

#include "include/raylib.h"

class Character{
    public:
        //Constructor
        Character();

        void updateCharacter();

        void setPosition(Vector2 newPosition);
        Vector2 getPosition();
        

    private:

        Vector2 position;

};

class Player : public Character{
    public:
        
    private:
};

class Monster : public Character{
    public:

    private:

};

#endif