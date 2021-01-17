/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    void generate(vector<int> &nums, vector<vector<int>> &results, vector<int> &sub, int index, int length)
    {
        if (length == sub.size())
        {
            results.push_back(sub);
            sub.clear();
            return;
        }
        for (int i = index; i < nums.size(); i++)
        {
            sub.push_back(nums[i]);
            generate(nums, results, sub, index + 1, length);
            sub.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> results;
        results.push_back({});
        vector<int> sub;
        for (int i = 1; i < nums.size(); i++)
            generate(nums, results, sub, 0, i);
        return results;
    }
};
// @lc code=end
int main()
{
    Solution b;
    vector<int> v{1, 2, 3};
    vector<vector<int>> s = b.subsets(v);
    for (auto x : s)
    {
        cout << "[ ";
        for (auto y : x)
            cout << y << " ";
        cout << "]";
        cout << endl;
    }
    cout << endl;
    return 0;
}
