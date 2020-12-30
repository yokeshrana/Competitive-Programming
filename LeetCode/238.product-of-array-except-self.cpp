/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
    //We solve it in two passes in first pass fill the array with left part multiples prefix
    //in second pass will fill the array with right side multiple siffix multipled with content of left side multiple prefix computed in first step
    vector<int> temp(nums.size(),1);
    for(int i=1;i<nums.size();i++)
    {
        temp[i]=temp[i-1]*nums[i-1];
    }
    // ie if arry is 2,4,6,8 it will store
    //               1 2 8 48
    int rmul=1;
    for(int i=nums.size()-1;i>=0;i--)
    {
        temp[i]*=rmul;
        rmul*=nums[i];
    }
    // ie              192 96 64 48
    return temp;
    }
};
// @lc code=end
