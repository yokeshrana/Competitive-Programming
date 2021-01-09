/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 */

// @lc code=start
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int k = 0;
        for (int i = 0; i < nums.size(); i++)
            if (nums[i])
                nums[k++] = nums[i];
        while (k < nums.size())
            nums[k++] = 0;
    }
};
// @lc code=end
