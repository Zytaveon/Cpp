#include <iostream>
#include "wordSorter.h"
#include <vector>

int main(){
    std::cout << "Hello";
    PRAC::tryMe();
    PRAC::printer printer = PRAC::printer();
    printer.practice();
    DEW::sorter sorter = DEW::sorter("Hello");
    std::cout << sorter.getHasDocument();
    DEW::sorter sort = DEW::sorter();
    std::cout << sort.getHasDocument();
    return 0;
}