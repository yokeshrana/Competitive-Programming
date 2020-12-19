/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */
#include "stdc++.h"
using namespace std;
// @lc code=start
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        map<int, int> mp;
        int max_in_mp = 0;
        int element;
        for (int i = 0; i < nums.size(); i++)
            {
                mp[nums[i]]++;
                if (mp[nums[i]] > max_in_mp)
                {
                    max_in_mp = mp[nums[i]];
                    element = nums[i];
                    if(max_in_mp>nums.size()/2)
                    return element;
                }
            }
        return element;
    }
};
// @lc code=end
