#include <gtest/gtest.h>
#include "argument-validator.hpp"


using namespace testing;

namespace ArgumentValidatorTests {
    TEST(ArgumentValidator, returnsFalseWhenArgumentsDoNotExist) {
        auto argumentValidator = new ArgumentValidator();
        const char * argv[] = { "./sc" };
        EXPECT_EQ(argumentValidator->validate(1, argv), false);
    }

    TEST(ArgumentValidator, returnsTrueWhenTheSecoundParamCanBeConvertedToAnInt) {
        auto argumentValidator = new ArgumentValidator();
        const char * argv[] = { "./sc", "404" };
        EXPECT_EQ(argumentValidator->validate(2, argv), true);
    }

    TEST(ArgumentValidator, returnsFalseWhenTheSecoundParamCannotBeConvertedToAnInt) {
        auto argumentValidator = new ArgumentValidator();
        const char * argv[] = { "./sc", "test" };
        EXPECT_EQ(argumentValidator->validate(2, argv), false);
    }
}
