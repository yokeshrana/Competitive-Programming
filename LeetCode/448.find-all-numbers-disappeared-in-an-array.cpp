/*
 * @lc app=leetcode id=448 lang=cpp
 *
 * [448] Find All Numbers Disappeared in an Array
 */
#include<vector>
// @lc code=start
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> v(nums.size()+1,0),t;
        for(int i=0;i<nums.size();i++)
        {
            v[nums[i]]=1;
        }
     for(int i=1;i<=nums.size();i++)
        {
            if(v[i]!=1)
                t.push_back(i);
            
        }
     return t;  
    }
};
// @lc code=end

