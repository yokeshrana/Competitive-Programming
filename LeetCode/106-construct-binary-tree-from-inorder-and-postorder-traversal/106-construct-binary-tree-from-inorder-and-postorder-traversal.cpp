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
    map<int,int> inomap;
    int postorderindex;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        if(inorder.size()==0)
            return NULL;
        
        postorderindex=postorder.size()-1;
        
        for(int i=0;i<inorder.size();i++)
            inomap[inorder[i]]=i;
        
        return build(postorder,0,inorder.size()-1);
    }
    
    TreeNode *build(vector<int>& postorder,int start,int end){
        if(start>end)
            return NULL;
        TreeNode *node = new TreeNode();
        node->val = postorder[postorderindex--];
        node->right=build(postorder,inomap[node->val]+1 ,end);  // Note if we dont construct right subtree first then there is error
        /*
        The intuition behind it is that since postorder: LEFT → RIGHT → ROOT, so when we go in reverse order, we must construct the tree in the order of: ROOT → RIGHT → LEFT
        
        */
        
        node->left=build(postorder,start,inomap[node->val]-1);
      
        return node;
    }
};