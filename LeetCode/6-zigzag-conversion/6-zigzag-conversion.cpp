class Solution {
public:
    string convert(string s, int n) {
        if(n==1)
            return s;
  int row=min(n,(int)s.length());
  vector<string> ss(row,"");
  int curRow=0;
  int goingDown=0;
  for(int i=0;i<s.length();i++){
      ss[curRow]+=s[i];
      if (curRow == 0 || curRow == row - 1) goingDown = !goingDown;
        curRow += goingDown ? 1 : -1;
  }
  string ans="";
  for(string x:ss)
        ans+=x;
  return ans;
    
    }
};