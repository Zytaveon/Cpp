#include <iostream>
#include "include/raylib.h"

/*
    Starting place for using raylib.
    This program should be fully functional and starts off with a black screen.

    When changing the file name, make sure run.ps1 is altered to reflect those changes or will get compile error
    I know the run.ps1 has a lot of stuff in it and I have no idea what it means
    But it makes the program work

    To compile and run this from the terminal, run "./run" without the quotes and it will compile the file
    Then to actually run the file, type "./hello" and it should run and window should be created.

    When done, click the red X in the top right corner or press ESC on the keyboard and the window should close and the program will end.
*/
int main(void){
    std::cout << "Hello from Raylib Base!" << std::endl; 

    InitWindow(250,250, "Hello from Raylib Base"); //Creates window
    SetTargetFPS(60); //Set window to 60fps

    while(!WindowShouldClose()){ //Check for when window is closed or ESC key hit
        BeginDrawing();

        //Code to be put into window goes here.   

        EndDrawing();
    }

    CloseWindow(); //Need to close window when done. 

    return 0; 
}
