/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    void generate(vector<vector<int>> &result, vector<int> &candidates, vector<int> &sub, int &target)
    {
        if (target < 0)
        {
            return;
        }
        if (target == 0)
        {
            result.push_back(sub);
            return;
        }
        int last_ele = -1; //Needed to make a check so that we get increasing order sub array
        if (!sub.empty())
            last_ele = sub[sub.size() - 1];
        for (auto x : candidates)
        {
            if (x > target)
                break;
            if (x < last_ele)
                continue;
            target = target - x;
            sub.push_back(x);
            generate(result, candidates, sub, target);
            sub.pop_back();
            target = target + x;
        }
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> result;
        sort(candidates.begin(), candidates.end());
        vector<int> sub;
        generate(result, candidates, sub, target);
        return result;
    }
};
// @lc code=end

// 170/170 cases passed (4 ms)
// Your runtime beats 98.01 % of cpp submissions
// Your memory usage beats 91.98 % of cpp submissions (11.1 MB)