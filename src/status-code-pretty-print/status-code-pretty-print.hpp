#include <string>
#include <cmath>
#include "../status-code-data/status-code-data.hpp"

const std::string COLOUR_SELECT_PREFIX = "\x1B[0;";
const std::string COLOUR_RESET = "\033[0m";

class StatusCodePrettyPrint { 
    public: 
        StatusCodePrettyPrint() { }
        std::string print(StatusCodeData* statusCodeData) {
            return "👂 Status Code: " 
                    + COLOUR_SELECT_PREFIX
                    + generateColourCode(statusCodeData)
                    + std::to_string(statusCodeData->getStatus())
                    + COLOUR_RESET;
        }

    private: 
        std::map<int, std::string> statusCodeColours = {
            { 1, "34" }, 
            { 2, "32" },
            { 3, "36" },
            { 4, "33" }, 
            { 5, "31" }, 
        };

        std::string generateColourCode(StatusCodeData* statusCodeData) {
             auto firstNumberOfCode = floor(statusCodeData->getStatus() / 100);  
             return this->statusCodeColours.at(firstNumberOfCode) + "m";
        }
};