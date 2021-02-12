/*
 * @lc app=leetcode id=257 lang=cpp
 *
 * [257] Binary Tree Paths
 */
#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// @lc code=start

class Solution
{
public:
    void traverse(TreeNode *root, vector<string> &result, string path)
    {
        if (!root->left && !root->right)
        {
            result.push_back(path);
        }
        else
        {
            if (root->left)
                traverse(root->left, result, path + "->" + to_string(root->left->val)); //Same like backtracking if we have written path+"->"+to_string(root->left->val) outisde the recursive call we need to call push before recursive call and pop after recursive call.
            if (root->right)
                traverse(root->right, result, path + "->" + to_string(root->right->val));
        }
    }
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> result;
        if (!root)
            return {};
        string path = "";
        traverse(root, result, to_string(root->val));
        return result;
    }
};
// @lc code=end
