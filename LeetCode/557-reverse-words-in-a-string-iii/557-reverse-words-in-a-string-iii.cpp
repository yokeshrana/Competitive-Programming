class Solution {
public:
    string reverseWords(string s) {
        int i=0,n=s.length(),j=0;
        while(i<n){
            if(j==n||s[j]==' ')
            { 
                reverse(s.begin()+i,s.begin()+j);
                while(s[j]==' ')j++;
                i=j;
            }
            j++;
        }
        return s;
    }
};