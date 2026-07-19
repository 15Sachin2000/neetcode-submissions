class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(vector<int> t:times){
            adj[t[0]].push_back({t[2],t[1]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<bool> vis(n+1,0);
        for(pair<int,int> p:adj[k]){
            pq.push(p);
        }
        vis[k]=1;
        int count=1;
        while(!pq.empty()){
            pair<int,int> p=pq.top();
            pq.pop();
            if(vis[p.second]){
                continue;
            }
            vis[p.second]=1;
            count++;
            if(count==n) return p.first;
            for(pair<int,int> q:adj[p.second]){
                if(!vis[q.second]){
                    pq.push({q.first+p.first,q.second});
                }
            }
        }
        return -1;
    }
};
