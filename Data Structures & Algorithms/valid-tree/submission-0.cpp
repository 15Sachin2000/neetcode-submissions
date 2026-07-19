class Solution {
public:
    bool dfs(int i,int p,vector<vector<int>> &adj,vector<bool> &vis){
        if(vis[i]) return false;
        vis[i]=true;
        for(int j:adj[i]){
            if(j!=p){
                if(!dfs(j,i,adj,vis)){
                    return false;
                }
            }
        }
        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(vector<int> v:edges){
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        vector<bool> vis(n,false);
        bool check=dfs(0,-1,adj,vis);
        if(!check) return false;
        for(bool node:vis){
            if(!node) return false;
        }
        return true;
    }
};
