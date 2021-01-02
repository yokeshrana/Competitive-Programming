/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    void generate(vector<vector<int>> &results, vector<int> &candidates, vector<int> &sub, int target, int index)
    {
        if (target < 0)
            return;
        if (target == 0)
        {
            results.push_back(sub);
            return;
        }

        for (int j = index + 1; j < candidates.size(); j++)
        {
            if (j > index + 1 && candidates[j] == candidates[j - 1])
                continue;
            target = target - candidates[j];
            sub.push_back(candidates[j]);
            generate(results, candidates, sub, target, j);
            sub.pop_back();
            target = target + candidates[j];
        }
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<vector<int>> results;
        vector<int> sub;
        sort(candidates.begin(), candidates.end());
        generate(results, candidates, sub, target, -1);
        return results;
    }
};
// @lc code=end
