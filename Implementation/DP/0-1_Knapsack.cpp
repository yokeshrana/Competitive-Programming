#include <bits/stdc++.h>
using namespace std;
int knapsack_recur(vector<int> &wt, vector<int> &val, int W, int n) // O(2^n)
{
    //Base condition either knapsack is empty or we dont have anything left to fill
    if (n == 0 || W == 0)
        return 0;

    //Current item Wt we are filling have to be lesser than the current capacity
    if (wt[n - 1] <= W)
    {
        return max(val[n - 1] + knapsack_recur(wt, val, W - wt[n - 1], n - 1), /*Including the current val wt */
                   knapsack_recur(wt, val, W, n - 1));                         /* Excluding the current val wt */
    }
    return knapsack_recur(wt, val, W, n - 1);
}
const int n = 4;
const int W = 50;
vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));           //Why n and W as these are only the thing that is changing in the recusive implementation
int knapsack_dp(vector<int> &wt, vector<int> &val, int W, int n) //O(n*W)
{
    if (n == 0 || W == 0)
        return dp[n][W] = 0;
    if (dp[n][W] != -1) //If we have already computed value then we can return the value
        return dp[n][W];
    //Current item Wt we are filling have to be lesser than the current capacity
    if (wt[n - 1] <= W)
    {
        return dp[n][W] = max(val[n - 1] + knapsack_dp(wt, val, W - wt[n - 1], n - 1), /*Including the current val wt */
                              knapsack_dp(wt, val, W, n - 1));                         /* Excluding the current val wt */
    }
    return dp[n][W] = knapsack_dp(wt, val, W, n - 1);
}

int knapsack_dp_bu(vector<int> &wt, vector<int> &val, int W, int n) //O(n*W)
{
    for (int i = 0; i <= val.size(); i++) // Represent the item index only
        for (int w = 0; w <= W; w++)      // Note in the table its not the weight array its continous weights from 0 to W (max capacity)
        {
            if (i == 0 || w == 0)
            {
                dp[i][w] = 0;
                continue;
            }

            if (wt[i] <= W)
            {
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], //Including the wt
                               dp[i - 1][w]);                         //Not including the wt
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    return dp[n][W];
}
int main()
{
    vector<int> val{60, 100, 120};
    vector<int> wt{10, 20, 30};
    int W = 50;
    cout << knapsack_dp_bu(wt, val, W, val.size()) << endl;
    return 0;
}
