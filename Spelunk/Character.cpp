#include "Character.h"

/*
    Constructors
*/
Character::Character(){
    return;
}

Player::Player(){
    std::cout << "Player Created" << std::endl;
}

/*
    Character Functions
*/

void Character::updateCharacter(){
    return;
}

void Character::setPosition(Vector2 newPosition){
    position = newPosition;
}

Vector2 Character::getPosition(){
    return position;
}

void Character::moveRight(){

    float nextX = position.x + movementSpeed; // Predict next X position

    // Get right-side corners (top and bottom)
    Vector2 topRight = {nextX + characterWidth / 2 - 1, position.y - (characterHeight / 2) + 3};
    Vector2 bottomRight = {nextX + characterWidth / 2 - 1, position.y + (characterHeight / 2) - 1};

    // Convert to grid coordinates
    int gridX = topRight.x / 50;
    int gridTopY = topRight.y / 50;
    int gridBottomY = bottomRight.y / 50;

    // Check if either right-side corner collides with a wall
    bool collidingWithWall = 
        currentLevel->getCellValue(gridTopY, gridX) == static_cast<int>(LevelValues::WALL) || 
        currentLevel->getCellValue(gridBottomY, gridX) == static_cast<int>(LevelValues::WALL);
    
    if (collidingWithWall) {
        // Stop movement and snap to wall
        position.x = gridX * 50 - characterWidth / 2;
    } 
    else {
        // Move character normally
        position.x += movementSpeed;
    }
}


void Character:: moveLeft(){
    float nextX = position.x - movementSpeed; // Predict next X position

    // Get left-side corners (top and bottom)
    Vector2 topLeft = {nextX - characterWidth / 2 + 1, position.y - (characterHeight / 2) + 3};
    Vector2 bottomLeft = {nextX - characterWidth / 2 + 1,  position.y + characterHeight / 2 - 1};

    // Convert to grid coordinates
    int gridX = topLeft.x / 50;
    int gridTopY = topLeft.y / 50;
    int gridBottomY = bottomLeft.y / 50;

    // Check if either left-side corner collides with a wall
    bool collidingWithWall = 
        currentLevel->getCellValue(gridTopY, gridX) == static_cast<int>(LevelValues::WALL) || 
        currentLevel->getCellValue(gridBottomY, gridX) == static_cast<int>(LevelValues::WALL);

    if (collidingWithWall) {
        // Stop movement and snap to wall
        position.x = (gridX + 1) * 50 + characterWidth / 2;
    } else {
        // Move player normally
        position.x -= movementSpeed;
    }
}

/*
    Player Functions
*/
void Player::drawPlayer(){
    DrawRectanglePro(
        {position.x, position.y, 50, 50},
        {(float)playerWidth/2, (float)playerHeight/2},
        0,
        playerColor
    );

    std::cout << "Player Position -> X: " << position.x << " Y: " << position.y << std::endl;
}

void Player::updatePlayer(Level* level){
    currentLevel = level;

    if(IsKeyDown(KEY_D)){
        moveRight();
    }

    if(IsKeyDown(KEY_A)){
        moveLeft();
    }
}



