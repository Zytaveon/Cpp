g++ spelunk.cpp Game.cpp Level.cpp Character.cpp Shop.cpp -o spelunk -O1 -Wall -Wno-missing-braces -I include/ -L lib/ -lraylib -lopengl32 -lgdi32 -lwinmm