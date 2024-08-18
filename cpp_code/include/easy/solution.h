
#pragma once

#include "solutionbase.h"
#include <any>
#include <cstdlib>
#include <string>
#include <iostream>
#include <mutex>
#include <map>
#include <functional>
#include <vector>
using namespace std;

template<typename T>
void print(T t){
  std::cout << t << std::endl;
}

/**
 * Definition for singly-linked list.
 */
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution_easy : public solutionBase{
 public:

  static Solution_easy& getInstance(){
    std::call_once(onceFlag_, []{
        std::cout << "init singleton, create soulution_easy" << std::endl;
        instance_=new Solution_easy();
        std::atexit(&Solution_easy::destorySingleton);
      });
    return *instance_;
  }

  template <typename Ret, typename... Args>
  void registerFunction(const std::string &name,
                        Ret (Solution_easy::*func)(Args...)) {
    auto lambda = [this, func](Args... args) -> Ret {
      return (this->*func)(args...);
    };
    std::function<Ret(Args...)> lambda_func = lambda;
    funcMap_[name] = lambda_func;
  }

  template <typename Ret, typename... Args>
  Ret callFunction(const std::string &name, Args... args) {
    auto it = funcMap_.find(name);
    if (it != funcMap_.end()) {
      auto func = std::any_cast<std::function<Ret(Args...)>>(it->second);
      return func(args...);
    } else {
      throw std::runtime_error(
          "Function not found or incorrect argument types.");
    }
  }

  /**
  * @brief Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
    Symbol       Value
    I             1
    V             5
    X             10
    L             50
    C             100
    D             500
    M             1000
    For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

    Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

    I can be placed before V (5) and X (10) to make 4 and 9. 
    X can be placed before L (50) and C (100) to make 40 and 90. 
    C can be placed before D (500) and M (1000) to make 400 and 900.
    Given a roman numeral, convert it to an integer.

    Example 1:

    Input: s = "III"
    Output: 3
    Explanation: III = 3.
    Example 2:

    Input: s = "LVIII"
    Output: 58
    Explanation: L = 50, V= 5, III = 3.
    Example 3:

    Input: s = "MCMXCIV"
    Output: 1994
    Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
    
    Constraints:

    1 <= s.length <= 15
    s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M').
    It is guaranteed that s is a valid roman numeral in the range [1, 3999].
  * @param {string} s
  * @return {number}
  **/
  int romanToInt(string s);

  /**
    * Determine whether an integer is a palindrome. An integer is a palindrome
      when it reads the same backward as forward.
    * @brief Given an integer x, return true if x is a
      palindrome, and false otherwise.
      Example 1:
        Input: x = 121
        Output: true
        Explanation: 121 reads as 121 from left to right and from right to left.
      Example 2:
        Input: x = -121
        Output: false
        Explanation: From left to right, it reads -121. From right to left, it becomes
        121-. Therefore it is not a palindrome. 
      Example 3:
        Input: x = 10
        Output: false
        Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
      Constraints:
        -2^31 <= x <= 2^31 - 1
    * @param {number} x
    * @return {boolean}
  **/
  static bool isPalindrome(int x);

  /**
  @brief Write a function to find the longest common prefix string amongst an array of strings.
  If there is no common prefix, return an empty string "".
  Example 1:
    Input: strs = ["flower","flow","flight"]
    Output: "fl"
  Example 2:
    Input: strs = ["dog","racecar","car"]
    Output: ""
  Explanation: There is no common prefix among the input strings.
  Constraints:
  1 <= strs.length <= 200
  0 <= strs[i].length <= 200
  strs[i] consists of only lowercase English letters.
  @param {string[]} strs
  @return {string}
  **/
  std::string longestCommonPrefix(std::vector<std::string>& strs);

  /**
  @brief
  Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
  An input string is valid if:
  Open brackets must be closed by the same type of brackets.
  Open brackets must be closed in the correct order.
  Every close bracket has a corresponding open bracket of the same type.
  Example 1:
    Input: s = "()"
    Output: true
  Example 2:
    Input: s = "()[]{}"
    Output: true
  Example 3:
    Input: s = "(]"
    Output: false
  Constraints:
    1 <= s.length <= 10^4
    s consists of parentheses only '()[]{}'.
  @param {string} s
  @return {bool}
  **/
  bool isValid(std::string s);

  /**
  @brief Merge two sorted linked lists and return it as a sorted list. The list should be made by splicing together the nodes of the first two lists.
        see https://leetcode.com/problems/merge-two-sorted-lists/
  @param {ListNode} l1 {ListNode} l2
  @return {ListNode}
  **/
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);

  /**
  @brief
    Given an array of integers, remove the duplicates in-place such that each
    element appears only once. The relative order of the elements should be kept
    the same. Return the new length of the array. Do not allocate extra space for
    another array, you must do this by modifying the input array in-place with
    O(1) extra memory. see https://leetcode.com/problems/remove-duplicates-from-sorted-array/
  @param {vector<int>} nums
  @return {int}
  **/
  int removeDuplicates(std::vector<int> &nums);

  /**
  @brief
    Implement strStr().
    Return the index of the first occurrence of needle in haystack, or -1 if
    needle is not part of haystack. More details see https://leetcode.com/problems/find-the-index-of-the-occurrence-in-a-string/
  @param {string} haystack {string} needle
  @return {int}
  **/
  int strStr(std::string haystack, std::string needle);

  /**
  @brief
    Given a string s consists of upper/lower-case alphabets and empty space
    characters ' ', return the length of last word in the string. If the last
    word does not exist, return 0. More details see
    https://leetcode.com/problems/length-of-last-word/
  @param {string} s
  @return {int}
  **/
  int lengthOfLastWord(std::string s);

  /**
  @brief
    Given a non-empty array of digits representing a non-negative integer, plus
    one to the integer. The digits are stored such that the most significant
    digit is at the head of the list, and each element in the array contain a
    single digit. You may assume the integer does not contain any leading zero,
    except the number 0 itself. More details see
    https://leetcode.com/problems/plus-one/
  @param{vector<int>} digits
  @return{vector<int>}
  **/
  std::vector<int> plusOne(std::vector<int> &digits);

  /**
  @brief
    Given two binary strings a and b, return their sum as a binary string. More
    details see https://leetcode.com/problems/add-binary/
  @param {string} a {string} b
  @return {string}
  **/
  std::string addBinary(std::string a, std::string b);

private:
  Solution_easy(){
    std::cout << "Solution_easy instance created." << std::endl;
  }
  ~Solution_easy(){
    std::cout << "Solution_easy instance destroyed." << std::endl;
  }

  Solution_easy(const Solution_easy&) = delete;
  Solution_easy(Solution_easy &&) = delete;
  Solution_easy& operator=(Solution_easy &&) = delete;
  Solution_easy& operator=(const Solution_easy&) = delete;

  static void destorySingleton(){
    std::cout << "destory singleton, delete soulution_easy" << std::endl;
    delete instance_;
  }

  std::map<std::string, std::any> funcMap_;

  inline static Solution_easy* instance_ = nullptr;
  inline static std::once_flag onceFlag_;
};