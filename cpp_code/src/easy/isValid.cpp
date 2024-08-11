
#include "easy/solution.h"
#include <stack>
bool Solution_easy::isValid(std::string s) {
  std::stack<char> stk;
  for (int i = 0; i < s.length(); i++) {
    char ch = s.at(i);
    if (ch == '(' || ch == '[' || ch == '{') {
      stk.push(ch);
    } else {
      if (stk.empty() || (ch == ')' && stk.top() != '(') ||
          (ch == ']' && stk.top() != '[') || (ch == '}' && stk.top() != '{')) {
        return false;
      } else {
        stk.pop();
      }
    }
  }
  return stk.empty();
}