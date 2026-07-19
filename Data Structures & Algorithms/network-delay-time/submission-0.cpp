class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        vector<bool> vis(n+1,false);
        for(vector<int> v:times){
            adj[v[0]].push_back({v[2],v[1]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k});
        int ans=0;
        while(!pq.empty()){
            auto p=pq.top();
            pq.pop();
            int t=p.first,node=p.second;
            if(vis[node]){
                continue;
            }
            vis[node]=true;
            ans=t;
            for(auto np:adj[node]){
                if(vis[np.second]){
                    continue;
                }
                pq.push({np.first+ans,np.second});
            }
        }
        for(int i=1;i<=n;i++){
            if(!vis[i]) return -1;
        }
        return ans;
    }
};
