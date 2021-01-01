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
    bool findword(vector<vector<char>> &board, int i, int j, string &word, int k)
    {

        if (i >= board.size() || i < 0 || j < 0 || j >= board[0].size() || board[i][j] != word[k])
            return false;

        if (k == word.length() - 1)
            return true;
        else
            k++;
        char temp = board[i][j];
        board[i][j] = '#';
        if (findword(board, i, j + 1, word, k) ||
            findword(board, i + 1, j, word, k) ||
            findword(board, i - 1, j, word, k) ||
            findword(board, i, j - 1, word, k))
            return true;
        board[i][j] = temp;
        return false;
    }
    bool exist(vector<vector<char>> &board, string &word)
    {

        int k = 0;
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[0].size(); j++)
                if (board[i][j] == word[k])
                {

                    if (findword(board, i, j, word, k))
                        return true;
                }
        return false;
    }
};
// @lc code=end
