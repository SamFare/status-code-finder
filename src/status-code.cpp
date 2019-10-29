#include <iostream>
#include <map>
#include <string>

std::map<int, std::string> statusCodes = {
        {404, "Not Found"}
    };

int main(int argc, char* argv[]) { 
    std::cout << statusCodes.at(404) << std::endl;
    
}