#include <iostream>
#include <fstream>
#include "wordSorter.h"
#include <fstream>
#include <vector>

namespace PRAC{

    int tryMe(){
        std::cout << "I work!" << std::endl;
        return 0;
    
    }

    void printer::practice(){
        std::cout << "Hi from practice!" << std::endl;
    }
}

namespace DEW{

    sorter::sorter(){
        hasDocument = false;
    }

    sorter::sorter(std::string newFile){
        hasDocument = true;
    }

    bool sorter::getHasDocument(){
        return sorter::hasDocument;
    }

    std::vector<std::string> sorter::sort(){
        if (!hasDocument){
            std::cout << "No file was given when creating sorter" << std::endl;
        }
        return {};
    }
}