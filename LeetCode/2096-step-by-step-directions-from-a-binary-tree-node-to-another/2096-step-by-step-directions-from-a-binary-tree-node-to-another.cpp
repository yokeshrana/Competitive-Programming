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
    
    bool traverse(TreeNode *root,int val,string &path){
        if(!root)
            return false;
        if(root->val == val)
            return true;
        path.push_back('L');
        if(traverse(root->left,val,path))
            return true;
        path.pop_back();
        path.push_back('R');
        if(traverse(root->right,val,path))
            return true;
        path.pop_back();
        
        return false;
    }
    
    TreeNode *findlca(TreeNode *root ,int p,int q){
        
        if(!root || root->val == p || root->val ==q)
            return root;
        TreeNode *left = findlca(root->left,p,q);
        TreeNode *right= findlca(root->right,p,q);
        
        if(left && right)
            return root;
            return left?left:right;
    }
    
    string getDirections(TreeNode* root, int startValue, int destValue) {
        
        TreeNode *ancestor=findlca(root,startValue,destValue);
        
        string lca2s="",lca2d="";
        traverse(ancestor,startValue,lca2s);  //path from ancestor to startvalue
        traverse(ancestor,destValue,lca2d);    //path from ancestor to destvalue
       
        for(auto& c : lca2s) c = 'U';  //path from ancestor to startvalue is only upwards when reversed so replace by U only
       // cout<<lca2s<<endl;
       // cout<<lca2d<<endl;
        
        return lca2s+lca2d;
    }
};