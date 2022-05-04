class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int lclsum=0,glbsum=INT_MIN;
        for(int i=0;i<nums.size();i++){
                 lclsum+=nums[i];
                glbsum=max(lclsum,glbsum);
              if(lclsum<=0) lclsum=0;

        }
        return glbsum;
    }
};