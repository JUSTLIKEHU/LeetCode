#include "easy/solution.h"
#include "utils/common.h"
#include <exception>
#include <string>
#include <vector>

auto &g_solution_easy = Solution_easy::getInstance();
int main(int argc, char **argv) {

  // auto& solution_easy = Solution_easy::getInstance();

  // solution_easy.registerFunction("romanToInt", &Solution_easy::romanToInt);

  // solution_easy.registerStaticFunction("isPalindrome",
  // &Solution_easy::isPalindrome);

  REGISTER_SOLUTION_EASY_FUNCTION(g_solution_easy, romanToInt,
                                  &Solution_easy::romanToInt);
  REGISTER_SOLUTION_EASY_STATIC_FUNCTION(g_solution_easy, isPalindrome,
                                         Solution_easy::isPalindrome);
  REGISTER_SOLUTION_EASY_FUNCTION(g_solution_easy, longestCommonPrefix,
                                  &Solution_easy::longestCommonPrefix);
  REGISTER_SOLUTION_EASY_FUNCTION(g_solution_easy, isValid, &Solution_easy::isValid);

  REGISTER_SOLUTION_EASY_FUNCTION(g_solution_easy, plusOne, &Solution_easy::plusOne);

  try {
    // auto res =
    //     g_solution_easy.callFunction<int, std::string>("romanToInt", "IV");
    // print(res);
    // auto res2 =
    //     g_solution_easy.callStaticFunction<bool, int>("isPalindrome", 100);
    // print(res2);
    // std::vector<std::string> strs = {"flower", "flow", "flight"};
    // auto res3 =
    //     g_solution_easy.callFunction<std::string, std::vector<std::string> &>(
    //         "longestCommonPrefix", strs);
    // print(res3);
    // auto res4 = g_solution_easy.callFunction<bool, std::string>("isValid", "()");
    // print(res4);
    std::vector<int> nums = {9, 8};
    auto res5 = g_solution_easy.callFunction<std::vector<int>, std::vector<int>&>("plusOne", nums);
    for(auto i : res5)
      print(i);

    
  } catch (const std::exception &e) {
    std::cout << e.what() << '\n';
  }
  return 0;
}