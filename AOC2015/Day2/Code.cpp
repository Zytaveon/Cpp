#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main(void){

    std::string testInput = "2x3x4";

    std::vector<std::string> sides = split(testInput, 'x');

    return 0;
}