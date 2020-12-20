/*
 * @lc app=leetcode id=226 lang=cpp
 *
 * [226] Invert Binary Tree
 */
#include <stdc++.h>
using namespace std;
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    void invertTrees(TreeNode *root)
    {

        TreeNode *curr = root;
        if (!curr || (!curr->left && !curr->right))
            return;

        TreeNode *left = curr->left;
        TreeNode *right = curr->right;
        invertTrees(left);
        invertTrees(right);
        swap(left, right);
        curr->left = left;
        curr->right = right;
    }
    TreeNode *invertTree(TreeNode *root)
    {
        invertTrees(root);
        return root;
    }
};
// @lc code=end
