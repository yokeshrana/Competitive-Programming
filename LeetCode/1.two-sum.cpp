/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */
#include "../stdc++.h"
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int i, j;
        vector<int> temp;
        for (i = 0; i < nums.size(); i++)
            for (j = i; j < nums.size(); j++)
                if (i != j && target - nums[i] == nums[j])
                {
                    temp.push_back(i);
                    temp.push_back(j);
                    break;
                }

        return temp;
    }
};
// @lc code=end
