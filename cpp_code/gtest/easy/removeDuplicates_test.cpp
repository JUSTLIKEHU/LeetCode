#include <gtest/gtest.h>
#include <vector>
#include "easy/solution.h"

class RemoveDuplicatesTest : public testing::Test {
 protected:
  Solution_easy* solution_;
  std::vector<int> nums1;
  std::vector<int> nums2;

  void SetUp() override {
    solution_ = &Solution_easy::getInstance();
    nums1 = {1, 1, 2};
    nums2 = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
  }

  void TearDown() override {}
};

TEST_F(RemoveDuplicatesTest, aabc) {
  EXPECT_EQ(solution_->removeDuplicates(nums1), 2);
}

TEST_F(RemoveDuplicatesTest, aabbbccdde) {
  EXPECT_EQ(solution_->removeDuplicates(nums2), 5);
} 