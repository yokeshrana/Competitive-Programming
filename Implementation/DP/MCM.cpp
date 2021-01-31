#include <bits/stdc++.h>
using namespace std;
int MCM_Recursive(vector<int> &v, int i, int j)
{
    if (i >= j)
        return 0;
    int ans = INT_MAX;
    for (int k = i; k < j; k++)
    {
        ans = min(ans, MCM_Recursive(v, i, k) + MCM_Recursive(v, k + 1, j) + v[i - 1] * v[k] * v[j]);
    }
    return ans;
}
int MCM_TopDown(vector<int> &v, int i, int j)
{
    vector<vector<int>> dp(v.size() + 1, vector<int>(v.size() + 1, -1));
    if (i >= j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int ans = INT_MAX;
    for (int k = i; k < j; k++)
    {
        ans = dp[i][j] = min(ans, MCM_Recursive(v, i, k) + MCM_Recursive(v, k + 1, j) + v[i - 1] * v[k] * v[j]);
    }
    return dp[i][j];
}
int main()
{
    vector<int> v{2, 4, 5, 3, 9};
    cout << MCM_Recursive(v, 1, v.size() - 1) << endl;
    cout << MCM_TopDown(v, 1, v.size() - 1) << endl;
    return 0;
}