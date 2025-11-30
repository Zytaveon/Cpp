#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int main(){
    
    std::string line;
    std::ifstream myFile("input.txt");
    std::stringstream ss;

    if(myFile.is_open()){
        while(std::getline(myFile, line)){
            std::cout << line << std::endl;
            ss.str(line);

            
        }

        myFile.close();
    }

    else{
        std::cout <<"Can't open file" << std::endl;
    }
    return 0;
}