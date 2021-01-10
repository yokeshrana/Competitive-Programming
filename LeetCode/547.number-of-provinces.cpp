/*
 * @lc app=leetcode id=547 lang=cpp
 *
 * [547] Number of Provinces
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    void dfs(vector<vector<int>> &isConnected, vector<bool> &visited, int i)
    {
        stack<int> st;
        st.push(i);
        visited[i] = true;
        while (!st.empty())
        {
            int x = st.top();
            st.pop();
            for (int k = 0; k < visited.size(); k++)
            {
                if (!visited[k] && isConnected[x][k])
                {
                    st.push(k);
                    visited[k] = true;
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        //Prepare a visited array and call dfs until all nodes are visited
        vector<bool> visited(isConnected.size(), false);
        int pr_count = 0;
        for (int i = 0; i < visited.size(); i++)
        {
            if (!visited[i])
            {
                dfs(isConnected, visited, i);
                pr_count++;
            }
        }
        return pr_count;
    }
};
// @lc code=end
