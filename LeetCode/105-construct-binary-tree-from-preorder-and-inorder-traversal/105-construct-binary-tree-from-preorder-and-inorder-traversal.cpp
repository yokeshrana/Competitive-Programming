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
    map<int,int> inordermap;
    int preorderIndex=0;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
     
        for(int i=0;i<inorder.size();i++){
            inordermap[inorder[i]]=i;
        }
        return build(preorder,0,preorder.size()-1);
    }
    
     TreeNode *build(vector<int> &preorder,int start,int end){
        
        if(start>end)
            return NULL;
        
        TreeNode *node=new TreeNode();
        node->val=preorder[preorderIndex++];
        node->left = build(preorder,start,inordermap[node->val]-1);
        node->right =build(preorder,inordermap[node->val]+1,end);
        return node;
    }
};