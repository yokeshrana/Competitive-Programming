/*
 * @lc app=leetcode id=141 lang=cpp
 *
 * [141] Linked List Cycle
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
using namespace std;
class Solution
{
public:
  struct ListNode
  {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
  bool hasCycle(ListNode *head)
  {
    ListNode *fast = head, *slow = head;

    while (fast && fast->next)
    {
      fast = fast->next->next;
      slow = slow->next;
      if (fast == slow)
        return true;
    }
    return false;
  }
};
// @lc code=end
