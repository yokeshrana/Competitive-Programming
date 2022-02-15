/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        int len1 = 0;
        int len2 = 0;
        ListNode *tmp = headA;
        while (tmp)
        {
            tmp = tmp->next;
            len1++;
        }
        tmp = headB;
        while (tmp)
        {
            tmp = tmp->next;
            len2++;
        }
        cout << len1 << " " << len2 << endl;
        while (len1 > len2)
        {
            headA = headA->next;
            len1--;
        }
        while (len2 > len1)
        {
            headB = headB->next;
            len2--;
        }
        cout << len1 << " " << len2 << endl;
        // cout << headA->val << " " << headB->val << endl;
        while (headA && headB)
        {
            if (headA == headB)
                return headA;
            headB = headB->next;
            headA = headA->next;
        }
        return nullptr;
    }
};
