#include <gtest/gtest.h>
#include <string>
#include "../status-code-data/status-code-data.hpp"
#include "status-code-pretty-print.hpp"

using namespace testing;

namespace StatusCodePrettyPrintTests {
    TEST(StatusCodePrettyPrintTests, RetrunedMessageContainsStatusCodeString) {
        auto statusCodeData404 = new StatusCodeData(404, "Not Found");
        auto statusCodeData200 = new StatusCodeData(200, "OK");

        auto statusCodePrettyPrinter = new StatusCodePrettyPrint();

        auto prettyPrintedStatus404 = statusCodePrettyPrinter->print(statusCodeData404);
        auto prettyPrintedStatus200 = statusCodePrettyPrinter->print(statusCodeData200);

        EXPECT_NE(prettyPrintedStatus404.find("Status Code:"), std::string::npos);
        EXPECT_NE(prettyPrintedStatus200.find("Status Code:"), std::string::npos);
    }

    TEST(StatusCodePrettyPrintTests, StatusMessagesArePrecededByEmoji) { 
        auto statusCodeData404 = new StatusCodeData(404, "Not Found");
        auto statusCodePrettyPrinter = new StatusCodePrettyPrint();
        auto prettyPrintedStatus404 = statusCodePrettyPrinter->print(statusCodeData404);
        EXPECT_NE(prettyPrintedStatus404.find("👂"), std::string::npos);
    
    }

    TEST(StatusCodePrettyPrintTests, 2XXMessagesAreColouredGreen) { 
        auto statusCodeData200 = new StatusCodeData(200, "OK");
        auto statusCodePrettyPrinter = new StatusCodePrettyPrint();

        auto prettyPrintedStatus200 = statusCodePrettyPrinter->print(statusCodeData200);

        EXPECT_NE(prettyPrintedStatus200.find("\x1B[0;32m200\033[0m"), std::string::npos);
    }

    TEST(StatusCodePrettyPrintTests, 4XXMessagesAreColouredYellow) { 
        auto statusCodeData404 = new StatusCodeData(404, "Not Found");
        auto statusCodePrettyPrinter = new StatusCodePrettyPrint();

        auto prettyPrintedStatus404 = statusCodePrettyPrinter->print(statusCodeData404);
        EXPECT_NE(prettyPrintedStatus404.find("\x1B[0;33m404\033[0m"), std::string::npos);
    }

    TEST(StatusCodePrettyPrintTests, 5XXMessagesAreColouredRed) { 
        auto statusCodeData500 = new StatusCodeData(500, "Internal Server Error");
        auto statusCodePrettyPrinter = new StatusCodePrettyPrint();

        auto prettyPrintedStatus500 = statusCodePrettyPrinter->print(statusCodeData500);
        EXPECT_NE(prettyPrintedStatus500.find("\x1B[0;31m500\033[0m"), std::string::npos);
    }

    TEST(StatusCodePrettyPrintTests, 1XXMessagesAreColouredBlue) { 
        auto statusCodeData100 = new StatusCodeData(100, "Continue");
        auto statusCodePrettyPrinter = new StatusCodePrettyPrint();

        auto prettyPrintedStatus100 = statusCodePrettyPrinter->print(statusCodeData100);
        EXPECT_NE(prettyPrintedStatus100.find("\x1B[0;34m100\033[0m"), std::string::npos);
    }

    TEST(StatusCodePrettyPrintTests, 3XXMessagesAreColouredCyan) { 
        auto statusCodeData300 = new StatusCodeData(300, "Multiple Choices");
        auto statusCodePrettyPrinter = new StatusCodePrettyPrint();

        auto prettyPrintedStatus300 = statusCodePrettyPrinter->print(statusCodeData300);
        EXPECT_NE(prettyPrintedStatus300.find("\x1B[0;36m300\033[0m"), std::string::npos);
    }

    TEST(StatusCodePrettyPrintTests, BreaksStatusTextOnToNewLine) { 
        auto statusCodeData300 = new StatusCodeData(300, "Multiple Choices");
        auto statusCodePrettyPrinter = new StatusCodePrettyPrint();

        auto prettyPrintedStatus300 = statusCodePrettyPrinter->print(statusCodeData300);
        EXPECT_NE(prettyPrintedStatus300.find("\n💬"), std::string::npos);
    }

    TEST(StatusCodePrettyPrintTests, StatusTextStartsWithSpeechBubble) { 
        auto statusCodeData300 = new StatusCodeData(300, "Multiple Choices");
        auto statusCodePrettyPrinter = new StatusCodePrettyPrint();

        auto prettyPrintedStatus300 = statusCodePrettyPrinter->print(statusCodeData300);
        EXPECT_NE(prettyPrintedStatus300.find("💬"), std::string::npos);
    }

    TEST(StatusCodePrettyPrintTests, DisplaysTheTextStatusText) { 
        auto statusCodeData300 = new StatusCodeData(300, "Multiple Choices");
        auto statusCodePrettyPrinter = new StatusCodePrettyPrint();

        auto prettyPrintedStatus300 = statusCodePrettyPrinter->print(statusCodeData300);
        EXPECT_NE(prettyPrintedStatus300.find("Status Text: "), std::string::npos);
    }

    TEST(StatusCodePrettyPrintTests, DisplatsTheStatusTextString) {
        auto statusText = std::to_string(time(NULL)); 
        auto statusCodeData300 = new StatusCodeData(300, statusText);
        auto statusCodePrettyPrinter = new StatusCodePrettyPrint();

        auto prettyPrintedStatus300 = statusCodePrettyPrinter->print(statusCodeData300);
        EXPECT_NE(prettyPrintedStatus300.find(statusText), std::string::npos);
    }
}