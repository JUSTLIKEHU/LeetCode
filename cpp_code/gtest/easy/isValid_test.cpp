#include <gtest/gtest.h>
#include "easy/solution.h"

class IsValidTest : public testing::Test {
 protected:
  void SetUp() override {
    solution_ = &Solution_easy::getInstance();
  };

  void TearDown() override {

  };

  Solution_easy* solution_;
};

TEST_F(IsValidTest, test1) {
  std::string s = "()";
  EXPECT_EQ(true, solution_->isValid(s));
}

TEST_F(IsValidTest, test2) {
  std::string s = "()[]{}";
  EXPECT_EQ(true, solution_->isValid(s));
}

TEST_F(IsValidTest, test3) {
  std::string s = "(]";
  EXPECT_EQ(false, solution_->isValid(s));
}

TEST_F(IsValidTest, test4) {
  std::string s = "([)]";
  EXPECT_EQ(false, solution_->isValid(s));
}

TEST_F(IsValidTest, test5) {
  std::string s = "{[]}";
  EXPECT_EQ(true, solution_->isValid(s));
}