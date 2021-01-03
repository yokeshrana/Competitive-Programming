/*
 * @lc app=leetcode id=148 lang=cpp
 *
 * [148] Sort List
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
    ListNode *sortList(ListNode *head)
    {
        ListNode *temp = head;
        if (head == NULL || head->next == NULL)
            return head;
        multimap<int, ListNode *> mp;

        while (temp)
        {
            mp.insert(make_pair(temp->val, temp));
            temp = temp->next;
        }
        auto j = mp.begin();
        for (auto i = mp.begin(); i != mp.end(); i++)
        {
            if (i == mp.begin())
                continue;
            (*j).second->next = (*i).second;
            j++;
        }
        (*j).second->next = NULL;
        head = (*mp.begin()).second;
        mp.clear();
        return head;
    }
};
// @lc code=end
