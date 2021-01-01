/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        set<vector<int>> result;
        multiset<int> sub;
        for (int i = 0; i < 1 << nums.size(); i++)
        {
            int n = i, index = 0;
            while (n > 0)
            {
                if (n & 1 == 1)
                    sub.insert(nums[index]);
                index++;
                n = n >> 1;
            }
            result.insert(vector(sub.begin(),sub.end()));
            sub.clear();
        }
        return vector(result.begin(),result.end());
    }
};
// @lc code=end
