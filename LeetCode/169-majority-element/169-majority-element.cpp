class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0;
        int mj      ;
       for(auto x:nums){
        if(count==0)
        {
            mj=x;
        }
           count+=(x == mj)? 1: -1;
       }     
        return mj;
    }
};