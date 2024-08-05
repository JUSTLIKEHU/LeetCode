
#include <gtest/gtest.h>
#include "easy/solution.h"

// 定义一个类来执行测试
class IsPalindromeTest : public ::testing::Test {
protected:
    // 在每个测试开始之前调用的函数，用于设置任何必要的环境或参数
    void SetUp() {}

    // 在每个测试结束之后调用的函数。这里的目的是清理任何在测试中可能创建的对象等。
    void TearDown() {}
};

// 定义一个测试函数来检查正数是否为回文
TEST_F(IsPalindromeTest, PositiveNumber) {
    EXPECT_TRUE(Solution_easy::isPalindrome(121)); // 应返回 true，因为 121 是回文数字
}

// 定义一个测试函数来检查负数是否为回文
TEST_F(IsPalindromeTest, NegativeNumber) {
    EXPECT_FALSE(Solution_easy::isPalindrome(-121)); // 应返回 false，因为 -121 不是回文数字且题目要求 x<0 时返回 false
}

// 定义一个测试函数来检查以零结尾的非零数是否为回文（例如：0 和 10）
TEST_F(IsPalindromeTest, TrailingZeroes) {
    EXPECT_TRUE(Solution_easy::isPalindrome(0)); // 应返回 false，因为题目要求 (x % 10 == 0 && x != 0)，即非零结尾的数应该被排除
    EXPECT_FALSE(Solution_easy::isPalindrome(10)); // 应返回 false，同上
}

// 定义一个测试函数来检查回文数字是否正确识别（例如：12321）
TEST_F(IsPalindromeTest, PalindromeNumber) {
    EXPECT_TRUE(Solution_easy::isPalindrome(12321)); // 应返回 true，因为 12321 是回文数字
}

// 定义一个测试函数来检查非回文数字是否正确识别（例如：456）
TEST_F(IsPalindromeTest, NonPalindromeNumber) {
    EXPECT_FALSE(Solution_easy::isPalindrome(456)); // 应返回 false，因为 456 不是回文数字
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
