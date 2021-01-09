/*
 * @lc app=leetcode id=1346 lang=cpp
 *
 * [1346] Check If N and Its Double Exist
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool checkIfExist(vector<int> &arr)
    {
        map<int, int> mp;
        for (int i = 0; i < arr.size(); i++)
            if (arr[i] == 0 && mp[arr[i]] == 2 || mp[arr[i] * 2] || arr[i] % 2 == 0 && mp[arr[i] / 2])
                return true;
            else
                mp[arr[i]]++;
        return false;
    }
};
// @lc code=end
