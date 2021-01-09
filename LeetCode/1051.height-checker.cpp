/*
 * @lc app=leetcode id=1051 lang=cpp
 *
 * [1051] Height Checker
 */

// @lc code=start
class Solution
{
public:
    int heightChecker(vector<int> &heights)
    {
        vector<int> sort_height = heights;
        sort(sort_height.begin(), sort_height.end());
        int count = 0;
        for (int i = 0; i < heights.size(); i++)
        {
            if (heights[i] != sort_height[i])
                count++;
        }
        return count;
    }
};
// @lc code=end
