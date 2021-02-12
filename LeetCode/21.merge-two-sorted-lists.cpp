/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *l3, *tmp;
        ListNode *start = l3;
        bool first = false;
        if (!l1 && !l2)
            return {};
        if (!l1)
            return l2;
        if (!l2)
            return l1;
        while (l1 && l2)
        {
            if (l1->val >= l2->val)
            {
                tmp = new ListNode(l2->val);
                if (!first)
                {
                    l3 = tmp;
                    first = true;
                    start = l3;
                }
                else
                {
                    l3->next = tmp;
                    l3 = l3->next;
                }
                l2 = l2->next;
            }
            else
            {
                tmp = new ListNode(l1->val);
                if (!first)
                {
                    l3 = tmp;
                    first = true;
                    start = l3;
                }
                else
                {
                    l3->next = tmp;
                    l3 = l3->next;
                }
                l1 = l1->next;
            }
            cout << tmp->val << endl;
        }
        if (l1)
            l3->next = l1;
        else
            l3->next = l2;
        return start;
    }
};
// @lc code=end
