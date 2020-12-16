/*
 * @lc app=leetcode id=303 lang=cpp
 *
 * [303] Range Sum Query - Immutable
 */
#include<vector>
using namespace std;
// @lc code=start
class NumArray {
private:
      vector<int> num;
public:
  
    NumArray(vector<int>& nums) {
    num=nums;
    for(int i=1;i<nums.size();i++)
        num[i]+=num[i-1];
    }
    
    int sumRange(int i, int j) {
        if(i==0)
            return num[j];
      
        return num[j]-num[i-1];
    }
};
/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
// @lc code=end

