class Solution {
public:
    int arraySign(vector<int>& nums) {
        int sign=1;
        for(auto x:nums){
            if(x>0) sign*=1;
            else
            if(x<0) sign*=-1;
            else
                return 0;
        }
        return sign;
    }
};