/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 */
#include "stdc++.h"
using namespace std;
// @lc code=start
class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int low = 0, high = nums.size()-1;
        int mid = 0;
        while (low <= high)
        {
            mid = (low + high) / 2;
            if (target == nums[mid])
                return mid;
            else
            {
                if (target > nums[mid])
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
        }
        return max(low,high);
    }
};
// @lc code=end

// 62/62 cases passed (8 ms)
// Your runtime beats 67.08 % of cpp submissions
// Your memory usage beats 67.33 % of cpp submissions (10 MB)

