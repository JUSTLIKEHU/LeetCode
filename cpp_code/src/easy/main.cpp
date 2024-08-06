#include "easy/solution.h"
#include "utils/common.h"
#include <exception>

auto& g_solution_easy = Solution_easy::getInstance();
int main(int argc, char** argv) {
  

  // auto& solution_easy = Solution_easy::getInstance();

  // solution_easy.registerFunction("romanToInt", &Solution_easy::romanToInt);

  // solution_easy.registerStaticFunction("isPalindrome", &Solution_easy::isPalindrome);

  REGISTER_SOLUTION_EASY_FUNCTION(g_solution_easy, romanToInt, &Solution_easy::romanToInt);
  REGISTER_SOLUTION_EASY_STATIC_FUNCTION(g_solution_easy, isPalindrome, Solution_easy::isPalindrome);

  try {
    auto res = g_solution_easy.callFunction<int, std::string>("romanToInt", "IV");
    print(res);
    auto res2 = g_solution_easy.callStaticFunction<bool, int>( "isPalindrome", 100);
    print(res2);
  } catch (const std::exception &e) {
    std::cout << e.what() << '\n';
  }
  return 0;
}