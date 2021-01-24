/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        dp[0][0] = grid[0][0];
        for (int k = 1; k < m; k++)
            dp[k][0] = dp[k - 1][0] + grid[k][0];
        for (int k = 1; k < n; k++)
            dp[0][k] = dp[0][k - 1] + grid[0][k];
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
        return dp[m - 1][n - 1];
    }
};
// @lc code=end
