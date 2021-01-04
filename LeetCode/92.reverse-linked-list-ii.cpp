/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
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
    ListNode *reverse(ListNode *head)
    {
        ListNode *curr = head, *prev = NULL, *next = NULL;
        while (curr)
        {
            cout << "->" << curr->val << " ";
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
    ListNode *reverseBetween(ListNode *head, int m, int n)
    {
        if (!head || !head->next)
            return head;
        ListNode *start = head, *end = head, *prestart = NULL, *afterend = NULL;
        for (int i = 1; i < n; i++)
        {
            if (i < m)
            {
                prestart = start;
                start = start->next;
            }
            end = end->next;
        }
        afterend = end->next;
        end->next = NULL;
        if (prestart)
        {
            prestart->next = reverse(start);
            while (prestart->next != NULL)
                prestart = prestart->next;
            prestart->next = afterend;
        }
        else
        {
            prestart = reverse(start);
            while (prestart->next != NULL)
                prestart = prestart->next;
            prestart->next = afterend;
        }

        return head;
    }
};
// @lc code=end
