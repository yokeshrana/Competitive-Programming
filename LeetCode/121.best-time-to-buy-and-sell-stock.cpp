/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
         if(prices.size()==1||prices.size()==0)return 0;
    int max=prices[prices.size()-1];
    int pf=0;
    for(int i=prices.size()-1;i>=0;i--){
        if(max<prices[i]) max=prices[i];
        if(max-prices[i]>pf)
            pf=max-prices[i];
    }
        return pf;
    }
};
// @lc code=end

