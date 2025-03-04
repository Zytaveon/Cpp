#include "Player.h"
#include "Shop.h"

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
    playerGold = 0;
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

void Player::drawGold(){
    return;
}

Vector2 Player::getPlayerPosition(){
    return playerPosition;
}

void Player::updatePlayer(Level* level, Shop* shop){

    // printPlayerPosition();

    currentLevel = level;
    currentShop = shop;
    // currentShop = shop;

    if(IsKeyDown(KEY_A) && !shopEnabled){
        moveLeftPro();
    }

    if(IsKeyDown(KEY_S) && !shopEnabled){
        stopjumo();
    }

    if(IsKeyDown(KEY_D) && !shopEnabled){
        moveRightPro();
        // moveRightPro();
    }

    // if(IsKeyDown(KEY_W)){
        // moveUp();
    // }

    if(IsKeyDown(KEY_SPACE) && jumping == false && readyTojump && !shopEnabled){
        jump();
    }

    if(jumping){
        checkjumpPro();
    }else{
        // checkGravity();
        checkGravityPro();
    }

    checkCollectable();
    checkShop();

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

    if(currentLevel->getCellValue(currentRowTile, currentColTile) == 1){
        movementValue = 0;
    }

    playerPosition.y -= movementValue;
}

//I dont think this will be used later
void Player::moveDown(){
    int movementvalue = 4;

    int currentRowTile = ((playerPosition.y + (playerHeight / 2)) + 1) / 50;
    int currentColTile = (playerPosition.x) / 50;

    if(currentLevel->getCellValue(currentRowTile, currentColTile) == 1){
        movementvalue = 0;
    }

    playerPosition.y += movementvalue;
}

void Player::moveRight(){
    int movementValue = movementSpeed;

    int currentRowTile = (playerPosition.y) / 50;
    int currentColTile = ((playerPosition.x + (playerHeight / 2)) + 1) / 50;

    if(currentLevel->getCellValue(currentRowTile, currentColTile) == 1){
        movementValue = 0;
    }


    playerPosition.x += movementValue;

}

//Written by ChatGPT because was frustrated with clipping and wanted to move on. Sad I know.
void Player::moveRightPro() {
    float nextX = playerPosition.x + movementSpeed; // Predict next X position

    // Get right-side corners (top and bottom)
    Vector2 topRight = {nextX + playerWidth / 2 - 1, playerPosition.y - (playerHeight / 2) + 3};
    Vector2 bottomRight = {nextX + playerWidth / 2 - 1, playerPosition.y + (playerHeight / 2) - 1};

    // Convert to grid coordinates
    int gridX = topRight.x / 50;
    int gridTopY = topRight.y / 50;
    int gridBottomY = bottomRight.y / 50;

    // Check if either right-side corner collides with a wall
    bool collidingWithWall = 
        currentLevel->getCellValue(gridTopY, gridX) == 1 || 
        currentLevel->getCellValue(gridBottomY, gridX) == 1;
    
    bool Collectable = 
        currentLevel->getCellValue(gridTopY, gridX) == 2 || 
        currentLevel->getCellValue(gridBottomY, gridX) == 2;

    if (collidingWithWall) {
        // Stop movement and snap to wall
        playerPosition.x = gridX * 50 - playerWidth / 2;
    } 
    else {
        // Move player normally
        playerPosition.x += movementSpeed;
    }

    // if(Collectable){
        // currentLevel->grabCollectable(gridBottomY, gridX);
    // }

    // std::cout << "Top Right Grid: (" << gridX << ", " << gridTopY << ") Value: " 
        //   << currentLevel.getCellValue(gridTopY, gridX) << std::endl;
    // std::cout << "Bottom Right Grid: (" << gridX << ", " << gridBottomY << ") Value: " 
        //   << currentLevel.getCellValue(gridBottomY, gridX) << std::endl;

}


void Player::moveLeft(){
    int movementValue = 4;

    int currentRowTile = (playerPosition.y - (playerHeight / 2)) / 50;
    int currentColTile = ((playerPosition.x - (playerWidth / 2)) - 1) / 50;

    if(currentLevel->getCellValue(currentRowTile, currentColTile) == 1){
        movementValue = 0;
    }

    playerPosition.x -= movementValue;

    
}

//Written by ChatGPT because was frustrated with clipping and wanted to move on. Sad I know.
void Player::moveLeftPro() {
    float nextX = playerPosition.x - movementSpeed; // Predict next X position

    // Get left-side corners (top and bottom)
    Vector2 topLeft = {nextX - playerWidth / 2 + 1, playerPosition.y - (playerHeight / 2) + 3};
    Vector2 bottomLeft = {nextX - playerWidth / 2 + 1,  playerPosition.y + playerHeight / 2 - 1};

    // Convert to grid coordinates
    int gridX = topLeft.x / 50;
    int gridTopY = topLeft.y / 50;
    int gridBottomY = bottomLeft.y / 50;

    // Check if either left-side corner collides with a wall
    bool collidingWithWall = 
        currentLevel->getCellValue(gridTopY, gridX) == 1 || 
        currentLevel->getCellValue(gridBottomY, gridX) == 1;

    if (collidingWithWall) {
        // Stop movement and snap to wall
        playerPosition.x = (gridX + 1) * 50 + playerWidth / 2;
    } else {
        // Move player normally
        playerPosition.x -= movementSpeed;
    }

    // std::cout << "Top Left Grid: (" << gridX << ", " << gridTopY << ") Value: " 
        //   << currentLevel.getCellValue(gridTopY, gridX) << std::endl;
    // std::cout << "Bottom Left Grid: (" << gridX << ", " << gridBottomY << ") Value: " 
        //   << currentLevel.getCellValue(gridBottomY, gridX) << std::endl;

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
        playerPosition.x - playerWidth / 2,
        playerPosition.y + playerHeight / 2
    };

    Vector2 playerRightCorner = {
        playerPosition.x + playerWidth / 2,
        playerPosition.y + playerHeight / 2
    };

    if(currentLevel->getCellValue((int)(playerLeftCorner.y + 1) / 50, (int)playerLeftCorner.x / 50) == 1){
        currentGravity = 0;
    }

    else if(currentLevel->getCellValue((int)(playerRightCorner.y + 1) / 50, (int)playerRightCorner.x / 50) == 1){
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

    if(currentLevel->getCellValue((int)(playerLeftCorner.y / 50) + 1, (int)playerLeftCorner.x / 50) == 1){
        if(gravityStep > ((((playerLeftCorner.y / 50) + 1) * 50) - 1) - playerLeftCorner.y){
            currentGravity = ((((playerLeftCorner.y / 50) + 1) * 50)) - playerLeftCorner.y;
        }
    }

    //playerPosition.y += currentGravity;

    int currentCell = playerPosition.y / 50;
    int cellBelow = currentCell + 1;
    int cellBelowTopValue = cellBelow * 50;
    int spaceBetween = cellBelowTopValue - playerPosition.y;
    bool cellBelowWall = false;

    if(currentLevel->getCellValue((int)(playerPosition.y / 50) + 1, (int)playerLeftCorner.x) == 1){
        cellBelowWall = true;
    }
    else{
        cellBelowWall = false;
    }

    std::cout << "CurrentCell: " << currentCell << " CellBelow: " << cellBelow << std::endl;
    std::cout << "Value of the top of the below Cell: " << cellBelowTopValue << std::endl;
    std::cout << "Space Between Current and Below (From center of player): " << spaceBetween << std::endl;
    std::cout << "Is the cell below a wall?: " << cellBelowWall << std::endl;

    std::cout << std::endl;

    if(cellBelowWall && spaceBetween < playerHeight/2 + (currentGravity) && currentGravity != 0){
        currentGravity = spaceBetween - (playerHeight / 2);
    }

    playerPosition.y += currentGravity;


}

//Written by ChatGPT because was frustrated with clipping and wanted to move on. Sad I know.
void Player::checkGravityPro(){

    float nextY = playerPosition.y + currentGravity; // Predict next Y position

    // Get bottom corners (left and right)
    Vector2 bottomLeft = {playerPosition.x - playerWidth / 2, nextY + playerHeight / 2};
    Vector2 bottomRight = {playerPosition.x + playerWidth / 2, nextY + playerHeight / 2};

    // Convert to grid coordinates
    int gridLeftX = (bottomLeft.x + 1) / 50;
    int gridRightX = (bottomRight.x - 1) / 50;
    int gridY = bottomLeft.y / 50;

    // Check if either bottom corner collides with the ground
    bool collidingWithGround = 
        currentLevel->getCellValue(gridY, gridLeftX) == 1 || 
        currentLevel->getCellValue(gridY, gridRightX) == 1;

    if (collidingWithGround) {
        currentGravity = 0;  // Stop falling
        readyTojump = true;
        playerPosition.y = gridY * 50 - playerHeight / 2; // Snap to floor
    } else {
        readyTojump = false;
        currentGravity += gravityStep; // Apply gravity normally
        if (currentGravity > maxGravity) currentGravity = maxGravity;
        playerPosition.y += currentGravity; // Move the player down
    }
}


void Player::checkjump(){
    if(GetTime() - jumpTime >= jumpDuration){
        jumping = false;
    }

    playerPosition.y -= 4;
}

void Player::checkjumpPro() {
    if (GetTime() - jumpTime >= jumpDuration) {
        jumping = false;
    }

    // Check if there's a ceiling tile above the player
    Vector2 playerTopLeft = {playerPosition.x - playerWidth / 2, playerPosition.y - playerHeight / 2};
    Vector2 playerTopRight = {playerPosition.x + playerWidth / 2, playerPosition.y - playerHeight / 2};

    bool hitCeiling = (currentLevel->getCellValue((playerTopLeft.y - 1) / 50, playerTopLeft.x / 50) == 1) ||
                      (currentLevel->getCellValue((playerTopRight.y - 1) / 50, playerTopRight.x / 50) == 1);

    if (!hitCeiling) {
        playerPosition.y -= 4;  // Move up only if there’s no ceiling
    } else {
        jumping = false;  // Stop jumping if ceiling is hit
    }
}

void Player::stopjumo(){
    jumping = false;
}

void::Player::checkCollectable(){
    if(currentLevel->getCellValue(playerPosition.y/50, playerPosition.x/50) == 2){
        currentLevel->grabCollectable(playerPosition.y/50, playerPosition.x/50);
        playerGold += 10;
    }
}

void::Player::checkShop(){
    if(IsKeyPressed(KEY_B) && !shopEnabled &&
        currentLevel->getCellValue(playerPosition.y / 50, playerPosition.x / 50) == 3){
            currentShop->activateShop();
            shopEnabled = true;
        }
    
    else if(IsKeyPressed(KEY_B) && shopEnabled){
        currentShop->disableShop();
        shopEnabled = false;
    }
}

int Player::getPlayerGold(){
    return playerGold;
}
