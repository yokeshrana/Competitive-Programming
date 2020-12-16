/*
 * @lc app=leetcode id=876 lang=cpp
 *
 * [876] Middle of the Linked List
 */

// @lc code=start
/**
 Definition for singly-linked list.
 
 */
#include<iostream>
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
    ListNode* middleNode(ListNode* head) {
        ListNode *slow=head,*fast=head;
        while(fast&&fast->next){
            cout<<slow->val<<" "<<fast->val<<"\n";
            slow=slow->next;   
            fast=fast->next->next;
            
        }
        return slow;
    }
};

// @lc code=end

