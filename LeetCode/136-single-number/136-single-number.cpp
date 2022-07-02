class Solution {
public:
    int singleNumber(vector<int>& nums) {
    int x=1;
        for(auto c:nums)
            x^=c;
        return x^1;
    }
};