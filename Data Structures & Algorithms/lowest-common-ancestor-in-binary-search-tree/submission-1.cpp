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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val>q->val) return lowestCommonAncestor(root,q,p);
        if(!root) return root;
        int val1=p->val;
        int val2=q->val;
        int rootVal=root->val;
        if(rootVal>=val1  && rootVal<=val2){
            return root;
        }
        if(val1>rootVal){
            return lowestCommonAncestor(root->right,p,q);
        }
        return lowestCommonAncestor(root->left,p,q);
    }
};
