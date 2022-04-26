class Solution {
public:
    vector<int> sumZero(int n) {
       vector<int> a(n);
        for(int i=1;i<a.size();i++){
            a[0]-=i;
            a[i]=i;
        }
        return a;
    }
};