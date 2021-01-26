#include <bits/stdc++.h>
using namespace std;
int lcs_recur(string x, string y, int m, int n)
{
    if (m == 0 || n == 0)
        return 0;
    if (x[m - 1] == y[n - 1])
        return 1 + lcs_recur(x, y, m - 1, n - 1);
    else
        return max(lcs_recur(x, y, m, n - 1), lcs_recur(x, y, m - 1, n));
}

int lcs_dp_td(string x, string y, int m, int n)
{
    static vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    if (m == 0 || n == 0)
        return dp[m][n] = 0;
    if (dp[m][n] != -1)
        return dp[m][n];
    if (x[m - 1] == y[n - 1])
        return dp[m][n] = 1 + lcs_recur(x, y, m - 1, n - 1);
    else
        return dp[m][n] = max(lcs_recur(x, y, m, n - 1), lcs_recur(x, y, m - 1, n));
}

int lcs_dp_bu(string x, string y, int m, int n)
{
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    for (int i = 0; i <= m; i++)
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
                continue;
            }
            if (x[i - 1] == y[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    return dp[m][n];
}

int main()
{
    string x = "xcasfrt", y = "xsrtefg";
    auto t1 = std::chrono::high_resolution_clock::now();
    cout << lcs_recur(x, y, x.length(), y.length()) << endl;
    auto t2 = std::chrono::high_resolution_clock::now();
    cout << "Time taken by function: " << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count() << " microseconds" << endl;
    cout << lcs_dp_td(x, y, x.length(), y.length()) << endl;
    auto t3 = std::chrono::high_resolution_clock::now();
    cout << "Time taken by function: " << std::chrono::duration_cast<std::chrono::microseconds>(t3 - t2).count() << " microseconds" << endl;
    cout << lcs_dp_bu(x, y, x.length(), y.length()) << endl;
    auto t4 = std::chrono::high_resolution_clock::now();
    cout << "Time taken by function: " << std::chrono::duration_cast<std::chrono::microseconds>(t4 - t3).count() << " microseconds" << endl;
    return 0;
}