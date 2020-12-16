/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result=1;
        for(int x:nums)
            result^=x;
        return result^1;
    }
};
// @lc code=end

