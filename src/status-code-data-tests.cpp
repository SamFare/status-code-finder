#include <gtest/gtest.h>
#include <random>
#include "status-code-data.hpp"

using namespace testing;

namespace {
    TEST(StatusCodeData, StatDataIsReturnedBasedOnCodeProvided) {
        StatusCodeData* dataWith404 = new StatusCodeData(404, "Not Found");
        StatusCodeData* dataWith200 = new StatusCodeData(200, "OK");
        
        EXPECT_EQ(dataWith404->getStatus(), 404); 
        EXPECT_EQ(dataWith200->getStatus(), 200);
    }

    TEST(StatusCodeData, retreivesDataAssociatedWithStatusCode) {
        StatusCodeData* dataWith404 = new StatusCodeData(404, "Not Found");
        StatusCodeData* dataWith200 = new StatusCodeData(200, "OK");
        
        EXPECT_EQ(dataWith404->getStatusText(), "Not Found"); 
        EXPECT_EQ(dataWith200->getStatusText(), "OK");
    }
}