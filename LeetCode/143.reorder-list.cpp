/*
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
 */
#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// @lc code=start

class Solution
{
public:
    ListNode *getMid(ListNode *head)
    {
        if (head == NULL)
            return NULL;
        ListNode *slow = head, *fast = slow->next;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode *reverse(ListNode *head)
    {
        ListNode *curr = head, *prev = NULL, *next = NULL;
        while (curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    void reorderList(ListNode *head)
    {
        if (!head || !head->next)
            return;
        ListNode *mid = getMid(head);

        mid = reverse(mid->next); //After reversing second half array
        ListNode *curr = head, *tmp;
        while (1)
        {

            tmp = curr->next;
            curr->next = mid;
            if (!mid)
                break;
            mid = mid->next;
            curr = curr->next;
            curr->next = tmp;
            curr = curr->next;
        }

        return;
    }
};
// @lc code=end
int main()
{
    Solution s;
    ListNode *l = new ListNode(5);
    l = new ListNode(4, l);
    l = new ListNode(3, l);
    l = new ListNode(2, l);
    l = new ListNode(1, l);
    s.reorderList(l);
    while (l)
    {
        cout << l->val << " ";
        l = l->next;
    }
    return 0;
}