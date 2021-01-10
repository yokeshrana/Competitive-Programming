/*
 * @lc app=leetcode id=344 lang=cpp
 *
 * [344] Reverse String
 */

// @lc code=start
class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        int st = 0, se = s.size() - 1;
        while (st <= se)
        {
            swap(s[st++], s[se--]);
        }
    }
};
// @lc code=end
