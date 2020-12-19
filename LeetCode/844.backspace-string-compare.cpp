/*
 * @lc app=leetcode id=844 lang=cpp
 *
 * [844] Backspace String Compare
 */
using namespace std;
#include <stdc++.h>
// @lc code=start
class Solution
{
public:
    bool backspaceCompare(string S, string T)
    {
        stack<char> s, t;
        for (auto c : S)
            if (c == '#')
            {
                if (!s.empty())
                    s.pop();
            }
            else

                s.push(c);
        for (auto c : T)
            if (c == '#')
            {
                if (!t.empty())
                    t.pop();
            }
            else
                t.push(c);

        while (1)
        {
            if (t.empty() && s.empty())
                return true;
            if (t.empty() || s.empty())
                return false;
            if (s.top() != t.top())
                return false;
            s.pop();
            t.pop();
        }
        return true;
    }
};
// @lc code=end
