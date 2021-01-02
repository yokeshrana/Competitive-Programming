/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{

public:
    bool well_formed(string s)
    {
        stack<char> st;
        int i = 0;
        while (i < s.length())
        {
            if (!st.empty() && st.top() == '(' && s[i] == ')')
                st.pop();
            else
                st.push(s[i]);
            i++;
        }
        if (st.empty())
            return true;
        else
            return false;
    }
    void generate(vector<string> &result, string &s, int i, int n)
    {
        if (i == 2 * n)
        {
            if (well_formed(s))
                result.push_back(s);
            s = "";
            return;
        }
        else
        {
            s += '(';
            generate(result, s, i + 1, n);
            s += ')';
            generate(result, s, i + 1, n);
        }
    }
    vector<string> generateParenthesis(int n)
    {
        vector<string> result;
        string s;
        generate(result, s, 0, n);
        return result;
    }
};
// @lc code=end
int main()
{
    int n = 3;
    Solution s;
    for (auto x : s.generateParenthesis(n))
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}