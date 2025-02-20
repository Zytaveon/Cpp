#include "Player.h"

/*
------------------------------------------
------   CONSTRUCTOR   -------------------
------------------------------------------
*/

Player::Player(Vector2 position){
    //Change values based on player size so player is actually in middle of the screen
    position.x = position.x - playerWidth / 2;
    position.y = position.y - playerHeight / 2;

    playerPosition = position;
}

/*
-------------------------------------------
-----   PUBLIC FUNCTIONS   ----------------
-------------------------------------------
*/

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

    printPlayerPosition();

    currentLevel = level;

    if(IsKeyDown(KEY_A)){
        moveLeft();
    }

    // if(IsKeyDown(KEY_S)){
        // moveDown();
    // }

    if(IsKeyDown(KEY_D)){
        moveRight();
    }

    // if(IsKeyDown(KEY_W)){
        // moveUp();
    // }

    if(IsKeyDown(KEY_SPACE) && jumping == false && readyTojump){
        jump();
    }

    if(jumping){
        checkjump();
    }
    
    else{
        checkGravity();
    }

}

/*
-----------------------------------
-----   PRIVATE FUNCTIONS   -------
-----------------------------------
*/

void Player::printPlayerPosition(){
    std::cout << "Player Position -> X: " << playerPosition.x << " Y: " << playerPosition.y << std::endl;
}

//I dont think this will be used later
void Player::moveUp(){
    int movementValue = 4;
    int currentRowTile = ((playerPosition.y - (playerHeight / 2)) - 1) / 50;
    int currentColTile = (playerPosition.x - (playerHeight / 2)) / 50;

    if(currentLevel.getCellValue(currentRowTile, currentColTile) == 1){
        movementValue = 0;
    }

    playerPosition.y -= movementValue;
}

//I dont think this will be used later
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
    int movementValue = movementSpeed;

    /*
    int currentRowTile = (playerPosition.y) / 50;
    int currentColTile = ((playerPosition.x + (playerHeight / 2)) + 1) / 50;

    if(currentLevel.getCellValue(currentRowTile, currentColTile) == 1){
        movementValue = 0;
    }

    playerPosition.x += movementValue;
    */

    std::vector<Vector2> corners;

    Vector2 topCorner ={
        playerPosition.x + (playerWidth / 2),
        playerPosition.y - (playerHeight / 2)
    };

    Vector2 middle = {
        playerPosition.x + (playerWidth / 2),
        playerPosition.y
    };

    Vector2 bottomCorner = {
        playerPosition.x + (playerWidth / 2),
        playerPosition.y + (playerHeight / 2)
    };

    corners.push_back(topCorner);
    corners.push_back(middle);
    corners.push_back(bottomCorner);

    for(int i = 0; i < corners.size(); ++i){
        if(currentLevel.getCellValue(
            (corners.at(i).y) / 50,
            (corners.at(i).x + 1) / 50
        ) == 1){
            movementValue = 0;
        }
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

void Player::jump(){
    jumping = true;
    jumpTime = GetTime();
    readyTojump = false;
}

/*
    When player starts falling it will be slower, but will eventually build up
    to max gravity value. Values might need changed later
*/
void Player::checkGravity(){
    
    //These are the bottom corners, because thats what needs to be checked when falling
    //If either of these are touching a "wall" or "floor", character shouldn't fall

    Vector2 playerLeftCorner = {
        playerPosition.x + playerWidth / 2,
        (playerPosition.y + playerHeight / 2)
    };

    Vector2 playerRightCorner = {
        playerPosition.x - playerWidth / 2,
        (playerPosition.y + playerHeight / 2)
    };

    if(currentLevel.getCellValue((playerLeftCorner.y + 1) / 50, playerLeftCorner.x / 50) == 1){
        currentGravity = 0;
    }

    else if(currentLevel.getCellValue((playerRightCorner.y + 1) / 50, playerRightCorner.x / 50) == 1){
        currentGravity = 0;
    }

    else{
        if(currentGravity == maxGravity){
            currentGravity += 0;
        }
        
        else if(currentGravity + gravityStep > maxGravity){
            currentGravity = maxGravity;
        }

        else{
            currentGravity += gravityStep;
        }
    }

    if(currentGravity == 0){
        readyTojump = true;
    }

    if(currentLevel.getCellValue((playerLeftCorner.y / 50) + 1, playerLeftCorner.x / 50) == 1){
        std::cout << "Hello!" << std::endl;
        if(gravityStep > ((((playerLeftCorner. y / 50) + 1) * 50) - 1) - playerLeftCorner.y){
            currentGravity = ((((playerLeftCorner. y / 50) + 1) * 50)) - playerLeftCorner.y;
        }
    }

    playerPosition.y += currentGravity;

}

void Player::checkjump(){
    if(GetTime() - jumpTime >= jumpDuration){
        jumping = false;
    }

    playerPosition.y -= 4;
}