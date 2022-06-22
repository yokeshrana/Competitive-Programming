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
class Solution {
public:
    int height(TreeNode *root){
        if(root){
            return 1+max({height(root->left),height(root->right)});
        }
        else
            return 0;
    }
    
   void traverse(TreeNode* root,vector<vector<int>> &result){
        if (root){
            traverse(root->left,result);
            traverse(root->right,result);
            result[height(root)-1].push_back(root->val);
        }
            
    }
    
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> result;
        int hroot=height(root);
        while(hroot--)
        {
            result.push_back({});
        }
        traverse(root,result);
        return result;
    }
};