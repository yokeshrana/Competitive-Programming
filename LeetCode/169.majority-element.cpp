/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */
#include "stdc++.h"
using namespace std;
// @lc code=start
class Solution
{
public:
    int count(vector<int> &nums, int element, int low, int high)
    {
        int c = 0;
        for (int i = low; i <= high; i++)
            if (nums[i] == element)
                c++;
        return c;
    }
    int findmajority(vector<int> &nums, int low, int high)
    {
        if (low == high) //Single elemnt case
            return nums[low];
        int mid = (high - low) / 2 + low; 
        int left = findmajority(nums, low, mid);
        int right = findmajority(nums, mid + 1, high);
        if (left == right)
            return left;
        return count(nums, left, low, high) > count(nums, right, low, high) ? left : right;
    }
    int majorityElement(vector<int> &nums)
    {
        int low = 0, high = nums.size() - 1;
        return findmajority(nums, low, high);
    }
};
// @lc code=end
