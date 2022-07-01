class Solution {
public:
    vector<int> countBits(int n) {
        // For even the set bits in n is == set bits in n/2
        //For odd the set bits in n is === 1 + set bits in n/2
        vector<int> res;
        for(int i=0;i<=n;i++){
            res.push_back(solve(i));
        }
        return res;
    }
    
    int solve(int n){
        if(n<=1) return n;
        if(n%2==0) return solve(n/2);
        else
        return 1+solve((n/2));
    }
};