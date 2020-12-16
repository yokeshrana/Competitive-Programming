/*
 * @lc app=leetcode id=704 lang=cpp
 *
 * [704] Binary Search
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
   int search(vector<int>& nums, int target) {
        return bin_search(nums,0,nums.size()-1,target);
    }
    int bin_search(vector<int>& nums,int low,int high,int target){
        int mid=(low+high)/2;
        if(low>high)
            return -1;
        if(target==nums[mid]) return mid;
        if(target<nums[mid]){
            return bin_search(nums,low,mid-1,target);
        }else
        {
            return bin_search(nums,mid+1,high,target);
        }
    }
};
// @lc code=end

