class Solution {
public:
    int minDeletions(string s) {
         map<char,int> mp;
        int count=0;   
        for(char c:s)
            mp[c]++;
        set<int> seen;
        for(auto it=mp.begin();it!=mp.end();it++){
            while(seen.find(it->second)!=seen.end())
            {
                (it->second)--;
                count++;
            }
            if(it->second>0)
            seen.insert(it->second);
        }
        return count;
    }
};