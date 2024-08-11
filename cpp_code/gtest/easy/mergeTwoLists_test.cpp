#include <gtest/gtest.h>
#include <vector>
#include "easy/solution.h"

class MergeTwoListsTest : public testing::Test {
 protected:
    
    Solution_easy* solution_;
    void SetUp() override {
      solution_ = &Solution_easy::getInstance();
    }

    void TearDown() override {};
};

void CreateList(ListNode* head, const std::vector<int>& vec) {
  head->val = vec[0];
  for (size_t i = 1; i < vec.size(); ++i) {
    ListNode* node = new ListNode(vec[i]);
    node->next = nullptr;
    head->next = node;
    head = node;
  }
}

void DeleteList(ListNode* head) {
  ListNode* node = head;
  while (node != nullptr) {
    ListNode* tmp = node;
    node = node->next;
    delete tmp;
  }
}

TEST_F(MergeTwoListsTest, TestEmptyList) {
  ListNode *list1 = nullptr;
  ListNode *mergedList = solution_->mergeTwoLists(list1, nullptr);
  ASSERT_EQ(nullptr, mergedList);
}

TEST_F(MergeTwoListsTest, TestOneElementList) {
  ListNode *list1 = new ListNode(1);
  ListNode *list2 = new ListNode(2);
  ListNode *mergedList = solution_->mergeTwoLists(list1, list2);
  ASSERT_EQ(1, mergedList->val);
  ASSERT_EQ(2, mergedList->next->val);
  ASSERT_EQ(nullptr, mergedList->next->next);
}

TEST_F(MergeTwoListsTest, TestSortedLists) {
    std::vector<int> values1{1, 2, 4};
    std::vector<int> values2{1, 3, 4};
    ListNode *list1 = new ListNode(0);
    ListNode *list2 = new ListNode(0);
    CreateList(list1, values1);
    CreateList(list2, values2);

    ListNode *mergedList = solution_->mergeTwoLists(list1, list2);

    auto *expectedHead = new ListNode(1); // Head of merged sorted list
    for (size_t i = 0; expectedHead->next != nullptr && i < values1.size() + values2.size(); ++i) {
        ASSERT_EQ(expectedHead->val, mergedList->val);
        if (i == values1.size()) {
            expectedHead = expectedHead->next;
        }
    }
}

TEST_F(MergeTwoListsTest, TestUnsortedLists) {
    std::vector<int> values1{4, 2, 3};
    std::vector<int> values2{3, 5, 7};
    ListNode *list1 = new ListNode(0);
    ListNode *list2 = new ListNode(0);
    CreateList(list1, values1);
    CreateList(list2, values2);

    ListNode *mergedList = solution_->mergeTwoLists(list1, list2);

    ListNode *expectedHead = new ListNode(3); // Head of merged sorted list
    for (size_t i = 0; expectedHead->next != nullptr && i < values1.size() + values2.size(); ++i) {
        ASSERT_EQ(expectedHead->val, mergedList->val);
        if ((i == values1.size() || i == values2.size()) && expectedHead->next != nullptr) {
            expectedHead = expectedHead->next;
        }
    }
}