/*
 * @lc app=leetcode id=485 lang=cpp
 *
 * [485] Max Consecutive Ones
 */

// @lc code=start
class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int max = 0, curr = 0;
        for (auto x : nums)
            if (x == 1)
            {
                curr++;
            }
            else
            {
                if (curr > max)
                    max = curr;
                curr = 0;
            }
        if (curr > max)
            max = curr;
        curr = 0;
        return max;
    }
};
// @lc code=end
