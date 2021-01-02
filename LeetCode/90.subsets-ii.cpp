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
      set<vector<int>>  result;
        vector<int> sub;  
        for(int i=0;i<(1<<nums.size());i++) // For n number total subset is 2^n ,so we generate numbers from 0 - 2^n and according to bits include the numbers in one particular subset .
        {       
           for(int j=0;j<nums.size();j++)  
           if((i&1<<j)>0) //if the corresponding bit is set ,then only push
                sub.push_back(nums[j]);  
            sort(sub.begin(),sub.end());
           result.insert(sub);
           sub.clear();
        }
        return vector(result.begin(),result.end());
    }
};
// @lc code=end
int main()
{
    Solution b;
    vector<int> v{1,2,3};
    vector<vector<int>> s=b.subsetsWithDup(v);
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
