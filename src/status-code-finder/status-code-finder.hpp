#include <fstream>
#include <nlohmann/json.hpp>
#include <string>

class StatusCodeFinder {
    public:
        StatusCodeFinder() {
         std::ifstream jsonDataFile("src/status-code-finder/status-codes.json");
         jsonDataFile >> this->statusCodeInformation;
        } 

        StatusCodeData* get(int statusCode) {
            auto statusText = this->statusCodeInformation
                                .at(std::to_string(statusCode))
                                .at("description");

            return new StatusCodeData(statusCode, statusText);      
        }

    private: 
        nlohmann::json statusCodeInformation;
};