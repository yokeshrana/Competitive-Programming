/*
 * @lc app=leetcode id=931 lang=cpp
 *
 * [931] Minimum Falling Path Sum
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &A)
    {
        int m = A.size(), n = A[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                int temp = min({i && j ? dp[i - 1][j - 1] : INT_MAX, i ? dp[i - 1][j] : INT_MAX, i == 0 || j == n - 1 ? INT_MAX : dp[i - 1][j + 1]});
                temp = temp == INT_MAX ? 0 : temp;
                dp[i][j] = A[i][j] + temp;
            }
        return *min_element(dp[m - 1].begin(), dp[m - 1].end());
    }
};
// @lc code=end
