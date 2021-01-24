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
        int i = 0, j = 0, k = 0;
        for (k = 1; k < m; ++k)
            grid[k][0] = grid[k - 1][0] + grid[k][0];
        for (k = 1; k < n; k++)
            grid[0][k] = grid[0][k - 1] + grid[0][k];
        for (i = 1; i < m; ++i)
            for (j = 1; j < n; ++j)
                grid[i][j] = grid[i][j] + min(grid[i - 1][j], grid[i][j - 1]);
        return grid[m - 1][n - 1];
    }
};
// @lc code=end
