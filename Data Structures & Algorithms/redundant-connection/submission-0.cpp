class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<bool> vis(edges.size()+1);
        for(vector<int> v:edges){
            if(vis[v[0]] && vis[v[1]]){
                return v;
            }
            vis[v[0]]=true;
            vis[v[1]]=true;
        }
        return {};
    }
};
