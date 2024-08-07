#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "easy/solution.h"

using namespace testing;

class SolutionEasyTest : public Test {
protected:
    void SetUp() override {
        // Initialize test data
        solution_ = &Solution_easy::getInstance();
    }

    void TearDown() override {
        // Free test data
    }

    // Define helper functions
    Solution_easy* solution_;
};

TEST_F(SolutionEasyTest, RomanToIntTest) {
    // Test case 1
    {
        std::string input = "III";
        int expected = 3;
        int result = solution_->romanToInt(input);
        EXPECT_EQ(result, expected);
    }

    // Test case 2
    {
        std::string input = "IV";
        int expected = 4;
        int result = solution_->romanToInt(input);
        EXPECT_EQ(result, expected);
    }

    // Test case 3
    {
        std::string input = "IX";
        int expected = 9;
        int result = solution_->romanToInt(input);
        EXPECT_EQ(result, expected);
    }

    // Test case 4
    {
        std::string input = "LVIII";
        int expected = 58;
        int result = solution_->romanToInt(input);
        EXPECT_EQ(result, expected);
    }

    // Test case 5
    {
        std::string input = "MCMXCIV";
        int expected = 1994;
        int result = solution_->romanToInt(input);
        EXPECT_EQ(result, expected);
    }
}

// int main(int argc, char** argv) {
//     InitGoogleMock(&argc, argv);
//     return RUN_ALL_TESTS();
// }