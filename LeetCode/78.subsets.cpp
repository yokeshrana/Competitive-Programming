/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    void generate(vector<int>& nums,vector<vector<int>>  &result,vector<int> &sub,int i){
        result.push_back(sub);
        for(int j=i;j<nums.size();j++){  //function work is to generate a vector with elements from i to length of array
            sub.push_back(nums[j]); //Insert a[j] in subset
            generate(nums,result,sub,j+1);
            sub.pop_back(); // backtracking remove a[i] from subset
        }
        return ;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
       vector<vector<int>>  result;
       vector<int> sub; 
        generate(nums,result,sub,0);
        return result;
    }
};
// @lc code=end
int main()
{
    Solution b;
    vector<int> v{1,2,3};
    vector<vector<int>> s=b.subsets(v);
    for(auto x:s){
        cout<<"[ ";
    for(auto y:x)
    cout<<y<<" ";
     cout<<"]";
     cout<<endl;
    }
    cout<<endl;
    return 0;
}
