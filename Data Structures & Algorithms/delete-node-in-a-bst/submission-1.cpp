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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;
        if(root->val==key){
            if(!root->left && !root->right){
                return NULL;
            }
            if(root->right){
                TreeNode* tmp=root->right;
                TreeNode* ptr=NULL;
                while(tmp->left){
                    ptr=tmp;
                    tmp=tmp->left;
                }
                root->val=tmp->val;
                if(ptr){
                    ptr->left=tmp->right;
                }else{
                    root->right=tmp->right;
                }
            }else{
                TreeNode* tmp=root->left;
                TreeNode* ptr=NULL;
                while(tmp->right){
                    ptr=tmp;
                    tmp=tmp->right;
                }
                root->val=tmp->val;
                if(ptr){
                    ptr->right=tmp->left;
                }else{
                    root->left=tmp->left;
                }
            }
            return root;
        }
        if(root->val>key){
            root->left=deleteNode(root->left,key);
        }else{
            root->right=deleteNode(root->right,key);
        }
        return root;
    }
};