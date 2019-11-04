#include <iostream>
#include <map>
#include <string>

#include "status-code-finder/status-code-finder.hpp"
#include "status-code-pretty-print/status-code-pretty-print.hpp"



int main(int argc, char* argv[]) {
    auto finder = new StatusCodeFinder(); 
    auto prettyPrint = new StatusCodePrettyPrint();
    std::cout << prettyPrint->print(finder->get(atoi(argv[1]))) << std::endl;
}