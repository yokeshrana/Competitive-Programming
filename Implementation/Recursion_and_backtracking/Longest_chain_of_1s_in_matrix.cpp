#include <stdc++.h>
using namespace std;
#define n 5
int dp[n][n];
int findpath(vector<vector<int>> &mt, int i, int j)
{
    if (dp[i][j] != -1)
        return dp[i][j];
        //All Direction not needed as loop might form of 1's so excluding all direction from here 
    //int max_up = i > 0 && mt[i][j] == 1 ? 1 + findpath(mt, i - 1, j) :  0;
    int max_down = i < n - 1 && mt[i][j] == 1 ? 1 + findpath(mt, i + 1, j) : 0;
    //int max_left = j < n - 1 && mt[i][j] == 1 ? 1 + findpath(mt, i, j - 1) : 0;
    int max_right = j < n - 1 && mt[i][j] == 1 ? 1 + findpath(mt, i, j + 1) : 0;
    //int max_up_left = i > 0 && j > 0 && mt[i][j] == 1 ? 1 + findpath(mt, i - 1, j - 1) : 0;
    //int max_up_right = i > 0 && j < n - 1 && mt[i][j] == 1 ? 1 + findpath(mt, i - 1, j + 1) : 0;
    //int max_down_left = i < n - 1 && j > 0 && mt[i][j] == 1 ? 1 + findpath(mt, i + 1, j - 1) : 0;
    int max_down_right = i < n - 1 && j < n - 1 && mt[i][j] == 1 ? 1 + findpath(mt, i + 1, j + 1) : 0;
    //return max(max_up, max(max_down, max(max_left, max(max_right, max(max_up_left, max(max_up_right, max(max_down_left, max_down_right)))))));
    return max(max_down,max(max_right,max_down_right));
}
int max_len(vector<vector<int>> &mt)
{
    int result = 1;
    memset(dp, -1, sizeof dp);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if (dp[i][j] == -1) //We dont want to run for already calcucaled max path at the index
                dp[i][j] = findpath(mt, i, j);
            result = max(dp[i][j], result);
        }
    return result;
}
int main()
{
    vector<vector<int>> mt{
        {0, 1, 1, 1, 0},
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 0},
        {0, 1, 1, 0, 0},
        {1, 1, 0, 1, 0},
    };
    cout << max_len(mt) << endl;
    return 0;
}