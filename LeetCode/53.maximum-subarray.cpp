/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       //Note in max subarray case arises only when some element in b/w becomes negative which causes local sum to be <=zero else it normal one contigous array,so we need checks in b/w whenever it becomes negative .
        if(nums.size()==1)return nums[0];
        int glbmax=INT_MIN;
        int lclmax=0;
        for(int i=0;i<nums.size();i++){          
                lclmax+=nums[i];            
            if(lclmax>glbmax)
                glbmax=lclmax;
             if(lclmax<0)lclmax=0;
        }
        return glbmax;
    }
};
// @lc code=end

