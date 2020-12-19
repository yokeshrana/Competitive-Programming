/*
 * @lc app=leetcode id=720 lang=cpp
 *
 * [720] Longest Word in Dictionary
 */
#include "stdc++.h"
using namespace std;
// @lc code=start
class Solution
{

public:
    string longestWord(vector<string> &words)
    {
        set<string> s(words.begin(), words.end());
        string res = "";
        for (auto st : words)
        {
            //possible if can be buiult one charcter at time from already dictionary words
            bool possible = true;
            for (int i = 1; i <= st.length(); i++)
            {
                if (s.find(st.substr(0, i)) == s.end())
                {
                    possible = false;
                    break;
                }
            }
            if (possible && st.length() > res.length())
            {
                res = st;
            }
            else if (possible && st.length() == res.length())
            {
                res = st < res ? st : res;
            }
        }
        return res;
    }
};
// @lc code=end
