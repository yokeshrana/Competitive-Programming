/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */
#include "stdc++.h"
using namespace std;
// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        std::sort(nums.begin(),nums.end());
        return nums[nums.size()/2];
    }
};
// @lc code=end

