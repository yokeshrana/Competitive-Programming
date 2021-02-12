/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int buyat = prices[0], pf = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            buyat = min(buyat, prices[i]); //Buy should be at lower price then sell
            pf = max(pf, prices[i] - buyat);
        }
        return pf;
    }
};
// @lc code=end
