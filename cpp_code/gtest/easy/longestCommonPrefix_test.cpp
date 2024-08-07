#include <gtest/gtest.h>
#include <vector>
#include "easy/solution.h"

class LongestCommonPrefixTest : public testing::Test {
 protected:

  void SetUp() override {
    strs1 = {"flower", "flow", "flight"};
    expected1 = "fl";

    strs2 = {"dog", "racecar", "car"};
    expected2 = "";

    strs3 = {"a"};
    expected3 = "a";

    solution_ = &Solution_easy::getInstance();
  };

  void TearDown() override {};

  std::vector<std::string> strs1;
  std::string expected1;

  std::vector<std::string> strs2;
  std::string expected2;

  std::vector<std::string> strs3;
  std::string expected3;

  Solution_easy* solution_;
};

TEST_F(LongestCommonPrefixTest, example1) {
  EXPECT_EQ(expected1, solution_->longestCommonPrefix(strs1));
}

TEST_F(LongestCommonPrefixTest, example2) {
  EXPECT_EQ(expected2, solution_->longestCommonPrefix(strs2));
}

TEST_F(LongestCommonPrefixTest, example3) {
  EXPECT_EQ(expected3, solution_->longestCommonPrefix(strs3));
}