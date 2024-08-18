#include "easy/solution.h"

int Solution_easy::lengthOfLastWord(std::string str) {
  // return std::distance(str.rbegin(), std::find_if(str.rbegin(), str.rend(),
  //                                                 [](char c) { return c != ' '; }));
  for (int i = (int)str.size() -1; i >=0 ; --i){
    if (str[i] != ' '){
      int j = i;
      while (j >= 0 && str[j] != ' '){
        --j;
      }
      return i - j;
    }
  }
  return  0;
}