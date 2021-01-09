/*
 * @lc app=leetcode id=414 lang=cpp
 *
 * [414] Third Maximum Number
 */

// @lc code=start
class Solution
{
public:
    int thirdMax(vector<int> &nums)
    {
        long long max1 = (long long)-1e10;
        long long max2 = max1;
        long long max3 = max1;
        for (auto x : nums)
        {
            if (x == max1 || x == max2 || x == max3)
                continue;
            if (x > max1)
            {
                max3 = max2;
                max2 = max1;
                max1 = x;
            }
            else if (x > max2)
            {
                max3 = max2;
                max2 = x;
            }
            else if (x > max3)
            {
                max3 = x;
            }
        }
        return max3 != -1e10l ? max3 : max1;
    }
};
// @lc code=end
