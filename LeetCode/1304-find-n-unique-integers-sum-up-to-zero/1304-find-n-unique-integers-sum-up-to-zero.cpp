class Solution {
public:
    vector<int> sumZero(int n) {
       vector<int> ans(n,0);
       ans[0]=0;
       for(int i=1;i<n;i++)
       {
           ans[0]-=i;
           ans[i]=i;
       }
      return ans;
    }
};