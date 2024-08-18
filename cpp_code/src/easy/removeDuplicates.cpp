#include "easy/solution.h"

int Solution_easy::removeDuplicates(vector<int>& nums) {
  if (nums.empty()) return 0;
  int i = 1, j = 1;
  while (j < nums.size()){
    if (nums[i-1]!= nums[j]) {
      nums[i++] = nums[j];
    }
    ++j;
  }
  return i;
}