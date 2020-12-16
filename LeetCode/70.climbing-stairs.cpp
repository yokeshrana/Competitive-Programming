/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    
    int climb(int n,vector<int> &dp){
        if(n==1) return 1;
        if(n==2) return 2;
        if(n<=0) return 0;
        int a,b;
        if(dp[n-2]==0)
        {
            a=climb(n-2,dp);
            dp[n-2]=a;
        }else
            a=dp[n-2];
        if(dp[n-1]==0)
        {
            b=climb(n-1,dp);
            dp[n-1]=b;
        }else
            b=dp[n-1];
        return a+b;
            
    }
    
    
    int climbStairs(int n) {
        vector<int> dp(n+1,0);
        return climb(n,dp);
    }
};
// @lc code=end

