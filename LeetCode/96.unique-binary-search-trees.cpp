/*
 * @lc app=leetcode id=96 lang=cpp
 *
 * [96] Unique Binary Search Trees
 */

// @lc code=start
class Solution
{
public:
    long long findBC(int n, int k)
    {
        long long res = 1;
        if (n - k < k)
            k = n - k;
        for (int i = 0; i < k; i++)
        {
            res *= (n - i);
            res /= (i + 1);
        }
        return res;
    }
    int numTrees(int n)
    {
        return (int)(findBC(2 * n, n) / (n + 1));
    }
};
// @lc code=end
