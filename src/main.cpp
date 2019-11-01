#include <iostream>
#include <map>
#include <string>

#include "status-code-finder/status-code-finder.hpp"



int main(int argc, char* argv[]) {
    auto finder = new StatusCodeFinder(); 
    std::cout << finder->get(atoi(argv[1]))->getStatusText() << std::endl;
}