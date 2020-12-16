/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include<vector>
using namespace std;
class Solution {
public:
    struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
    };
    bool isPalindrome(ListNode* head) {
        ListNode *s=head,*f=head;
        if(!head||!head->next)return true;
        if(!head->next->next)
            return head->val==head->next->val?true:false;
        vector<int> v;
        bool odd=false;
        while(f&&f->next){
            v.push_back(s->val);
            s=s->next;
            f=f->next->next;
              if(f&&!f->next)
                odd=true;
          
        }
        int middle=v.size()-1;
        cout<<middle;
        if(odd==true)
            s=s->next;
        while(s){
        if(v[middle--]!=s->val)return false;
            s=s->next;
        }
        return true;
    }
};
// @lc code=end

