/*
 * @lc app=leetcode id=83 lang=cpp
 *
 * [83] Remove Duplicates from Sorted List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * 
 */
#include "stdc++.h"
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *tmp=head,*t;
        if(!tmp)return head;
        while(tmp->next){
          if(tmp->val==tmp->next->val){
              t=tmp->next;
              tmp->next=tmp->next->next;
              delete t;
          }
            else
              tmp=tmp->next;
            
        }   
        
        return head;
    }
};
// @lc code=end

