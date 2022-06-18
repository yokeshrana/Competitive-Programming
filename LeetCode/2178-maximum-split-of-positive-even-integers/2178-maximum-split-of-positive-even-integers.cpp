class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        if(finalSum%2==1)
            return {};
        vector<long long> l;
        long long n=2;
        while(finalSum-n>=0){
            l.push_back(n);
            finalSum-=n;
            n+=2;  
        }
        l[l.size()-1]+=finalSum;
        return l;
    }
};