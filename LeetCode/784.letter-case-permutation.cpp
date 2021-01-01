/*
 * @lc app=leetcode id=784 lang=cpp
 *
 * [784] Letter Case Permutation
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    void generate(string &s, int curr, vector<string> &result)
    {
        
        if (curr == s.length())
           result.push_back(s);
        else
            if (s[curr] >= 'a' && s[curr] <= 'z' || s[curr] >= 'A' && s[curr] <= 'Z')
        {
            s[curr] = tolower(s[curr]);
            generate(s, curr + 1, result);
            s[curr] = toupper(s[curr]);
            generate(s, curr + 1, result);
           
        }else
        {
             generate(s, curr + 1, result);
        }
        
    }

    vector<string> letterCasePermutation(string S)
    {
        vector<string> result;
        generate(S, 0, result);
        return result;
    }
};
// @lc code=end
int main()
{
    Solution s;
    vector<string> result = s.letterCasePermutation("cz4b");
    for(auto x:result)cout<<x<<" ";
    cout<<endl;
    return 0;
}