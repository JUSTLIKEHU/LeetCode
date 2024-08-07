#include "easy/solution.h"

std::string Solution_easy::longestCommonPrefix(std::vector<std::string> &strs) {
  if (strs.empty()) {
    return "";
  }
  int len = strs[0].length();
  for (int i = 1; i < strs.size() && len > 0; ++i) {
    for (int j = 0; j < len; ++j) {
      if (strs[i][j]!= strs[0][j]) {
        len = j;
        break;
      }
    }
  }
  return std::string(strs[0], 0, len);
}