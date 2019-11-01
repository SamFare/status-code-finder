#pragma once
#include <exception>

class StatusCodeNotFoundException : std::exception {
    public: 
        const char* getError() { 
            return "Status Code Not Found!"; 
        }
};