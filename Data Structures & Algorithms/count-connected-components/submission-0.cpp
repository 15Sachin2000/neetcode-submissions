class Solution {
public:
    void solve(int i,vector<vector<int>> &adj,vector<bool> &vis){
        if(vis[i]) return;
        vis[i]=true;
        for(int j:adj[i]){
            solve(j,adj,vis);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        int ans=0;
        vector<bool> vis(n,false);
        for(vector<int> v:edges){
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                solve(i,adj,vis);
                ans++;
            }
        }
        return ans;
    }
};
