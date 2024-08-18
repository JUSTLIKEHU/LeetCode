#include "easy/solution.h"

int Solution_easy::strStr(std::string haystack, std::string needle) {
  // return haystack.find(needle);
  if (haystack.size() < needle.size()) {
    return -1;
  }
  for (auto i = 0; i < haystack.size(); ++i) {
    if (haystack.substr(i, needle.size()) == needle) {
      return i;
    }
  }
  return -1;
}