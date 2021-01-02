/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    void generate(vector<vector<int>> &result, vector<int> &sub, int n, int k, int index)
    {
        if (sub.size() == k)
        {
            result.push_back(sub);
            return;
        }
        for (int i = index + 1; i <= n; i++)
        {
            sub.push_back(i);
            generate(result, sub, n, k, i);
            sub.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> result;
        vector<int> sub;
        generate(result, sub, n, k, 0);
        return result;
    }
};
// @lc code=end
