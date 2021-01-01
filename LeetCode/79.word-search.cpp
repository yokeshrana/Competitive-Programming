/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool findword(vector<vector<char>> &board, int i, int j, string word, int k, vector<vector<int>> &visited)
    {
       
        if (i >= board.size() || i < 0 || j < 0 ||j >= board[0].size() || board[i][j] != word[k] || visited[i][j] == 1)
            return false;
        
        if (k == word.length() - 1)
            return true;
        else
            k++;
        visited[i][j] = 1;
        if (findword(board, i, j + 1, word, k, visited))
            return true;
        if (findword(board, i + 1, j, word, k, visited))
            return true;
        if (findword(board, i - 1, j, word, k, visited))
            return true;
        if (findword(board, i, j - 1, word, k, visited))
            return true;
       visited[i][j] = 0;
        return false;
    }
      bool exist(vector<vector<char>> &board, string word)
    {
        
        int k = 0;
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[0].size(); j++)
                if (board[i][j] == word[k]){
                    vector<vector<int>> visited(board.size(), vector<int>(board[0].size(), 0));
                    if (findword(board, i, j, word, k, visited))
                        return true;
                }
        return false;
    }
};
// @lc code=end
