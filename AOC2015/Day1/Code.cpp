#include <iostream>
#include <fstream>
#include <string>

int main(void){

    std::fstream inputFile("input.txt");

    if(!inputFile.is_open()){
        std::cerr << "Error opening the file" << std::endl;
        return 1;
    }

    std::string line;

    while(std::getline(inputFile, line)){
        std::cout << line << std::endl;
    }

    int floor = 0;
    bool basement = true;

    for(int i = 0; i < line.length(); ++i){
        if(line[i] == ')'){--floor;}
        if(line[i] == '('){++floor;}

        if(floor < 0 && basement){
            std::cout <<"Part 2 Answer: " <<  i + 1 << std::endl;
            basement = false;
        }
    }

    
    std::cout <<"Part 1 Answer: " << floor << std::endl;

    inputFile.close();



    return 0;
}