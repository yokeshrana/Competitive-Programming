/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
 */

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
    void inorder(vector<int> &result, TreeNode *root)
    {
        if (root)
        {
            inorder(result, root->left);
            result.push_back(root->val);
            inorder(result, root->right);
        }
    }
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> result;
        inorder(result, root);
        return result;
    }
};
// @lc code=end
