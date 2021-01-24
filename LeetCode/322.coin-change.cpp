/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int curr_amt = 1; curr_amt <= amount; curr_amt++)
        {
            for (int j = 0; j < coins.size(); j++)
            {
                if (coins[j] <= curr_amt)
                {
                    dp[curr_amt] = min(dp[curr_amt], 1 + dp[curr_amt - coins[j]]);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};
// @lc code=end
