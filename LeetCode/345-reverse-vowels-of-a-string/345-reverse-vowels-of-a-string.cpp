class Solution {
public:
    bool checkVowel(char c){
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U')
            return true;
        else
            return false;
    }
    string reverseVowels(string x) {
        int i=0,j=x.length()-1;
        while(i<j){
            while(!checkVowel(x[i])&&i<x.length())
                i++;
            while(!checkVowel(x[j])&&j>0)
                j--;
            if(i<j) {
                swap(x[i], x[j]);
                i++;
                j--;
            }
        }
        return x;
    }
};