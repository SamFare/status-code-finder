#include <gtest/gtest.h>
#include "status-code-finder.hpp"

using namespace testing;

namespace StatusCodeFinderTests{
    TEST(StatusCodeFinder, ReturnsAStatusDataObjectWithStatusCode) {
        auto finder = new StatusCodeFinder();
        auto dataWith404 = finder->get(404);
        auto dataWith200 = finder->get(200);
        
        EXPECT_EQ(dataWith404->getStatus(),404);
        EXPECT_EQ(dataWith200->getStatus(),200);    
    }


    TEST(StatusCodeFinder, ReturnsAStatusDataObjectWithStatusText) {
        auto finder = new StatusCodeFinder();
        auto dataWith404 = finder->get(404);
        auto dataWith200 = finder->get(200);
        
        EXPECT_EQ(dataWith404->getStatusText(),"Not Found");
        EXPECT_EQ(dataWith200->getStatusText(),"OK");    
    }
}