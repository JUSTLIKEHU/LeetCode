#include "easy/solution.h"
#include <exception>

int main(int argc, char** argv) {
  

  auto& solution_easy = Solution_easy::getInstance();
  // print(solution_easy.romanToInt("IV"));

  solution_easy.registerFunction("romanToInt", &Solution_easy::romanToInt);

  solution_easy.registerStaticFunction("isPalindrome", &Solution_easy::isPalindrome);

  try {
    auto res = solution_easy.callFunction<int, std::string>("romanToInt", "IV");
    print(res);
    auto res2 = solution_easy.callStaticFunction<bool, int>( "isPalindrome", 100);
    print(res2);
  } catch (const std::exception &e) {
    std::cout << e.what() << '\n';
  }
  return 0;
}