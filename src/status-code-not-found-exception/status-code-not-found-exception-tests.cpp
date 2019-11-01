#include <gtest/gtest.h>
#include "status-code-not-found-exception.hpp"
#include "../status-code-not-found-exception/status-code-not-found-exception.hpp"

using namespace testing;

namespace StatusCodeNotFoundExceptionTests {
    TEST(StatusCodeNotFoundExceptionTests, ReturnsAMessageSayingStatusCodeNotFound) {
        auto exception = new StatusCodeNotFoundException();
        EXPECT_STREQ(exception->getError(), "Status code not found!");
    }
}