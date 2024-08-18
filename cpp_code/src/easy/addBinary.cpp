#include "easy/solution.h"
#include <algorithm>
#include <bitset>

std::string Solution_easy::addBinary(std::string a, std::string b) {
  // return std::to_string(std::stoi(a, nullptr, 2) + std::stoi(b, nullptr, 2));
  int carry = 0;
  int i = a.size() - 1;
  int j = b.size() - 1;
  std::string res = "";
  while (i >= 0 || j >= 0 || carry) {
    int sum = carry;
    if (i >= 0) {
      sum += a[i] - '0';
      i--;
    }
    if (j >= 0) {
      sum += b[j] - '0';
      j--;
    }
    res = std::to_string(sum % 2) + res;
    carry = sum / 2;
  }
  return res;
}
