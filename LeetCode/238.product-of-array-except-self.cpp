/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        long long int x = 1;
        vector<int> zi;
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] == 0)
                zi.push_back(i);
            else
            {
                x *= nums[i];
            }
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                if (zi.size() >= 1)
                {
                    if (zi.size() == 1 && i == zi[0])
                        nums[i] = x;
                    else
                    {
                        nums[i] = 0;
                    }
                }else
                {
                    nums[i]=x;
                }
                
            }
            else
            {
                if (zi.size() >= 1)
                {
                    if (zi.size() == 1 && i == zi[0])
                        nums[i] = x;
                    else
                    {
                        nums[i] = 0;
                    }
                }else
                {
                    nums[i]=x/nums[i];
                }
                
            }
        }
        return nums;
    }
};
// @lc code=end
