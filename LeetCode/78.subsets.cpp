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
   
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>  result;
        vector<int> sub;  
        for(int i=0;i<(1<<nums.size());i++) // For n number total subset is 2^n ,so we generate numbers from 0 - 2^n and according to bits include the numbers in one particular subset .
        {       
           int j=i;
           int index=0;
           while(j>0){
               if(j&1==1) //if right most bit is set
               sub.push_back(nums[index]);  
               j=j>>1;
               index++;
           }
           result.push_back(sub);
           sub.clear();
        }
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
