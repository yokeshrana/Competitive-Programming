/*
 * @lc app=leetcode id=61 lang=cpp
 *
 * [61] Rotate List
 */
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
    ListNode *rotateRight(ListNode *head, int k)
    {
        ListNode *curr = head, *end = nullptr;
        if (!head || !head->next)
            return head;
        //Rotate by k means move head by k position in circular fashion
        int l = 1;
        while (curr->next)
        {
            curr = curr->next;
            l++;
        }
        if (k >= l)
            k = k % l;
        l = l - k;
        end = curr;
        curr->next = head;
        curr = curr->next;
        while (l--)
        {
            end = end->next;
            curr = curr->next;
        }
        end->next = nullptr;
        return curr;
    }
};
// @lc code=end
