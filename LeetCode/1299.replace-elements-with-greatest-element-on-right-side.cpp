/*
 * @lc app=leetcode id=1299 lang=cpp
 *
 * [1299] Replace Elements with Greatest Element on Right Side
 */

// @lc code=start
class Solution
{
public:
    vector<int> replaceElements(vector<int> &arr)
    {
        int maxuptonow = -1, t;
        for (int i = arr.size() - 1; i >= 0; i--)
        {
            t = arr[i];
            arr[i] = maxuptonow;
            if (t > maxuptonow)
                maxuptonow = t;
        }
        return arr;
    }
};
// @lc code=end
