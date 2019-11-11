#pragma once
#include <iterator>
#include <regex>

class ArgumentValidator {
    public: 
        bool validate(int argc, const char* argv[]) {
            if(argc > 1) {
                if(std::regex_match(argv[1], std::regex("[(-|+)|][0-9]+"))) { 
                    return true;
                } 
            }
            return false; 
        }

};