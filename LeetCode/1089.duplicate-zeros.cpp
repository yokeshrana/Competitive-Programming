/*
 * @lc app=leetcode id=1089 lang=cpp
 *
 * [1089] Duplicate Zeros
 */

// @lc code=start
class Solution
{
public:
    void duplicateZeros(vector<int> &arr)
    {
        int zeroes = 0, i = 0, l = arr.size();
        for (i = 0; i < l - zeroes; i++)
        {
            if (arr[i] == 0)
                zeroes++;
        }
        for (i = i - 1; zeroes > 0; --i)
        {
            if (i < l - zeroes)
                arr[i + zeroes] = arr[i];
            if (arr[i] == 0)
                arr[i + --zeroes] = arr[i];
        }
    }
};
// @lc code=end
