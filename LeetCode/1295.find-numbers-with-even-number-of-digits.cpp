/*
 * @lc app=leetcode id=1295 lang=cpp
 *
 * [1295] Find Numbers with Even Number of Digits
 */

// @lc code=start
class Solution
{
public:
    bool iseven(int num)
    {
        int digit = 0;
        while (num > 0)
        {
            digit++;
            num /= 10;
        }
        return digit % 2 == 0;
    }
    int findNumbers(vector<int> &nums)
    {
        int result = 0;
        for (auto x : nums)
        {
            if (iseven(x))
                result++;
        }
        return result;
    }
};
// @lc code=end
