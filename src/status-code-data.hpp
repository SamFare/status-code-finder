#include <map>
#include <string>

class StatusCodeData {
    public:  
        StatusCodeData(int statusCode, std::string statusText) {
            this->statusCode = statusCode;
            this->statusText = statusText;
        }

        int getStatus() { 
            return this->statusCode;
        }

        std::string getStatusText() { 
            return this->statusText;
        } 

    private: 
        int statusCode;
        std::string statusText;
};
