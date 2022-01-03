/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int start = 0, end = height.size() - 1;
        int area = 0;
        while (start < end)
        {
            area = max(area, (end - start) * min(height[start], height[end]));
            if (height[start] > height[end])
            {
                end--;
            }
            else
            {
                start++;
            }
        }
        return area;
    }
};
// @lc code=end
