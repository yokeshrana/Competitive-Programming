/*
 * @lc app=leetcode id=684 lang=cpp
 *
 * [684] Redundant Connection
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int findParent(vector<int> &parent, int i)
    {
        if (i == parent[i])
            return parent[i];
        return parent[i] = findParent(parent, parent[i]);
    }
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        if (edges.size() == 0)
            return {};
        vector<int> parent;
        parent.resize(edges.size() + 1);
        int p1, p2;
        for (int i = 1; i <= edges.size(); i++)
            parent[i] = i;
        for (auto x : edges)
        {
            p1 = findParent(parent, x[0]);
            p2 = findParent(parent, x[1]);
            if (p1 == p2)
                return {x[0], x[1]};
            parent[p2] = p1;
        }
        return {};
    }
};
// @lc code=end
