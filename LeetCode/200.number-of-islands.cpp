/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution
{
public:
    bool cc(vector<vector<char>> &grid, int i, int j)
    {
        int l = grid.size(), m = grid[0].size();
        if (i >= 0 && i < l && j < m && j >= 0)
            return true;
        return false;
    }
    void dfs(vector<vector<char>> &grid, vector<vector<bool>> &visited, int i, int j)
    {
        visited[i][j] = true;
        if (cc(grid, i - 1, j) && !visited[i - 1][j] && grid[i - 1][j] == '1')
            dfs(grid, visited, i - 1, j);
        if (cc(grid, i, j - 1) && !visited[i][j - 1] && grid[i][j - 1] == '1')
            dfs(grid, visited, i, j - 1);
        if (cc(grid, i + 1, j) && !visited[i + 1][j] && grid[i + 1][j] == '1')
            dfs(grid, visited, i + 1, j);
        if (cc(grid, i, j + 1) && !visited[i][j + 1] && grid[i][j + 1] == '1')
            dfs(grid, visited, i, j + 1);
    }
    int numIslands(vector<vector<char>> &grid)
    {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), 0));
        int count = 0;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[i].size(); j++)
                if (!visited[i][j] && grid[i][j] == '1')
                {
                    dfs(grid, visited, i, j);
                    count++;
                }
        return count;
    }
};
// @lc code=end
