/*
 * @lc app=leetcode id=27 lang=cpp
 *
 * [27] Remove Element
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int prev=0;
        if(nums.empty())return 0;
        for (int j=0;j<nums.size();j++)
            if(nums[j]!=val){
            {
                nums[prev++]=nums[j];
            }
            
        }
        return prev;
    }
};
// @lc code=end

/*

113/113 cases passed (0 ms)
Your runtime beats 100 % of cpp submissions
Your memory usage beats 71.64 % of cpp submissions (9.1 MB)


*/