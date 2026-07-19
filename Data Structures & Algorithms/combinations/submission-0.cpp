class Solution {
public:
    void solve(int i,int n,int k,vector<int> &tmp,vector<vector<int>> &ans){
        if(tmp.size()==k){
            ans.push_back(tmp);
            return;
        }
        if(i>n) return;
        for(int j=i;j<=n;j++){
            tmp.push_back(j);
            solve(j+1,n,k,tmp,ans);
            tmp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> tmp;
        solve(1,n,k,tmp,ans);
        return ans;
    }
};