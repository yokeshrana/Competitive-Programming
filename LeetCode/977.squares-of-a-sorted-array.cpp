/*
 * @lc app=leetcode id=977 lang=cpp
 *
 * [977] Squares of a Sorted Array
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        vector<int> x(nums.size()); //Key is here to fill from end
        int k = nums.size() - 1;
        int i = 0, j = k;
        while (i <= j)
        {
            if (abs(nums[i]) > abs(nums[j]))
            {
                x[k--] = nums[i] * nums[i];
                i++;
            }
            else
            {
                x[k--] = nums[j] * nums[j];
                j--;
            }
        }
        return x;
    }
};
// @lc code=end
