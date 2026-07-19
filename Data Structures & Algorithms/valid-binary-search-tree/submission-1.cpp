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
    bool solve(TreeNode* root,int mx,int mn){
        if(!root) return true;
        if(root->val>=mx ||root->val<=mn) return false;
        return solve(root->left,root->val,mn) && solve(root->right,mx,root->val);
    }
    bool isValidBST(TreeNode* root) {
       
        return solve(root,INT_MAX,INT_MIN);
    }
};
