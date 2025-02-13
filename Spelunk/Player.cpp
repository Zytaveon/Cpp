#include "Player.h"

Player::Player(Vector2 position){
    //Change values based on player size so player is actually in middle of the screen
    position.x = position.x - playerWidth / 2;
    position.y = position.y - playerHeight / 2;

    playerPosition = position;
}

void Player::drawPlayer(){
    DrawRectanglePro(
        {playerPosition.x, playerPosition.y, 50, 50},
        {0,0},
        0,
        spriteColor
    );
}

Vector2 Player::getPlayerPosition(){
    return playerPosition;
}

void Player::moveUp(){
    playerPosition.y -= 4;
    spriteColor = RED;
}

void Player::moveDown(){
    playerPosition.y += 4;
}

void Player::moveRight(){
    playerPosition.x += 4;
}

void Player::moveLeft(){
    playerPosition.x -= 4;
}