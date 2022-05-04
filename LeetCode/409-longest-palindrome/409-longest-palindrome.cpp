class Solution {
public:
    int longestPalindrome(string s) {
        map<int,int> mp;
        int count=0;
        for(int i=0;i<s.length();i++)
            if(mp[s[i]]&&mp[s[i]]>=1)
            {
                count+=2;
                mp[s[i]]--;
            }else
                mp[s[i]]++;
    return count<s.length()?++count:count;
    }
    
};