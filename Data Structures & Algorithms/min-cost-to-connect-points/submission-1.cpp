class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<vector<int>> adj(n,vector<int>(n,0));
        vector<bool> vis(n,0);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                adj[i][j]=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                adj[j][i]=adj[i][j];
            }
        }
        int ans=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});
        while(!pq.empty()){
            int d=pq.top().first;
            int i=pq.top().second;
            pq.pop();
            if(vis[i]) continue;
            ans+=d;
            vis[i]=1;
            for(int k=0;k<n;k++){
                if(vis[k]) continue;
                pq.push({adj[i][k],k});
            }
        }
        return ans;
    }
};
