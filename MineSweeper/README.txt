As of 2/8/2025 I think I have made all the progress that I want to in minesweeper

There are still a few things that could be tidied up, so if I were to come back this
    would be the list of things to initially add/modify.

    -> Show how many mines/flags are left
        -?Would require having the game inside of a smaller window so could have some game logic above, like showing # of flags which would match # of mines
        ->If out of flags but not on mines, make player lift flag before being able to add more

    ->Add a lose state.
        ->Currently when you press a mine all the mines show up, but squares can still be clicked and revealed
        ->Would want to make it so squares can't be touched
        ->Add a thumbs down over the screen to show player they lost
        ->Add a restart button

    ->Add a win state.
        ->I perrsonally have never reached this state myself so not 100% sure what should happen
        ->Once all mines have flag over them show they player they won, maybe with a thumbs up over the screen

    ->Clean up code
        ->the header file isn't too bad
        ->Make it so the game can be completely ran from game.cpp except maybe runGame() function
        ->game.cpp is messy.
            -> Saw enums the other day, would probably make this look a lot better
            -> Functions are all over the place. I think it would definitely make more sense to have them match the order they are in as the game.h file
    
    ->Add starting window that adds functionality
        ->Restart
        ->Easy
        ->Meduim
        ->Hard