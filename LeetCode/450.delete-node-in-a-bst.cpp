/*
 * @lc app=leetcode id=450 lang=cpp
 *
 * [450] Delete Node in a BST
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
    TreeNode *FindMin(TreeNode *root)
    {
        while (root->left)
            root = root->left;
        return root;
    }

    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (!root)
            return NULL;

        if (root->val > key)
            root->left = deleteNode(root->left, key);
        else if (root->val < key)
            root->right = deleteNode(root->right, key);
        else
        {
            if (!root->left)
                root = root->right;
            else if (!root->right)
                root = root->left;
            else
            {
                //Case of Two Node
                TreeNode *temp = FindMin(root->right);
                root->val = temp->val;
                root->right = deleteNode(root->right, root->val);
            }
        }
        return root;
    }
};
// @lc code=end
