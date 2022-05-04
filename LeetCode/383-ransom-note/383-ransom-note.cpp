class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<int,int> mp;
        for(int i=0;i<magazine.length();i++)
                mp[magazine[i]]++;
        
        for(int i=0;i<ransomNote.length();i++)
            if(!mp[ransomNote[i]])
                return false; 
        else
            mp[ransomNote[i]]--;
            
    
        return true;
    }
};