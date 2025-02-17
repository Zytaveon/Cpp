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
        {playerWidth/2,playerHeight/2},
        0,
        spriteColor
    );
}

Vector2 Player::getPlayerPosition(){
    return playerPosition;
}

void Player::updatePlayer(Level level){

    currentLevel = level;

    if(IsKeyDown(KEY_A)){
        moveLeft();
    }

    if(IsKeyDown(KEY_S)){
        moveDown();
    }

    if(IsKeyDown(KEY_D)){
        moveRight();
    }

    if(IsKeyDown(KEY_W)){
        moveUp();
    }
}

void Player::moveUp(){
    int movementValue = 4;
    int currentRowTile = ((playerPosition.y - (playerHeight / 2)) - 1) / 50;
    int currentColTile = (playerPosition.x - (playerHeight / 2)) / 50;

    if(currentLevel.getCellValue(currentRowTile, currentColTile) == 1){
        movementValue = 0;
    }

    playerPosition.y -= movementValue;
}

void Player::moveDown(){
    int movementvalue = 4;

    int currentRowTile = ((playerPosition.y + (playerHeight / 2)) + 1) / 50;
    int currentColTile = (playerPosition.x) / 50;

    if(currentLevel.getCellValue(currentRowTile, currentColTile) == 1){
        movementvalue = 0;
    }

    playerPosition.y += movementvalue;
}

void Player::moveRight(){
    int movementValue = 4;

    int currentRowTile = (playerPosition.y) / 50;
    int currentColTile = ((playerPosition.x + (playerHeight / 2)) + 1) / 50;

    if(currentLevel.getCellValue(currentRowTile, currentColTile) == 1){
        movementValue = 0;
    }

    playerPosition.x += movementValue;
}

void Player::moveLeft(){
    int movementValue = 4;

    int currentRowTile = (playerPosition.y - (playerHeight / 2)) / 50;
    int currentColTile = ((playerPosition.x - (playerWidth / 2)) - 1) / 50;

    if(currentLevel.getCellValue(currentRowTile, currentColTile) == 1){
        movementValue = 0;
    }

    playerPosition.x -= movementValue;
}

void Player::checkCollision(Level board){
    bool collision = false;

    //Check Collisions
    std::cout << "Player Position -> X: " << playerPosition.x << " Y: " << playerPosition.y << std::endl;

    int currentRowTile = playerPosition.y / 50;
    int currentColTile = playerPosition.x / 50;

    if(board.getCellValue(currentRowTile, currentColTile) == 1){
        collision = true;
    }

    //Change color of sprite depending on collision value
    if(collision){
        spriteColor = RED;
    }
    else{
        spriteColor = GREEN;
    }
}