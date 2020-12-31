/*
 * @lc app=leetcode id=73 lang=cpp
 *
 * [73] Set Matrix Zeroes
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int r = matrix.size(), c = matrix[0].size();
        vector<int> rv, cv;
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                if (matrix[i][j] == 0)
                {
                    rv.push_back(i);
                    cv.push_back(j);
                }

        for (int p = 0; p < rv.size(); p++)
        {
            for (int k = 0; k < c; k++)
                matrix[rv[p]][k] = 0;
            for (int k = 0; k < r; k++)
                matrix[k][cv[p]] = 0;
        }
    }
};
// @lc code=end

int main()
{
    Solution s;
    vector<vector<int>> v{{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
    s.setZeroes(v);
    for (int i = 0; i < v.size(); i++)
        for (int j = 0; j < v[0].size(); j++)
        {
            cout << v[i][j] << " ";
        }
    cout << endl;

    return 0;
}