class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        vector<bool> vis(n,0);
        for(vector<int> v:flights){
            adj[v[0]].push_back({v[1],v[2]});
        }
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        pq.push({0,src,0});
        while(!pq.empty()){
            int dis=pq.top()[0];
            int i=pq.top()[1];
            int stop=pq.top()[2];
            pq.pop();
            vis[i]=true;
            if(i==dst) return dis;
            if(stop>k) continue;
            for(pair<int,int> p:adj[i]){
                if(!vis[p.first]){
                    pq.push({p.second+dis,p.first,stop+1});
                }
            }
        }
        return -1;
    }
};
