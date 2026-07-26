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
    pair<int,int> solve(TreeNode* root){
        if(!root) return {0,0};
        pair<int,int> p1=solve(root->left);
        int ls=p1.first,le=p1.second;
        pair<int,int> p2=solve(root->right);
        int rs=p2.first,re=p2.second;
        int s=max(le+re+root->val,ls+rs);
        return {s,ls+rs};
    }
    int rob(TreeNode* root) {
        pair<int,int> p=solve(root);
        int a=p.first,b=p.second;
        return max(a,b);
    }
};