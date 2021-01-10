/*
 * @lc app=leetcode id=997 lang=cpp
 *
 * [997] Find the Town Judge
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution
{
public:
    int findJudge(int N, vector<vector<int>> &trust)
    {
        //If we see the pattern here we have to find a person(ie node)
        //which is trusted by everyone (ie in degree =N-1) and he trust no one ie outdegree=0;

        vector<pair<int, int>> degree(N + 1);
        for (auto x : trust)
        {
            degree[x[0]].second++;
            degree[x[1]].first++;
        }
        for (int i = 1; i < N + 1; i++)
        {
            if (degree[i].first == N - 1 && degree[i].second == 0)
                return i;
        }
        return -1;
    }
};
// @lc code=end
