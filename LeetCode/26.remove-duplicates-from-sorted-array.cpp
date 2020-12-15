/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */
#include "stdc++.h"
using namespace std;
// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
         int prev=INT_MIN;
         int length=0;
         int size=nums.size();
         for(int i=0;i<size;i++){
            if(nums[i]==prev)
            {
                nums.erase(nums.begin()+i);
                size--;
                i--;
            }
            else
            {
                prev=nums[i];
                length++;
            }
            
         }
         return length;
    }
};
// @lc code=end

