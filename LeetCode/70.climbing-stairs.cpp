/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int climb_rec(int n) //O(2^n)
    {
        if (n <= 2)
            return n;
        else
            return climb_rec(n - 1) + climb_rec(n - 2);
    }
    int climb_top_down(vector<int> &dp, int n) //O(n)
    {

        if (n <= 2)
            dp[n] = n;
        if (dp[n] != -1)
            return dp[n];
        else
        {
            return dp[n] = climb_top_down(dp, n - 1) + climb_top_down(dp, n - 2);
        }
    }
    int climb_bottom_up(int n) //O(n)
    {
        vector<int> dp(n + 1, -1);
        dp[1] = 1;
        if (n == 1)
            return dp[1];
        dp[2] = 2;
        for (int i = 3; i <= n; i++)
            dp[i] = dp[i - 1] + dp[i - 2];
        return dp[n];
    }
    int climbStairs(int n)
    {
        //return climb_rec(n);

        //vector<int> dp(n + 1, -1);
        //return climb_top_down(dp, n);

        return climb_bottom_up(n);
    }
};
// @lc code=end
