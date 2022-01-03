/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& nums) {
        
        int carry=1;
        for(int i=nums.size()-1;i>=0;i--)
            if(nums[i]+carry>9){
                nums[i]=0;
                carry=1;
            }else
            {
                nums[i]+=carry;
                return nums;
            }
        
        nums.insert(nums.begin(),1);
        return nums;
    }
};
// @lc code=end

