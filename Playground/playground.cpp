#include <iostream>
#include <vector>

int main(void){

    int ROWS = 5;
    int COLS = 5;

    std::vector<std::vector<int>> grid (ROWS, std::vector<int>(COLS));

    for(int i = 0; i < ROWS; ++i){
        for(int j = 0; j < COLS; ++j){
            grid.at(i).at(j) = (i * 10) + j;
        }
    }
    

    for(int i = 0; i < ROWS; ++i){
        for(int j = 0; j < COLS; ++j){
            std::cout << grid.at(i).at(j) << " ";
        }

        std::cout << std::endl;
    }

    return 0;
}
