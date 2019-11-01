#pragma once
#include <fstream>
#include <nlohmann/json.hpp>
#include <string>
#include <iostream>
#include <exception>

#include "../status-code-not-found-exception/status-code-not-found-exception.hpp"
#include "../status-code-data/status-code-data.hpp"

class StatusCodeFinder {
    public:
        StatusCodeFinder() {
         std::ifstream jsonDataFile("src/status-code-finder/status-codes.json");
         jsonDataFile >> this->statusCodeInformation;
        } 

        StatusCodeData* get(int statusCode) {
            try {
                 auto statusText = this->statusCodeInformation
                                .at(std::to_string(statusCode))
                                .at("description");    
                return new StatusCodeData(statusCode, statusText); 
            } catch (std::exception e) {
                throw StatusCodeNotFoundException();
            }      
        }

    private: 
        nlohmann::json statusCodeInformation;
};