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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> stk;
        int ans=root->val;
        TreeNode* tmp=root;
        while(tmp){
            stk.push(tmp);
            tmp=tmp->left;
        }
        while(!stk.empty() && k!=0){
            TreeNode* ptr=stk.top();
            k--;
            ans=ptr->val;
            stk.pop();
            ptr=ptr->right;
            while(ptr){
                stk.push(ptr);
                ptr=ptr->left;
            }
        }
        return ans;
    }
};
