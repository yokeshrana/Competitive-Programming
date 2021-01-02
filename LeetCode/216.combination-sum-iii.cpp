/*
 * @lc app=leetcode id=216 lang=cpp
 *
 * [216] Combination Sum III
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    void generate(vector<vector<int>> &result, vector<int> &sub, int &target, int k, int curr)
    {
        int l = sub.size();
        if (target == 0 && l != 0 && l == k)
        {
            result.push_back(sub);
            return;
        }
        if (target < 0 || l > k)
            return;

        for (int i = curr; i <= 9; i++)
        {
            target -= i;
            sub.push_back(i);
            generate(result, sub, target, k, i + 1);
            sub.pop_back();
            target += i;
        }
    }
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> result;
        vector<int> sub;
        generate(result, sub, n, k, 1);
        return result;
    }
};
// @lc code=end
