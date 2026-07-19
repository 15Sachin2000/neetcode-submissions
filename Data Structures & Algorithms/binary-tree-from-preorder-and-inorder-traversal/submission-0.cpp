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
    int findIndex(int val,vector<int> & inorder,int mn,int mx){
        for(int i=mn;i<=mx;i++){
            if(inorder[i]==val){
                return i;
            }
        }
        return -1;
    }
    TreeNode* solve(int &s,vector<int>& preorder, vector<int>& inorder,int mn,int mx){
        if(s==preorder.size()|| mn>mx){
            return NULL;
        };
        int idx=findIndex(preorder[s],inorder,mn,mx);
        if(idx==-1){
            return NULL;
        }
        TreeNode* tmp=new TreeNode(preorder[s]);
        s++;
        tmp->left=solve(s,preorder,inorder,mn,idx-1);
        tmp->right=solve(s,preorder,inorder,idx+1,mx);
        return tmp;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int s=0;
        return solve(s,preorder,inorder,0,inorder.size());
    }
};
