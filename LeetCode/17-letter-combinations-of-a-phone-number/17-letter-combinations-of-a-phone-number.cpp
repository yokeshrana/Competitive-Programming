class Solution {
public:
    map<int,string> mp={make_pair(2,"abc"),make_pair(3,"def"),make_pair(4,"ghi"),
                        make_pair(5,"jkl"),make_pair(6,"mno"),make_pair(7,"pqrs"),
                        make_pair(8,"tuv"),make_pair(9,"wxyz")};
        
    void generate(string digits,vector<string> &result,string sub,int index)
    {
       // cout<<digits[index]<<mp[digits[index]-'0']<<en;
        if(sub.length()==digits.length())
            result.push_back(sub);
        else
            for(auto j=0 ;j<mp[digits[index]-'0'].length();j++){
            generate(digits,result,sub+(mp[digits[index]-'0'][j]),index+1);
            }
    }
    vector<string> letterCombinations(string digit) {
        if(digit=="")
            return {};
      vector<string> results;
      string sub="";
      generate(digit,results,sub,0);
      return results;
    }
};